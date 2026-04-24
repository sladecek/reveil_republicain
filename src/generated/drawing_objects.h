#pragma once

#include <cstdint>
#include <array>

namespace rr::ui {

// Fragment table declarations
constexpr int fragment_count = 416;
constexpr int fragment_content_size = 2873;
extern const std::array<uint8_t, fragment_content_size> fragment_content;
extern const std::array<uint16_t, fragment_count> fragment_begin;
extern const std::array<uint16_t, fragment_count> fragment_len;

// Fragment label indices
enum class fragment_index : uint16_t {
    nr = 0,
    colon = 10,
    space = 11,
    bell = 12,
    run = 13,
    stop = 14,
    alarm = 15,
    hour = 16,
    minute = 17,
    set = 18,
    day = 19,
    month = 20,
    year = 21,
    annee = 22,
    decade = 23,
    jourdu = 24,
    jourepagomene = 25,
    on_off = 26,
    months = 28,
    days = 40,
    sansculottides = 50,
    day_of_year = 56,
};

// Font: big (size 36pt, height 39px)
constexpr int big_font_len = 11;
constexpr int big_font_height = 39;
extern const std::array<uint8_t, big_font_len> big_font_char_widths;
extern const std::array<uint16_t, big_font_len> big_font_char_begin;
extern const std::array<uint8_t, 1170> big_font_content;

// Font: normal (size 18pt, height 24px)
constexpr int normal_font_len = 64;
constexpr int normal_font_height = 24;
extern const std::array<uint8_t, normal_font_len> normal_font_char_widths;
extern const std::array<uint16_t, normal_font_len> normal_font_char_begin;
extern const std::array<uint8_t, 1944> normal_font_content;

} // namespace rr::ui
