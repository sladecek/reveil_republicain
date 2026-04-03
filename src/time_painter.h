/// Time painter for displaying Republican calendar time
#pragma once

#include "hardware_interface.h"
#include "renderer.h"
#include "text_layout_calculator.h"
#include "rr_time.h"
#include "number_to_string.h"
#include "generated/drawing_objects.h"

#include <optional>
#include <array>

namespace rr::ui
{

    // Color constants (2-bit colors: 0=black, 1=white, 2=yellow, 3=red)
    constexpr hw::color_t COLOR_BLACK = 0;
    constexpr hw::color_t COLOR_WHITE = 1;
    constexpr hw::color_t COLOR_YELLOW = 2;
    constexpr hw::color_t COLOR_RED = 3;
    constexpr hw::BitsPerPixel BPP = hw::BitsPerPixel::b2;

    template <hw::Display D, Font NormalFont, Font LargeFont>
    class TimePainter
    {
    public:
        TimePainter(D &display, const NormalFont &normal_font, const LargeFont &large_font)
            : display_(display), normal_font_(normal_font), large_font_(large_font)
        {
        }

        void update(const Time &time)
        {
            // Display has 5 lines
            constexpr int line_height_normal = normal_font_height;
            constexpr int line_height_large = big_font_height;
            
            bool needs_display_update = false;
            
            // Line 1: Day and month name (yellow on red, normal font)
            if (!previous_time_.has_value() || 
                previous_time_->day != time.day || 
                previous_time_->month != time.month)
            {
                paint_line1(time);
                needs_display_update = true;
            }
            
            // Line 2: Hour:Minute (black on white, large font)
            if (!previous_time_.has_value() ||
                previous_time_->hour != time.hour ||
                previous_time_->minute != time.minute)
            {
                paint_line2(time);
                needs_display_update = true;
            }
            
            // Line 3: Day name (e.g., "Primidi d.1", black on yellow, normal font)
            if (!previous_time_.has_value() ||
                previous_time_->day != time.day ||
                previous_time_->decade != time.decade)
            {
                paint_line3(time);
                needs_display_update = true;
            }
            
            // Line 4: Year (e.g., "an 234", black on yellow, normal font)
            if (!previous_time_.has_value() ||
                previous_time_->year != time.year)
            {
                paint_line4(time);
                needs_display_update = true;
            }
            
            // Line 5: Day of year name (black on yellow, normal font)
            if (!previous_time_.has_value() ||
                previous_time_->day != time.day ||
                previous_time_->decade != time.decade ||
                previous_time_->month != time.month)
            {
                paint_line5(time);
                needs_display_update = true;
            }

            if (needs_display_update)
            {
                display_.update();
            }
            
            // Save current time
            previous_time_ = time;
        }

    private:
        D &display_;
        const NormalFont &normal_font_;
        const LargeFont &large_font_;
        std::optional<Time> previous_time_;

        void paint_line1(const Time &time)
        {
            // Line 1: "DD MonthName" (yellow on red)
            hw::window_t window{0, 0, 200, normal_font_height};
            Renderer<BPP, D, NormalFont> renderer(display_, window, normal_font_);
            
            // Convert day of decade to 2-digit string
            NumberToString<NormalFont, 2> day_converter;
            int day_in_month = time.decade * 10 + time.day + 1; // +1 because days are 1-based display
            auto day_str = day_converter.convert(day_in_month);
            
            // Create string with day + space
            // String format: [digit1, digit2, space, month_fragment]
            String line1_str;
            line1_str[0] = day_str[2];
            line1_str[1] = day_str[3];
            line1_str[2] = 0; // space
            line1_str[3] = static_cast<uint16_t>(get_month_fragment(time.month));
            
            // Draw the complete line
            renderer.draw(line1_str, COLOR_RED, COLOR_YELLOW, Align::left);
        }

        void paint_line2(const Time &time)
        {
            // Line 2: "HH:MM" (black on white, large font)
            hw::window_t window{0, static_cast<hw::y_t>(normal_font_height), 200, big_font_height};
            Renderer<BPP, D, LargeFont> renderer(display_, window, large_font_);
            
            // Convert hour and minute to 2-digit strings
            NumberToString<LargeFont, 2> converter;
            auto hour_str = converter.convert(time.hour);
            auto minute_str = converter.convert(time.minute);
            
            // Create string: [hour_digit1, hour_digit2, colon, minute_digit1]
            // Note: Since String is only 4 elements, we'll need to draw twice or extend
            // For now, using format HH:M (first minute digit only)
            String line2_str;
            line2_str[0] = hour_str[2];  // First hour digit (from position 2 of right-aligned result)
            line2_str[1] = hour_str[3];  // Second hour digit
            line2_str[2] = static_cast<uint16_t>(fragment_index::colon);
            line2_str[3] = minute_str[2]; // First minute digit
            
            // Draw the complete line
            renderer.draw(line2_str, COLOR_WHITE, COLOR_BLACK, Align::left);
            
            // TODO: Draw second minute digit separately if needed
        }

