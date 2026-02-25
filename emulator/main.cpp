#include "reveil.h"
#include "hardware_emulator.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <string>
#include <cstdio>
#include <chrono>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char**)
{
    // Setup GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // GL 3.3 + GLSL 330
    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Reveil Emulator", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Create Reveil and hardware emulator
    rr::ReveilRepublicain reveil;
    emulator::HardwareEmulator hardware(reveil);
    
    // Application state
    double last_second_time = glfwGetTime();
    
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Handle time updates and ticks
        double current_time = glfwGetTime();
        
        // Update simulated time (each real second = 1 simulated second)
        if (current_time - last_second_time >= 1.0)
        {
            last_second_time = current_time;
            auto time_point = rr::hw::Clock::time_point(
                rr::hw::Clock::duration(static_cast<rr::hw::Clock::rep>(current_time))
            );
            hardware.update_time(time_point);
            
            // Send tick event if awake
            if (hardware.is_awake())
            {
                hardware.handle_tick();
            }
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Update background color based on backlight
        if (hardware.is_backlight_on())
        {
            clear_color = ImVec4(0.8f, 0.9f, 1.0f, 1.00f); // Bright blue-white
        }
        else
        {
            clear_color = ImVec4(0.2f, 0.2f, 0.3f, 1.00f); // Dark
        }

        // Main window
        {
            ImGui::Begin("Reveil Republicain Emulator", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
            
            ImGui::Text("Republican Alarm Clock Emulator");
            ImGui::Separator();
            
            // Status display
            ImGui::Text("Status: %s", hardware.is_awake() ? "AWAKE" : "SLEEPING");
            ImGui::SameLine();
            if (hardware.is_beeping())
            {
                ImGui::TextColored(ImVec4(1.0f, 0.5f, 0.0f, 1.0f), " 🔊 BEEPING");
            }
            
            // Time display
            auto current_time = hardware.get_current_time();
            auto seconds = current_time.time_since_epoch().count();
            int hours = (seconds / 3600) % 24;
            int minutes = (seconds / 60) % 60;
            int secs = seconds % 60;
            ImGui::Text("Current Time: %02d:%02d:%02d", hours, minutes, secs);
            
            // Alarm countdown
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
            
            ImGui::Separator();
            
            // Encoder controls
            ImGui::Text("Encoder Controls:");
            if (ImGui::Button("➖ Minus"))
            {
                hardware.handle_encoder_minus();
            }
            ImGui::SameLine();
            if (ImGui::Button("⏺ Press"))
            {
                hardware.handle_encoder_press();
            }
            ImGui::SameLine();
            if (ImGui::Button("➕ Plus"))
            {
                hardware.handle_encoder_plus();
            }
            
            ImGui::Separator();
            
            // Display rendering (200x200 grid)
            ImGui::Text("Display (200x200):");
            ImDrawList* draw_list = ImGui::GetWindowDrawList();
            ImVec2 canvas_pos = ImGui::GetCursorScreenPos();
            const float pixel_size = 2.0f; // Each pixel is 2x2 screen pixels
            const float display_width = emulator::HardwareEmulator::DISPLAY_WIDTH * pixel_size;
            const float display_height = emulator::HardwareEmulator::DISPLAY_HEIGHT * pixel_size;
            
            // Draw display background
            draw_list->AddRectFilled(
                canvas_pos,
                ImVec2(canvas_pos.x + display_width, canvas_pos.y + display_height),
                IM_COL32(0, 0, 0, 255)
            );
            
            // Draw pixels
            for (int y = 0; y < emulator::HardwareEmulator::DISPLAY_HEIGHT; ++y)
            {
                for (int x = 0; x < emulator::HardwareEmulator::DISPLAY_WIDTH; ++x)
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
            }
            
            // Reserve space for the display
            ImGui::Dummy(ImVec2(display_width, display_height));
            
            ImGui::Separator();
            ImGui::Text("FPS: %.1f", io.Framerate);
            
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, 
                     clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
