/// Rendering algorithm
#pragma once

#include "hardware_interface.h"
#include "font.h"
#include "bit_packer.h"
#include "string_iterator.h"
#include "text_layout_calculator.h"
#include "line_renderer.h"

#include <cstddef>
#include <type_traits>

namespace rr::ui
{

    template <hw::BitsPerPixel BPP, hw::Display D, Font F>
    class Renderer
    {
    public:
        Renderer(D &display, const hw::window_t &w, const F &font)
            : display(display), window(w), font(font), string_iterator(font), line_renderer(font)
        {
        }

        void draw(const String &s, hw::color_t bg, hw::color_t fg, Align align)
        {
            display.start_window(window);

            const auto string_width = string_iterator.measure_width(s);
            const auto layout = TextLayoutCalculator::compute_horizontal_alignment(
                window.width, string_width, align);

            // Vertical centering: calculate offset to center font in window
            const hw::y_t vertical_offset = (window.height > font.font_height) 
                ? (window.height - font.font_height) / 2 
                : 0;

            // Create bit packer with callback to send bytes to display
            auto send_byte = [this](uint8_t byte) { display.send_pixels(byte); };
            BitPacker<static_cast<int>(BPP)> packer(send_byte);

            for (hw::y_t y = 0; y < window.height; y++)
            {
                // Adjust y coordinate for vertical centering
                hw::y_t font_y = (y >= vertical_offset && y < vertical_offset + font.font_height)
                    ? y - vertical_offset
                    : font.font_height; // Out of range - will fill with background
                
                line_renderer.render_line(packer, font_y, font.font_height, window.width,
                                          layout, s, bg, fg);
            }

            display.finish_window();
        }

        hw::x_t measure_string_width(const String &s)
        {
            return string_iterator.measure_width(s);
        }

        void fill(hw::color_t bg)
        {
            constexpr String empty_string{NULL_CHAR, NULL_CHAR, NULL_CHAR, NULL_CHAR};
            draw(empty_string, bg, bg, Align::left);
        }

    private:
        D &display;
        hw::window_t window;
        const F &font;
        StringIterator<F> string_iterator;
        LineRenderer<BPP, F> line_renderer;
    };

}