#pragma once

#include "hardware_interface.h"
#include "font.h"
#include "generated/drawing_objects.h"

#include <array>
#include <cstdint>
#include <functional>

namespace rr::ui
{
    using String = std::array<uint16_t, 4>;
    constexpr uint16_t NULL_CHAR = 0xFFFF;

    // Iterates through all characters in a String (which contains fragments)
    template <Font F>
    class StringIterator
    {
    public:
        using CharCallback = std::function<void(uint8_t ch, hw::x_t x, hw::x_t char_width)>;

        StringIterator(const F &font) : font_(font) {}

        // Iterate through all characters in the string, calling the callback for each
        // Returns the total width of the string
        hw::x_t iterate(const String &s, CharCallback callback) const
        {
            hw::x_t x = 0;

            for (const auto fragment : s)
            {
                if (fragment != NULL_CHAR)
                {
                    for (size_t ic = 0; ic < fragment_len[fragment]; ++ic)
                    {
                        const auto ch = fragment_content[fragment_begin[fragment] + ic];
                        const hw::x_t char_width = font_.char_widths[ch];
                        callback(ch, x, char_width);
                        x += char_width;
                    }
                }
            }
            return x;
        }

        // Measure the total width of a string without drawing
        hw::x_t measure_width(const String &s) const
        {
            return iterate(s, [](auto &&...) {});
        }

    private:
        const F &font_;
    };

} // namespace rr::ui
