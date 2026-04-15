#include "reveil.h"
#include "hardware_emulator.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <string>
#include <cstdio>
#include <chrono>
#include <ctime>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

class EmulatorApplication
{
public:
    EmulatorApplication() : window(nullptr), last_second_time(0.0), 
                           clear_color(0.45f, 0.55f, 0.60f, 1.00f) {}
    
    ~EmulatorApplication()
    {
        cleanup();
    }
    
    bool initialize()
    {
        if (!initialize_glfw())
            return false;
        
        if (!create_window())
            return false;
        
        initialize_imgui();
        return true;
    }
    
    void run()
    {
        last_second_time = glfwGetTime();
        
        // Send initial timer event with current real time
        auto initial_time = get_current_time_point();
        hardware.update_time(initial_time);
        
        rr::hw::TimerEvent initial_event{initial_time};
        auto flags = reveil.compute_update(hardware, hardware, initial_event);
        hardware.process_output_flags(flags);
        
        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
            
            update_simulation();
            update_background_color();
            
            render_frame();
        }
    }

private:
    bool initialize_glfw()
    {
        glfwSetErrorCallback(glfw_error_callback);
        if (!glfwInit())
            return false;
        
        // GL 3.3 + GLSL 330
        glsl_version = "#version 330";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        return true;
    }
    
    // Convert current system time to Clock::time_point
    rr::hw::Clock::time_point get_current_time_point()
    {
        // Get current system time
        auto now = std::chrono::system_clock::now();
        auto unix_time = std::chrono::system_clock::to_time_t(now);
        
        // Convert Unix time (seconds since 1970-01-01) to Clock time (seconds since 2001-01-01)
        // Days from 1970-01-01 to 2001-01-01 = 31 years
        // Account for leap years: 1972, 1976, 1980, 1984, 1988, 1992, 1996, 2000 = 8 leap days
        // Total days = 31*365 + 8 = 11323 days
        constexpr int64_t seconds_1970_to_2001 = 11323LL * 24 * 3600;
        
        int64_t seconds_since_2001 = unix_time - seconds_1970_to_2001;
        
        return rr::hw::Clock::time_point(
            rr::hw::Clock::duration(static_cast<rr::hw::Clock::rep>(seconds_since_2001))
        );
    }
    
    bool create_window()
    {
        window = glfwCreateWindow(1280, 720, "Reveil Emulator", nullptr, nullptr);
        if (window == nullptr)
            return false;
        
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); // Enable vsync
        
        return true;
    }
    
    void initialize_imgui()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        
        ImGui::StyleColorsDark();
        
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);
    }
    
    void update_simulation()
    {
        double current_time = glfwGetTime();
        
        if (current_time - last_second_time >= 0.1)
        {
            last_second_time = current_time;
            handle_time_tick();
            
            // Check if we need to send a timer-scheduled clock event
            auto time_point = get_current_time_point();
            auto next_alarm = hardware.get_next_alarm();
            if (next_alarm.has_value() && time_point >= next_alarm.value())
            {
                rr::hw::TimerEvent timer_event{time_point};
                auto flags = reveil.compute_update(hardware, hardware, timer_event);
                hardware.process_output_flags(flags);
            }
        }
    }
    
    void handle_time_tick()
    {
        auto time_point = get_current_time_point();
        hardware.update_time(time_point);
        
        // Send tick event if awake
        if (hardware.is_awake())
        {
            rr::hw::TickEvent tick_event{hardware.get_tick_counter()};
            auto flags = reveil.compute_update(hardware, hardware, tick_event);
            hardware.process_output_flags(flags);
            hardware.handle_tick();
        }
    }
    
    void update_background_color()
    {
        if (hardware.is_backlight_on())
        {
            clear_color = ImVec4(0.8f, 0.9f, 1.0f, 1.00f); // Bright blue-white
        }
        else
        {
            clear_color = ImVec4(0.2f, 0.2f, 0.3f, 1.00f); // Dark
        }
    }
    
    void render_frame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        render_ui();
        
        ImGui::Render();
        render_opengl();
        
        glfwSwapBuffers(window);
    }
    
    void render_ui()
    {
        ImGui::Begin("Reveil Republicain Emulator", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
        
        ImGui::Text("Republican Alarm Clock Emulator");
        ImGui::Separator();
        
        render_status_section();
        render_time_section();
        render_alarm_section();
        
        ImGui::Separator();
        render_encoder_controls();
        
        ImGui::Separator();
        render_display();
        
        ImGui::Separator();
        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
        
        ImGui::End();
    }
    
    void render_status_section()
    {
        ImGui::Text("Status: %s", hardware.is_awake() ? "AWAKE" : "SLEEPING");
        ImGui::SameLine();
        if (hardware.is_beeping())
        {
            ImGui::TextColored(ImVec4(1.0f, 0.5f, 0.0f, 1.0f), " 🔊 BEEPING");
        }
    }
    
    void render_time_section()
    {
        auto current_time = hardware.get_current_time();
        auto seconds = current_time.time_since_epoch().count();
        int hours = (seconds / 3600) % 24;
        int minutes = (seconds / 60) % 60;
        int secs = seconds % 60;
        ImGui::Text("Current Time: %02d:%02d:%02d", hours, minutes, secs);
    }
    
    void render_alarm_section()
    {
        auto countdown = hardware.get_countdown_seconds();
        if (countdown.has_value())
        {
            int64_t count_secs = countdown.value();
            if (count_secs >= 0)
            {
                int64_t count_hours = count_secs / 3600;
                int64_t count_mins = (count_secs / 60) % 60;
                int64_t count_s = count_secs % 60;
                ImGui::Text("Alarm in: %02ld:%02ld:%02ld", 
                           static_cast<long>(count_hours), 
                           static_cast<long>(count_mins), 
                           static_cast<long>(count_s));
            }
            else
            {
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Alarm TRIGGERED!");
            }
        }
        else
        {
            ImGui::Text("Alarm: Not set");
        }
    }
    
    void render_encoder_controls()
    {
        ImGui::Text("Encoder Controls:");
        
        if (ImGui::Button("➖ Minus"))
        {
            send_encoder_event(-1, false);
        }
        ImGui::SameLine();
        
        if (ImGui::Button("⏺ Press"))
        {
            send_encoder_event(0, true);
        }
        ImGui::SameLine();
        
        if (ImGui::Button("➕ Plus"))
        {
            send_encoder_event(1, false);
        }
    }
    
    void send_encoder_event(int delta, bool pressed)
    {
        rr::hw::EncoderEvent event{delta, pressed};
        auto flags = reveil.compute_update(hardware, hardware, event);
        hardware.process_output_flags(flags);
    }
    
    void render_display()
    {
        ImGui::Text("Display (200x200):");
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        ImVec2 canvas_pos = ImGui::GetCursorScreenPos();
        const float pixel_size = 2.0f;
        const float display_width = decltype(hardware)::DISPLAY_WIDTH * pixel_size;
        const float display_height = decltype(hardware)::DISPLAY_HEIGHT * pixel_size;
        
        draw_display_background(draw_list, canvas_pos, display_width, display_height);
        draw_display_pixels(draw_list, canvas_pos, pixel_size);
        
        // Reserve space for the display
        ImGui::Dummy(ImVec2(display_width, display_height));
    }
    
    void draw_display_background(ImDrawList* draw_list, const ImVec2& canvas_pos, 
                                  float width, float height)
    {
        draw_list->AddRectFilled(
            canvas_pos,
            ImVec2(canvas_pos.x + width, canvas_pos.y + height),
            IM_COL32(0, 0, 0, 255)
        );
    }
    
    void draw_display_pixels(ImDrawList* draw_list, const ImVec2& canvas_pos, float pixel_size)
    {
        for (int y = 0; y < decltype(hardware)::DISPLAY_HEIGHT; ++y)
        {
            for (int x = 0; x < decltype(hardware)::DISPLAY_WIDTH; ++x)
            {
                draw_single_pixel(draw_list, canvas_pos, x, y, pixel_size);
            }
        }
    }
    
    void draw_single_pixel(ImDrawList* draw_list, const ImVec2& canvas_pos, 
                          int x, int y, float pixel_size)
    {
        auto pixel = hardware.get_pixel(x, y);
        float r, g, b;
        hardware.get_pixel_color(pixel, r, g, b);
        
        ImU32 color = IM_COL32(
            static_cast<int>(r * 255),
            static_cast<int>(g * 255),
            static_cast<int>(b * 255),
            255
        );
        
        ImVec2 p_min(
            canvas_pos.x + x * pixel_size,
            canvas_pos.y + y * pixel_size
        );
        ImVec2 p_max(
            p_min.x + pixel_size,
            p_min.y + pixel_size
        );
        
        draw_list->AddRectFilled(p_min, p_max, color);
    }
    
    void render_opengl()
    {
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, 
                     clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    void cleanup()
    {
        if (ImGui::GetCurrentContext())
        {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
        }
        
        if (window)
        {
            glfwDestroyWindow(window);
            window = nullptr;
        }
        
        glfwTerminate();
    }

private:
    GLFWwindow* window;
    const char* glsl_version;
    double last_second_time;
    ImVec4 clear_color;
    
    // Use debug-enabled version of ReveilRepublicain
    using ReveilType = rr::ReveilRepublicain<true>;
    ReveilType reveil;
    emulator::HardwareEmulator<ReveilType> hardware{reveil};
};

int main(int, char**)
{
    EmulatorApplication app;
    
    if (!app.initialize())
        return 1;
    
    app.run();
    
    return 0;
}
