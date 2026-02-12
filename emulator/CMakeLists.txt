# Create ImGui library
add_library(imgui_lib STATIC
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui_lib
    PUBLIC
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
)

target_link_libraries(imgui_lib
    PUBLIC
        glfw
)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Create emulator executable
add_executable(emulator
    main.cpp
)

target_link_libraries(emulator
    PRIVATE
        reveil
        imgui_lib
        glfw
        OpenGL::GL
        ${CMAKE_DL_LIBS}
)

target_include_directories(emulator
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
)
