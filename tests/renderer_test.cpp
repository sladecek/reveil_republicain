#include "renderer.h"
#include "generated/concrete_fonts.h"
#include "text_layout_calculator.h"

#include <gtest/gtest.h>
#include <vector>
#include <cstdint>

namespace rr::ui::test
{

    using namespace rr::ui;

    // Mock display for testing
    class MockDisplay
    {
    public:
        static constexpr int PIXELS_PER_BYTE = 4; // 2 bits per pixel
        
        struct Pixel
        {
            hw::x_t x{};
            hw::y_t y{};
            hw::color_t value{};
        };

        void start_window(const hw::window_t &w)
        {
            current_window = w;
            window_pixel_index = 0;
        }

        void send_pixels(hw::pixels_t pixel)
        {
            // Each byte contains 4 pixels (2 bits each)
            for (int i = 0; i < PIXELS_PER_BYTE; ++i)
            {
                if (window_pixel_index >= current_window.width * current_window.height)
                    break;

                int local_x = window_pixel_index % current_window.width;
                int local_y = window_pixel_index / current_window.width;
                int global_x = current_window.x + local_x;
                int global_y = current_window.y + local_y;

                // Extract 2 bits for this pixel (from MSB to LSB)
                int shift = 6 - (i * 2);
                hw::color_t pixel_value = (pixel >> shift) & 0x03;
                
                pixels.push_back({static_cast<hw::x_t>(global_x), 
                                  static_cast<hw::y_t>(global_y), 
                                  pixel_value});
                window_pixel_index++;
            }
        }

        void finish_window()
        {
            // Nothing to do
        }

        void update()
        {
            // Nothing to do
        }

        const std::vector<Pixel> &get_pixels() const { return pixels; }
        void clear() { pixels.clear(); }

    private:
        hw::window_t current_window{};
        int window_pixel_index{};
        std::vector<Pixel> pixels;
    };

    TEST(RendererTest, CreateRenderer)
    {
        MockDisplay display;
        NormalFont font;
        hw::window_t window{0, 0, 200, 24};

        Renderer<hw::BitsPerPixel::b2, MockDisplay, NormalFont> renderer(display, window, font);

        // Test passes if it compiles and constructs
        SUCCEED();
    }

    TEST(RendererTest, FillSmallWindow)
    {
        MockDisplay display;
        NormalFont font;
        hw::window_t window{10, 20, 8, 4}; // 8x4 = 32 pixels

        Renderer<hw::BitsPerPixel::b2, MockDisplay, NormalFont> renderer(display, window, font);

        // Fill with color 2 (2-bit color value)
        renderer.fill(2);

        // Should have 32 pixels (8x4)
        const auto &pixels = display.get_pixels();
        EXPECT_EQ(pixels.size(), 32);

        // All pixels should have color 2
        for (const auto &pixel : pixels)
        {
            EXPECT_EQ(pixel.value, 2);
        }
        
        // Check first pixel position
        EXPECT_EQ(pixels[0].x, 10);
        EXPECT_EQ(pixels[0].y, 20);
        
        // Check last pixel position
        EXPECT_EQ(pixels[31].x, 17); // 10 + 7
        EXPECT_EQ(pixels[31].y, 23); // 20 + 3
    }

    TEST(RendererTest, FillWithDifferentColors)
    {
        MockDisplay display;
        NormalFont font;
        hw::window_t window{0, 0, 4, 2}; // 4x2 = 8 pixels

        Renderer<hw::BitsPerPixel::b2, MockDisplay, NormalFont> renderer(display, window, font);

        // Test color 0 (black)
        display.clear();
        renderer.fill(0);
        const auto &pixels0 = display.get_pixels();
        EXPECT_EQ(pixels0.size(), 8); // 8 pixels
        for (const auto &p : pixels0)
        {
            EXPECT_EQ(p.value, 0);
        }

        // Test color 1
        display.clear();
        renderer.fill(1);
        const auto &pixels1 = display.get_pixels();
        EXPECT_EQ(pixels1.size(), 8);
        for (const auto &p : pixels1)
        {
            EXPECT_EQ(p.value, 1);
        }

        // Test color 3
        display.clear();
        renderer.fill(3);
        const auto &pixels3 = display.get_pixels();
        EXPECT_EQ(pixels3.size(), 8);
        for (const auto &p : pixels3)
        {
            EXPECT_EQ(p.value, 3);
        }
    }

    TEST(RendererTest, RenderHello)
    {
        MockDisplay display;
        NormalFont font;
        hw::window_t window{0, 0, 200, 24};

        Renderer<hw::BitsPerPixel::b2, MockDisplay, NormalFont> renderer(display, window, font);

        // Create "hello" string
        // Note: This is a simplified test - actual character mapping would need to be implemented
        String hello_str = {0, 0, 0, 0}; // Placeholder

        renderer.draw(hello_str, 0, 3, Align::left); // bg=0 (black), fg=3 (white/max)

        // For now, just verify it doesn't crash
        // In a complete implementation, we would verify the pixel output
        SUCCEED();
    }

