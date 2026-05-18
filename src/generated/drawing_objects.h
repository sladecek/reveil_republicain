#pragma once

#include <cstdint>
#include <array>

namespace rr::ui {

// Fragment table declarations
constexpr int fragment_count = 415;
constexpr int fragment_content_size = 4461;
extern const std::array<uint8_t, fragment_content_size> fragment_content;
extern const std::array<uint16_t, fragment_count> fragment_begin;
extern const std::array<uint16_t, fragment_count> fragment_len;

// Fragment label indices
enum class fragment_index : uint16_t {
    nr = 0,
    colon = 10,
    space = 11,
    run = 12,
    stop = 13,
    alarm = 14,
    hour = 15,
    minute = 16,
    set = 17,
    day = 18,
    month = 19,
    year = 20,
    annee = 21,
    decade = 22,
    jourdu = 23,
    jourepagomene = 24,
    on_off = 25,
    months = 27,
    days = 39,
    sansculottides = 49,
    day_of_year = 55,
};

// Font: big (size 36pt, height 39px)
constexpr int big_font_len = 11;
constexpr int big_font_height = 39;
extern const std::array<uint8_t, big_font_len> big_font_char_widths;
extern const std::array<uint16_t, big_font_len> big_font_char_begin;
extern const std::array<uint8_t, 1170> big_font_content;

// Font: normal (size 18pt, height 24px)
constexpr int normal_font_len = 63;
constexpr int normal_font_height = 24;
extern const std::array<uint8_t, normal_font_len> normal_font_char_widths;
extern const std::array<uint16_t, normal_font_len> normal_font_char_begin;
extern const std::array<uint8_t, 1896> normal_font_content;

} // namespace rr::ui
