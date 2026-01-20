# Create the reveil library
add_library(reveil
    reveil.cpp
)

target_include_directories(reveil
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Optional: set library properties
set_target_properties(reveil PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)