    TEST(RendererTest, MeasureEmptyStringWidth)
    {
        MockDisplay display;
        NormalFont font;
        hw::window_t window{0, 0, 200, 24};

        Renderer<hw::BitsPerPixel::b2, MockDisplay, NormalFont> renderer(display, window, font);

        // Create empty string (all NULL_CHAR)
        String empty_str = {NULL_CHAR, NULL_CHAR, NULL_CHAR, NULL_CHAR};

        hw::x_t width = renderer.measure_string_width(empty_str);

        // Empty string should have width 0
        EXPECT_EQ(width, 0);
    }

    TEST(RendererTest, MeasureString123Width)
    {
        MockDisplay display;
        NormalFont font;
        hw::window_t window{0, 0, 200, 24};

        Renderer<hw::BitsPerPixel::b2, MockDisplay, NormalFont> renderer(display, window, font);

        // Create string "123" using digit fragments
        // nr fragment starts at index 0, so digit 1 = fragment 1, digit 2 = fragment 2, digit 3 = fragment 3
        String str_123 = {
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            static_cast<uint16_t>(fragment_index::nr) + 2,  // "2"
            static_cast<uint16_t>(fragment_index::nr) + 3,  // "3"
            NULL_CHAR
        };

        hw::x_t width = renderer.measure_string_width(str_123);

        // Width should be sum of individual character widths from the font
        // Fragment 1 contains char 4 (width 6), fragment 2 contains char 5 (width 8), fragment 3 contains char 6 (width 8)
        hw::x_t expected_width = 6 + 8 + 8;  // = 22
        
        EXPECT_EQ(width, expected_width);
        EXPECT_GT(width, 0);  // Should be non-zero
    }

    TEST(RendererTest, DrawDigit0)
    {
        MockDisplay display;
        NormalFont font;
        
        // Digit "0" is 8 pixels wide and font height is 24 pixels
        hw::window_t window{0, 0, 8, 24};
        
        Renderer<hw::BitsPerPixel::b2, MockDisplay, NormalFont> renderer(display, window, font);
        
        // Create string with just digit "0" (fragment index 0)
        String str_0 = {
            static_cast<uint16_t>(fragment_index::nr) + 0,  // "0"
            NULL_CHAR,
            NULL_CHAR,
            NULL_CHAR
        };
        
        display.clear();
        renderer.draw(str_0, 0, 3, Align::left);
        
        const auto &pixels = display.get_pixels();
        
        // Should have exactly 8x24 = 192 pixels
        EXPECT_EQ(pixels.size(), 192);
        
        // Verify all pixels are within the window bounds
        for (const auto &pixel : pixels)
        {
            EXPECT_LT(pixel.x, 8);
            EXPECT_LT(pixel.y, 24);
        }
        
        
        // Check a few specific pixels to validate the digit shape
        // Digit '0' should have foreground pixels forming an oval shape
        // Top-left corner should be background
        EXPECT_EQ(pixels[0].value, 0) << "Top-left corner should be background";
        
        // Top-right corner should be background
        EXPECT_EQ(pixels[7].value, 0) << "Top-right corner should be background";
        
        // Bottom-left corner should be background (pixel at y=23, x=0)
        auto bottom_left = std::find_if(pixels.begin(), pixels.end(), 
            [](const MockDisplay::Pixel& p) { return p.x == 0 && p.y == 23; });
        ASSERT_NE(bottom_left, pixels.end());
        EXPECT_EQ(bottom_left->value, 0) << "Bottom-left corner should be background";
        
        // Bottom-right corner should be background (pixel at y=23, x=7)
        auto bottom_right = std::find_if(pixels.begin(), pixels.end(), 
            [](const MockDisplay::Pixel& p) { return p.x == 7 && p.y == 23; });
        ASSERT_NE(bottom_right, pixels.end());
        EXPECT_EQ(bottom_right->value, 0) << "Bottom-right corner should be background";
        
        // Print pixels for visual inspection
        std::cout << "\nDigit '0' bitmap (8x24 pixels):\n";
        std::cout << "Legend: . = background (0), # = foreground (3)\n\n";
        
        for (int y = 0; y < 24; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                auto pixel = std::find_if(pixels.begin(), pixels.end(),
                    [x, y](const MockDisplay::Pixel& p) { return p.x == x && p.y == y; });
                
                if (pixel != pixels.end())
                {
                    std::cout << (pixel->value == 3 ? '#' : '.');
                }
                else
                {
                    std::cout << '?';  // Should never happen
                }
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
    }

    TEST(RendererTest, DrawDateLine)
    {
        MockDisplay display;
        NormalFont font;
        
        // Window size matches paint_line1: 200 pixels wide, normal font height
        hw::window_t window{0, 0, 200, normal_font_height};
        
        Renderer<hw::BitsPerPixel::b2, MockDisplay, NormalFont> renderer(display, window, font);
        
        // Create string "11 Vendémiaire" (day 11 of first month)
        // Format: digit 1, digit 1, space, month_fragment
        String date_str = {
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            static_cast<uint16_t>(fragment_index::space),   // " "
            static_cast<uint16_t>(fragment_index::months),  // "Vendémiaire"
        };
        
        display.clear();
        renderer.draw(date_str, 0, 3, Align::left);  // bg=0 (black), fg=3 (white)
        
        const auto &pixels = display.get_pixels();
        
        // Should have exactly 200 * 24 = 4800 pixels
        EXPECT_EQ(pixels.size(), 200 * 24);
        
        // Verify all pixels are within the window bounds
        for (const auto &pixel : pixels)
        {
            EXPECT_LT(pixel.x, 200);
            EXPECT_LT(pixel.y, 24);
        }
        
        // Print the first digit "1" for visual inspection (first 6 pixels wide)
        std::cout << "\nFirst digit '1' from date line (6x24 pixels):\n";
        std::cout << "Expected from drawing_objects.cpp comments:\n";
        std::cout << "       (7 blank lines)\n";
        std::cout << "   ##  \n";
        std::cout << "  ###  \n";
        std::cout << " ####  \n";
        std::cout << "## ##  \n";
        std::cout << "   ##  (9 lines of '   ## ')\n";
        std::cout << "       (4 blank lines)\n";
        std::cout << "\nActual rendering (verifying consistency):\n";
        
        for (int y = 0; y < 24; ++y)
        {
            for (int x = 0; x < 6; ++x)
            {
                auto pixel = std::find_if(pixels.begin(), pixels.end(),
                    [x, y](const MockDisplay::Pixel& p) { return p.x == x && p.y == y; });
                
                if (pixel != pixels.end())
                {
                    std::cout << (pixel->value == 3 ? '#' : '.');
                }
                else
                {
                    std::cout << '?';
                }
            }
            std::cout << '\n';
        }
        
        // Verify the shape matches the ASCII art comments in drawing_objects.cpp
        // Line 7: '   ## ' = "...##."
        auto line7_x3 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 3 && p.y == 7; });
        ASSERT_NE(line7_x3, pixels.end());
        EXPECT_EQ(line7_x3->value, 3) << "Line 7, x=3 should be foreground (#)";
        
