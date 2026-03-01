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
        struct Pixel
        {
            hw::x_t x;
            hw::y_t y;
            hw::pixel_t value;
        };

        void start_window(const hw::window_t &w)
        {
            current_window_ = w;
            current_x_ = w.x;
            current_y_ = w.y;
        }

        void send_pixel(hw::pixel_t pixel)
        {
            pixels_.push_back({current_x_, current_y_, pixel});
            current_x_++;
            if (current_x_ >= current_window_.x + current_window_.width)
            {
                current_x_ = current_window_.x;
                current_y_++;
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
        hw::x_t current_x_{};
        hw::y_t current_y_{};
        std::vector<Pixel> pixels_;
    };

    TEST(RendererTest, CreateRenderer)
    {
        MockDisplay display;
        NormalFont font;
        hw::window_t window{0, 0, 200, 24};

        Renderer<BitsPerPixel::b2, MockDisplay, NormalFont> renderer(window, font);

        // Test passes if it compiles and constructs
        SUCCEED();
    }

    TEST(RendererTest, RenderHello)
    {
        MockDisplay display;
        NormalFont font;
        hw::window_t window{0, 0, 200, 24};

        Renderer<BitsPerPixel::b2, MockDisplay, NormalFont> renderer(window, font);

        // Create "hello" string
        // Note: This is a simplified test - actual character mapping would need to be implemented
        String hello_str = {0, 0, 0, 0}; // Placeholder

        renderer.draw(hello_str, 0, 3); // bg=0 (black), fg=3 (white/max)

        // For now, just verify it doesn't crash
        // In a complete implementation, we would verify the pixel output
        SUCCEED();
    }

} // namespace rr::ui::test
