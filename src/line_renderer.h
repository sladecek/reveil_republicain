#pragma once

#include "hardware_interface.h"
#include "font.h"
#include "bit_packer.h"
#include "char_pixel_extractor.h"
#include "string_iterator.h"
#include "text_layout_calculator.h"

#include <functional>

namespace rr::ui
{
    // Renders a single horizontal line of text
    template <hw::BitsPerPixel BPP, Font F>
    class LineRenderer
    {
    public:
        LineRenderer(const F &font) : font_(font) {}

        // Render one line (y coordinate) of a string
        // packer: BitPacker for pixel output
        // y: vertical line number (0 = top)
        // layout: horizontal layout (padding and text width)
        // s: string to render
        // bg, fg: background and foreground colors
        void render_line(
            BitPacker<static_cast<int>(BPP)> &packer,
            hw::y_t y,
            hw::y_t font_height,
            hw::x_t window_width,
            const HorizontalLayout &layout,
            const String &s,
            hw::color_t bg,
            hw::color_t fg)
        {
            packer.start_line();

            if (y < font_height)
            {
                // Draw text line with padding
                const auto draw_pixel = [&](bool bit)
                {
                    packer.draw_pixel(bit ? fg : bg);
                };

                const auto fill_pixels_with_bg = [&](hw::x_t count)
                {
                    for (hw::x_t i = 0; i < count; ++i)
                    {
                        draw_pixel(false);
                    }
                };

                fill_pixels_with_bg(layout.left_padding);

                CharPixelExtractor<F> extractor(font_, draw_pixel);
                StringIterator<F> iterator(font_);

                iterator.iterate(s, [&](uint8_t ch, hw::x_t x, hw::x_t char_width)
                {
                    hw::x_t max_pixels = TextLayoutCalculator::calculate_clipping(
                        x, char_width, layout.text_width);
                    extractor.extract_char_line(ch, y, char_width, max_pixels);
                });

                fill_pixels_with_bg(layout.right_padding);
            }
            else
            {
                // Below font height - fill entire line with background
                for (hw::x_t i = 0; i < window_width; ++i)
                {
                    packer.draw_pixel(bg);
                }
            }

            packer.end_line();
        }

    private:
        const F &font_;
    };

} // namespace rr::ui
