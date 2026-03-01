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