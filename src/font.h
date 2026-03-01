/// Font definition
#pragma once

#include <cstddef>
#include <array>
#include <type_traits>

namespace rr::ui
{  
    template <typename T>
    concept Font = requires {
        { T::font_len } -> std::convertible_to<size_t>;
        { T::font_height } -> std::convertible_to<size_t>;
        { T::font_content_size } -> std::convertible_to<size_t>;
    } && requires(T font) {
        { font.char_widths } -> std::convertible_to<const std::array<uint8_t, T::font_len>&>;
        { font.char_begin } -> std::convertible_to<const std::array<uint16_t, T::font_len>&>;
        { font.content } -> std::convertible_to<const std::array<uint8_t, T::font_content_size>&>;
    };
}
