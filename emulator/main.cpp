#include "reveil.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <string>
#include <cstdio>

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

    // Create our calculator instance
    reveil::Calculator calc;
    
    // Application state
    int num1 = 0;
    int num2 = 0;
    int result = 0;
    char name_buffer[128] = "World";
    std::string greeting_text = "";
    
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Main window
        {
            ImGui::Begin("Reveil Emulator");
            
            ImGui::Text("Welcome to the Reveil Library Emulator!");
            ImGui::Separator();
            
            // Calculator section
            ImGui::Text("Calculator");
            ImGui::InputInt("Number 1", &num1);
            ImGui::InputInt("Number 2", &num2);
            
            if (ImGui::Button("Add")) {
                result = calc.add(num1, num2);
            }
            ImGui::SameLine();
            if (ImGui::Button("Subtract")) {
                result = calc.subtract(num1, num2);
            }
            ImGui::SameLine();
            if (ImGui::Button("Multiply")) {
                result = calc.multiply(num1, num2);
            }
            
            ImGui::Text("Result: %d", result);
            
            ImGui::Separator();
            
            // Greeting section
            ImGui::Text("Greeting Generator");
            ImGui::InputText("Name", name_buffer, IM_ARRAYSIZE(name_buffer));
            
            if (ImGui::Button("Generate Greeting")) {
                greeting_text = reveil::greet(std::string(name_buffer));
            }
            
            if (!greeting_text.empty()) {
                ImGui::TextWrapped("%s", greeting_text.c_str());
            }
            
            ImGui::Separator();
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 
                       1000.0f / io.Framerate, io.Framerate);
            
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
