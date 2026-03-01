/// Rendering algorithm
#pragma once

#include "hardware_interface.h"
#include "font.h"

#include <cstddef>
#include <array>
#include <type_traits>

namespace rr::ui
{

    using String = std::array<uint16_t, 4>;


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

        void draw(const String &s, hw::color_t bg, hw::color_t fg)
        {
        }

    private:
        D &display_;
        hw::window_t window_;
        const F &font_;
    };

}