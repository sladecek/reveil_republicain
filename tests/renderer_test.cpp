#include "renderer.h"
#include "concrete_fonts.h"

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
            hw::x_t x;
            hw::y_t y;
            hw::color_t value;
        };

        void start_window(const hw::window_t &w)
        {
            current_window_ = w;
            window_pixel_index_ = 0;
        }

        void send_pixel(hw::pixel_t pixel)
        {
            // Each byte contains 4 pixels (2 bits each)
            for (int i = 0; i < PIXELS_PER_BYTE; ++i)
            {
                if (window_pixel_index_ >= current_window_.width * current_window_.height)
                    break;

                int local_x = window_pixel_index_ % current_window_.width;
                int local_y = window_pixel_index_ / current_window_.width;
                int global_x = current_window_.x + local_x;
                int global_y = current_window_.y + local_y;

                // Extract 2 bits for this pixel (from MSB to LSB)
                int shift = 6 - (i * 2);
                hw::color_t pixel_value = (pixel >> shift) & 0x03;
                
                pixels_.push_back({static_cast<hw::x_t>(global_x), 
                                  static_cast<hw::y_t>(global_y), 
                                  pixel_value});
                window_pixel_index_++;
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

        const std::vector<Pixel> &get_pixels() const { return pixels_; }
        void clear() { pixels_.clear(); }

    private:
        hw::window_t current_window_{};
        int window_pixel_index_{};
        std::vector<Pixel> pixels_;
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

        renderer.draw(hello_str, 0, 3); // bg=0 (black), fg=3 (white/max)

        // For now, just verify it doesn't crash
        // In a complete implementation, we would verify the pixel output
        SUCCEED();
    }

} // namespace rr::ui::test
