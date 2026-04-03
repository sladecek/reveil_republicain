#pragma once

#include "hardware_interface.h"

namespace rr::ui
{
    enum class Align
    {
        left,
        center,
        right
    };

    struct HorizontalLayout
    {
        hw::x_t left_padding;
        hw::x_t text_width;
        hw::x_t right_padding;
    };

    class TextLayoutCalculator
    {
    public:
        static HorizontalLayout compute_horizontal_alignment(
            hw::x_t window_width,
            hw::x_t string_width,
            Align align)
        {
            HorizontalLayout layout;

            // If string fits entirely in window, compute padding based on alignment
            if (string_width <= window_width)
            {
                layout.text_width = string_width;

                switch (align)
                {
                case Align::left:
                    layout.left_padding = 0;
                    layout.right_padding = window_width - string_width;
                    break;

                case Align::center:
                    layout.left_padding = (window_width - string_width) / 2;
                    layout.right_padding = window_width - string_width - layout.left_padding;
                    break;

                case Align::right:
                    layout.left_padding = window_width - string_width;
                    layout.right_padding = 0;
                    break;
                }
            }
            else
            {
                // String is wider than window - truncate it
                layout.left_padding = 0;
                layout.text_width = window_width;
                layout.right_padding = 0;
            }

            return layout;
        }

        // Calculate how many pixels of a character should be drawn considering clipping
        static hw::x_t calculate_clipping(hw::x_t x, hw::x_t char_width, hw::x_t text_width)
        {
            if (x + char_width <= text_width)
            {
                return char_width;
            }
            else if (text_width > x)
            {
                return text_width - x;
            }
            else
            {
                return 0;
            }
        }
    };

} // namespace rr::ui
