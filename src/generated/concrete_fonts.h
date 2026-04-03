/// Font definitions
#pragma once

#include "generated/drawing_objects.h"
#include "font.h"

namespace rr::ui
{

// Wrapper for the normal font to match Font template structure
struct NormalFont {
    static constexpr size_t font_len = normal_font_len;
    static constexpr size_t font_height = normal_font_height;
    static constexpr size_t font_content_size = 1872;

    const std::array<uint8_t, normal_font_len>& char_widths = normal_font_char_widths;
    const std::array<uint16_t, normal_font_len>& char_begin = normal_font_char_begin;
    const std::array<uint8_t, 1872>& content = normal_font_content;
};


// Wrapper for the big font to match Font template structure
struct BigFont {
    static constexpr size_t font_len = big_font_len;
    static constexpr size_t font_height = big_font_height;
    static constexpr size_t font_content_size = 819;

    const std::array<uint8_t, big_font_len>& char_widths = big_font_char_widths;
    const std::array<uint16_t, big_font_len>& char_begin = big_font_char_begin;
    const std::array<uint8_t, 819>& content = big_font_content;
};

}