        auto line7_x4 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 4 && p.y == 7; });
        ASSERT_NE(line7_x4, pixels.end());
        EXPECT_EQ(line7_x4->value, 3) << "Line 7, x=4 should be foreground (#)";
        
        auto line7_x0 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 0 && p.y == 7; });
        ASSERT_NE(line7_x0, pixels.end());
        EXPECT_EQ(line7_x0->value, 0) << "Line 7, x=0 should be background (space)";
        
        // Line 8: '  ### ' = "..###."
        auto line8_x2 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 2 && p.y == 8; });
        ASSERT_NE(line8_x2, pixels.end());
        EXPECT_EQ(line8_x2->value, 3) << "Line 8, x=2 should be foreground (#)";
        
        auto line8_x3 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 3 && p.y == 8; });
        ASSERT_NE(line8_x3, pixels.end());
        EXPECT_EQ(line8_x3->value, 3) << "Line 8, x=3 should be foreground (#)";
        
        auto line8_x4 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 4 && p.y == 8; });
        ASSERT_NE(line8_x4, pixels.end());
        EXPECT_EQ(line8_x4->value, 3) << "Line 8, x=4 should be foreground (#)";
        
        // Line 9: ' #### ' = ".####."
        auto line9_x1 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 1 && p.y == 9; });
        ASSERT_NE(line9_x1, pixels.end());
        EXPECT_EQ(line9_x1->value, 3) << "Line 9, x=1 should be foreground (#)";
        
        // Line 10: '## ## ' = "##.##."
        auto line10_x0 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 0 && p.y == 10; });
        ASSERT_NE(line10_x0, pixels.end());
        EXPECT_EQ(line10_x0->value, 3) << "Line 10, x=0 should be foreground (#)";
        
        auto line10_x1 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 1 && p.y == 10; });
        ASSERT_NE(line10_x1, pixels.end());
        EXPECT_EQ(line10_x1->value, 3) << "Line 10, x=1 should be foreground (#)";
        
        auto line10_x2 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 2 && p.y == 10; });
        ASSERT_NE(line10_x2, pixels.end());
        EXPECT_EQ(line10_x2->value, 0) << "Line 10, x=2 should be background (gap)";
        
        auto line10_x3 = std::find_if(pixels.begin(), pixels.end(),
            [](const MockDisplay::Pixel& p) { return p.x == 3 && p.y == 10; });
        ASSERT_NE(line10_x3, pixels.end());
        EXPECT_EQ(line10_x3->value, 3) << "Line 10, x=3 should be foreground (#)";
        
        std::cout << "\nTest verified: First '1' shape rendering matches ASCII art comments in drawing_objects.cpp!\n";
        std::cout << std::endl;
    }

} // namespace rr::ui::test
