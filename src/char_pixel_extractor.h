#pragma once

#include <cstdint>
#include <functional>
#include "font.h"
#include "hardware_interface.h"

namespace rr::ui
{
    // Extracts pixels from a character bitmap in a font.
    // Character bitmaps are stored with pixels packed into bytes (8 pixels per byte, MSB first).
    // This class iterates through the pixels of a single line of a character.
    template <Font F>
    class CharPixelExtractor
    {
    public:
        using PixelCallback = std::function<void(bool)>;

        CharPixelExtractor(const F &font, PixelCallback draw_pixel)
            : font(font)
            , draw_pixel(draw_pixel)
        {
        }

        // Extract and draw all pixels for one line of a character.
        // ch: character index in the font
        // y: line number (0 = top line of character)
        // char_width: width of the character in pixels
        // max_pixels: maximum number of pixels to extract (for clipping)
        void extract_char_line(uint8_t ch, hw::y_t y, hw::x_t char_width, hw::x_t max_pixels)
        {
            const auto char_line_bytes = (char_width + 7) / 8;
            auto char_data_begin = font.char_begin[ch] + y * char_line_bytes;
            
            int bit = 0;
            uint8_t byte{};
            
            for (hw::x_t i = 0; i < char_width && i < max_pixels; ++i)
            {
                if (bit == 0)
                {
                    byte = font.content[char_data_begin++];
                }
                draw_pixel(byte & 0x80);
                byte <<= 1;
                bit++;
                bit %= 8;
            }
        }

    private:
        const F &font;
        PixelCallback draw_pixel;
    };

} // namespace rr::ui
