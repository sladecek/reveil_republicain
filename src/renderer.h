/// Rendering algorithm
#pragma once

#include "hardware_interface.h"
#include "font.h"
#include "generated/drawing_objects.h"

#include <cstddef>
#include <array>
#include <type_traits>

namespace rr::ui
{

    using String = std::array<uint16_t, 4>;
    constexpr uint16_t NULL_CHAR = 0xFFFF;


    template <hw::BitsPerPixel BPP, hw::Display D, Font F>
    class Renderer
    {
    public:
        Renderer(D &display, const hw::window_t &w, const F &font) 
            : display_(display), window_(w), font_(font)
        {
        }

        void fill(hw::color_t bg)
        {
            display_.start_window(window_);
            
            // Calculate number of pixels and pack them according to BPP
            int total_pixels = window_.width * window_.height;
            int bits_per_pixel = static_cast<int>(BPP);
            int pixels_per_byte = 8 / bits_per_pixel;
            int total_bytes = (total_pixels + pixels_per_byte - 1) / pixels_per_byte;
            
            // Pack color into a byte based on BPP
            hw::pixel_t packed_pixel = 0;
            for (int i = 0; i < pixels_per_byte; ++i)
            {
                int shift = (pixels_per_byte - 1 - i) * bits_per_pixel;
                packed_pixel |= (bg << shift);
            }
            
            // Send packed pixels
            for (int i = 0; i < total_bytes; ++i)
            {
                display_.send_pixel(packed_pixel);
            }
            
            display_.finish_window();
        }

        enum class Align { left, center, right};

        void draw(const String &s, hw::color_t bg, hw::color_t fg, Align align)
        {
            display_.start_window(window_);
            
            int bits_per_pixel = static_cast<int>(BPP);
            int pixels_per_byte = 8 / bits_per_pixel;
            
            // Current position in the window
            hw::x_t x_pos = 0;
            
            // For each element in the string
            for (int str_idx = 0; str_idx < 4; ++str_idx)
            {
                uint16_t char_or_fragment = s[str_idx];
                
                // Skip NULL characters
                if (char_or_fragment == NULL_CHAR)
                    continue;
                
                // Check if it's a fragment (index >= fragment_count means it's a single char)
                if (char_or_fragment < fragment_count)
                {
                    // It's a fragment - render multiple characters
                    uint16_t frag_idx = char_or_fragment;
                    uint16_t frag_start = fragment_begin[frag_idx];
                    uint16_t frag_length = fragment_len[frag_idx];
                    
                    for (uint16_t i = 0; i < frag_length; ++i)
                    {
                        uint8_t char_idx = fragment_content[frag_start + i];
                        x_pos = render_char(char_idx, x_pos, bg, fg);
                    }
                }
                else
                {
                    // It's a single character index
                    uint8_t char_idx = static_cast<uint8_t>(char_or_fragment);
                    x_pos = render_char(char_idx, x_pos, bg, fg);
                }
            }
            
            // Fill remaining window with background color
            int remaining_pixels = window_.width - x_pos;
            if (remaining_pixels > 0)
            {
                int total_pixels = remaining_pixels * window_.height;
                int total_bytes = (total_pixels + pixels_per_byte - 1) / pixels_per_byte;
                
                hw::pixel_t packed_bg = 0;
                for (int i = 0; i < pixels_per_byte; ++i)
                {
                    int shift = (pixels_per_byte - 1 - i) * bits_per_pixel;
                    packed_bg |= (bg << shift);
                }
                
                for (int i = 0; i < total_bytes; ++i)
                {
                    display_.send_pixel(packed_bg);
                }
            }
            
            display_.finish_window();
        }


        inline hw::x_t measure_string_width(const String &s) {
            hw::x_t result = 0; 
            loop_over_all_chars_in_string(s, [](auto&&...){}, [&result](hw::x_t x){result = x;});
            return result;
        }

    private:
        D &display_;
        hw::window_t window_;
        const F &font_;
        

        template <typename F1, typename F2>
        inline void loop_over_all_chars_in_string(const String &s, F1&& inner, F2&& final) {
            hw::y_t effective_height = std::min(static_cast<hw::y_t>(F::font_height), window_.height);
            
            for (const auto fragment: s) {
                if (fragment != NULL_CHAR) {
                    for (hw::y_t y = 0; y < effective_height; ++y){
                        hw::x_t x = 0;
                        for (size_t ic = 0; ic < fragment_len[fragment]; ++ic) {
                            const auto ch = fragment_content[fragment_begin[fragment]+ic];
                            const hw::x_t char_width = font_.char_widths[ch];
                            inner(ch, char_width);
                            x += char_width;
                        }
                        final(x);
                    }
                }
            }
        }  

        
        // Render a single character and return the new x position
        hw::x_t render_char(uint8_t char_idx, hw::x_t x_pos, hw::color_t bg, hw::color_t fg)
        {
            // Get character properties
            if (char_idx >= font_.char_widths.size())
                return x_pos; // Invalid character
            
            uint8_t char_width = font_.char_widths[char_idx];
            uint16_t char_data_begin = font_.char_begin[char_idx];
            
            int bits_per_pixel = static_cast<int>(BPP);
            int pixels_per_byte = 8 / bits_per_pixel;
            
            // Render character: font data is organized as columns (x) × rows (y)
            // Display expects data in row-major order
            // We need to transpose: iterate rows first, then columns
            
            for (size_t row = 0; row < F::font_height; ++row)
            {
                for (uint8_t col = 0; col < char_width; ++col)
                {
                    // Calculate bit position in font data (column-major)
                    size_t bit_idx = char_data_begin + col * F::font_height + row;
                    size_t byte_idx = bit_idx / 8;
                    size_t bit_in_byte = bit_idx % 8;
                    
                    // Get pixel value (1 = foreground, 0 = background)
                    bool pixel_on = false;
                    if (byte_idx < font_.content.size())
                    {
                        pixel_on = (font_.content[byte_idx] >> (7 - bit_in_byte)) & 1;
                    }
                    
                    hw::color_t color = pixel_on ? fg : bg;
                    
                    // Pack and send pixel
                    // Note: This simplified version sends one color at a time
                    // A more optimized version would pack multiple pixels per byte
                    hw::pixel_t packed = color << ((pixels_per_byte - 1) * bits_per_pixel);
                    for (int i = 1; i < pixels_per_byte; ++i)
                    {
                        packed |= (color << ((pixels_per_byte - 1 - i) * bits_per_pixel));
                    }
                    display_.send_pixel(packed);
                }
            }
            
            return x_pos + char_width;
        }
    };

}