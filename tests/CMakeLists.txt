# Create test executable
add_executable(reveil_tests
    reveil_test.cpp
    renderer_test.cpp
    time_test.cpp
    bit_packer_test.cpp
    char_pixel_extractor_test.cpp
    text_layout_calculator_test.cpp
    string_iterator_test.cpp
)

# Link against gtest, gtest_main, and the reveil library
target_link_libraries(reveil_tests
    PRIVATE
        reveil
        gtest
        gtest_main
)

# Include directories
target_include_directories(reveil_tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

# Discover tests for CTest
include(GoogleTest)
gtest_discover_tests(reveil_tests)
