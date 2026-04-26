/// Menu painter for displaying menu options
#pragma once

#include "hardware_interface.h"
#include "renderer.h"
#include "text_layout_calculator.h"
#include "state.h"
#include "number_to_string.h"
#include "generated/drawing_objects.h"

#include <optional>
#include <array>

namespace rr::ui
{

    template <hw::Display D, Font NormalFont>
    class MenuPainter
    {
    public:
        MenuPainter(D &display, const NormalFont &normal_font)
            : display(display), normal_font(normal_font)
        {
        }

        void update(const State &state)
        {
            bool needs_display_update = false;

            // Check if menu line changed or any relevant state changed
            if (!previous_state.has_value() ||
                previous_state->menu_line != state.menu_line ||
                previous_state->alarm_state != state.alarm_state ||
                previous_state->alarm_hour != state.alarm_hour ||
                previous_state->alarm_minute != state.alarm_minute ||
                previous_state->time.hour != state.time.hour ||
                previous_state->time.minute != state.time.minute ||
                previous_state->time.day != state.time.day ||
                previous_state->time.month != state.time.month ||
                previous_state->time.year != state.time.year)
            {
                paint_menu(state);
                needs_display_update = true;
            }

            if (needs_display_update)
            {
                display.update();
            }

            // Save current state
            previous_state = state;
        }

    private:
        D &display;
        const NormalFont &normal_font;
        std::optional<State> previous_state;

        // Menu has 10 lines total (0-9)
        static constexpr int MENU_LINE_COUNT = 10;
        static constexpr int DISPLAY_LINES = 4;

        void paint_menu(const State &state)
        {
            // Determine which 4 lines to display based on menu_line
            int first_line = 0;
            if (state.menu_line >= 2)
            {
                first_line = state.menu_line - 1;
                if (first_line + DISPLAY_LINES > MENU_LINE_COUNT)
                {
                    first_line = MENU_LINE_COUNT - DISPLAY_LINES;
                }
            }

            // Paint 4 display lines
            for (int i = 0; i < DISPLAY_LINES; ++i)
            {
                int menu_line_index = first_line + i;
                bool is_highlighted = (menu_line_index == state.menu_line);
                paint_menu_line(i, menu_line_index, state, is_highlighted);
            }
        }

        void paint_menu_line(int display_line, int menu_line_index, const State &state, bool highlighted)
        {
            hw::y_t y_pos = display_line * normal_font_height;
            hw::window_t window{0, y_pos, 200, normal_font_height};
            Renderer<BPP, D, NormalFont> renderer(display, window, normal_font);

            String line_str;
            get_menu_line_content(menu_line_index, state, line_str);

            // Highlighted line: white on black, others: black on white
            hw::color_t bg_color = highlighted ? COLOR_BLACK : COLOR_WHITE;
            hw::color_t fg_color = highlighted ? COLOR_WHITE : COLOR_BLACK;

            renderer.draw(line_str, bg_color, fg_color, Align::center);
        }

        void get_menu_line_content(int menu_line_index, const State &state, String &line_str)
        {
            NumberToString<NormalFont, 2> converter;

            switch (menu_line_index)
            {
            case 0: // run
                line_str[0] = static_cast<uint16_t>(fragment_index::run);
                line_str[1] = NULL_CHAR;
                line_str[2] = NULL_CHAR;
                line_str[3] = NULL_CHAR;
                break;

            case 1: // alarm on/off
            {
                bool alarm_is_on = (state.alarm_state == AlarmState::on || 
                                   state.alarm_state == AlarmState::active || 
                                   state.alarm_state == AlarmState::cleared);
                uint16_t on_off_index = alarm_is_on ? 0 : 1;
                line_str[0] = static_cast<uint16_t>(fragment_index::alarm);
                line_str[1] = static_cast<uint16_t>(fragment_index::space);
                line_str[2] = static_cast<uint16_t>(fragment_index::on_off) + on_off_index;
                line_str[3] = NULL_CHAR;
                break;
            }

            case 2: // alarm hour XX
            {
                auto hour_str = converter.convert(state.alarm_hour);
                line_str[0] = static_cast<uint16_t>(fragment_index::alarm);
                line_str[1] = static_cast<uint16_t>(fragment_index::hour);
                line_str[2] = hour_str[2];
                line_str[3] = hour_str[3];
                break;
            }

            case 3: // alarm minute XX
            {
                auto minute_str = converter.convert(state.alarm_minute);
                line_str[0] = static_cast<uint16_t>(fragment_index::alarm);
                line_str[1] = static_cast<uint16_t>(fragment_index::minute);
                line_str[2] = minute_str[2];
                line_str[3] = minute_str[3];
                break;
            }

            case 4: // set hour XX
            {
                auto hour_str = converter.convert(state.time.hour);
                line_str[0] = static_cast<uint16_t>(fragment_index::set);
                line_str[1] = static_cast<uint16_t>(fragment_index::hour);
                line_str[2] = hour_str[2];
                line_str[3] = hour_str[3];
                break;
            }

            case 5: // set minute XX
            {
                auto minute_str = converter.convert(state.time.minute);
                line_str[0] = static_cast<uint16_t>(fragment_index::set);
                line_str[1] = static_cast<uint16_t>(fragment_index::minute);
                line_str[2] = minute_str[2];
                line_str[3] = minute_str[3];
                break;
            }

            case 6: // set day XX
            {
                auto day_str = converter.convert(state.time.day);
                line_str[0] = static_cast<uint16_t>(fragment_index::set);
                line_str[1] = static_cast<uint16_t>(fragment_index::day);
                line_str[2] = day_str[2];
                line_str[3] = day_str[3];
                break;
            }

            case 7: // set month XX
            {
                auto month_str = converter.convert(state.time.month);
                line_str[0] = static_cast<uint16_t>(fragment_index::set);
                line_str[1] = static_cast<uint16_t>(fragment_index::month);
                line_str[2] = month_str[2];
                line_str[3] = month_str[3];
                break;
            }

            case 8: // set year XX (using 2 digits for year, will display 00-99)
            {
                auto year_str = converter.convert(state.time.year % 100);
                line_str[0] = static_cast<uint16_t>(fragment_index::set);
                line_str[1] = static_cast<uint16_t>(fragment_index::year);
                line_str[2] = year_str[2];
                line_str[3] = year_str[3];
                break;
            }

            case 9: // run
                line_str[0] = static_cast<uint16_t>(fragment_index::run);
                line_str[1] = NULL_CHAR;
                line_str[2] = NULL_CHAR;
                line_str[3] = NULL_CHAR;
                break;

            default:
                line_str[0] = NULL_CHAR;
                line_str[1] = NULL_CHAR;
                line_str[2] = NULL_CHAR;
                line_str[3] = NULL_CHAR;
                break;
            }
        }
    };

} // namespace rr::ui