        void paint_line3(const Time &time)
        {
            // Line 3: "DayName d.D" (e.g., "Primidi d.1", black on yellow)
            hw::y_t y_pos = normal_font_height + big_font_height;
            hw::window_t window{0, y_pos, 200, normal_font_height};
            Renderer<BPP, D, NormalFont> renderer(display_, window, normal_font_);
            
            // Get day name fragment (Primidi, Duodi, etc.)
            fragment_index day_name = get_day_name_fragment(time.day);
            
            // Convert day number to single digit string
            NumberToString<NormalFont, 1> converter;
            auto day_str = converter.convert(time.day + 1); // +1 for 1-based display
            
            // Create string: [day_name_fragment, space, 'd', '.']
            // Note: Actual implementation may need to handle multi-character day names differently
            String line3_str;
            line3_str[0] = static_cast<uint16_t>(day_name);
            line3_str[1] = 0; // space
            line3_str[2] = static_cast<uint16_t>(fragment_index::day); // "d." fragment
            line3_str[3] = day_str[3]; // day digit
            
            // Draw the complete line
            renderer.draw(line3_str, COLOR_YELLOW, COLOR_BLACK, Align::left);
        }

        void paint_line4(const Time &time)
        {
            // Line 4: "an YYY" (3 digit year, black on yellow)
            hw::y_t y_pos = normal_font_height + big_font_height + normal_font_height;
            hw::window_t window{0, y_pos, 200, normal_font_height};
            Renderer<BPP, D, NormalFont> renderer(display_, window, normal_font_);
            
            // Convert year to 3-digit string
            NumberToString<NormalFont, 3> converter;
            auto year_str = converter.convert(time.year);
            
            // Create string: [annee_fragment, year_digit1, year_digit2, year_digit3]
            String line4_str;
            line4_str[0] = static_cast<uint16_t>(fragment_index::annee); // "an" fragment
            line4_str[1] = year_str[1]; // First year digit (from position 1 of right-aligned result)
            line4_str[2] = year_str[2]; // Second year digit
            line4_str[3] = year_str[3]; // Third year digit
            
            // Draw the complete line
            renderer.draw(line4_str, COLOR_YELLOW, COLOR_BLACK, Align::left);
        }

        void paint_line5(const Time &time)
        {
            // Line 5: Day of year name (e.g., "raisin", black on yellow)
            hw::y_t y_pos = normal_font_height + big_font_height + 2 * normal_font_height;
            hw::window_t window{0, y_pos, 200, normal_font_height};
            Renderer<BPP, D, NormalFont> renderer(display_, window, normal_font_);
            
            // Get day of year (0-364 or 0-365)
            int day_of_year = time.day_of_year();
            
            // Get day of year name fragment
            fragment_index day_name = get_day_of_year_fragment(day_of_year);
            
            // Create string: [day_of_year_name_fragment, NULL, NULL, NULL]
            String line5_str;
            line5_str[0] = static_cast<uint16_t>(day_name);
            line5_str[1] = NULL_CHAR;
            line5_str[2] = NULL_CHAR;
            line5_str[3] = NULL_CHAR;
            
            // Draw the complete line
            renderer.draw(line5_str, COLOR_YELLOW, COLOR_BLACK, Align::left);
        }

        // Helper to get month name fragment index
        fragment_index get_month_fragment(uint8_t month) const
        {
            // months enum starts at index 24
            return static_cast<fragment_index>(
                static_cast<uint16_t>(fragment_index::months) + month
            );
        }

        // Helper to get day name fragment index
        fragment_index get_day_name_fragment(uint8_t day_of_decade) const
        {
            // days enum starts at index 36
            return static_cast<fragment_index>(
                static_cast<uint16_t>(fragment_index::days) + day_of_decade
            );
        }

        // Helper to get day of year name fragment index
        fragment_index get_day_of_year_fragment(int day_of_year) const
        {
            // day_of_year enum starts at index 52
            return static_cast<fragment_index>(
                static_cast<uint16_t>(fragment_index::day_of_year) + day_of_year
            );
        }
    };

} // namespace rr::ui
