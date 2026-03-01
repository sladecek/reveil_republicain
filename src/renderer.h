/// Rendering algorithm
#pragma once

#include "hardware_interface.h"

#include <cstddef>
#include <array>
#include <type_traits>

namespace rr::ui
{

    using String = std::array<uint16_t, 4>;

    
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

    enum class BitsPerPixel: uint8_t
    {
        b1,
        b2,
        b4,
        b8
    };

    template <BitsPerPixel BPP, hw::Display D, Font F>
    class Renderer
    {
    public:
        Renderer(const hw::window_t &w, const F &font) : window_(w), font_(font)
        {
        }

        void draw(const String &s, uint8_t bg, uint8_t fg)
        {
        }

    private:
        hw::window_t window_;
        const F &font_;
    };

}