// Main class for the French Calender Alarm Clock

#pragma once

#include "hardware_interface.h"
#include "renderer.h"
#include "generated/concrete_fonts.h"
#include "time_painter.h"
#include "menu_painter.h"
#include "rr_time.h"
#include "state.h"

#include <concepts>
#include <variant>
#include <cstdio>

namespace rr
{
    // Debug printing functions (implemented in reveil.cpp)
    namespace debug
    {
        void print_encoder_event(const hw::EncoderEvent& event);
        void print_timer_event(const hw::TimerEvent& event);
    }

    // Compile-time flag to enable/disable debug printing
    template<bool EnableDebug = false>
    class ReveilRepublicain
    {
    public:
        ReveilRepublicain() = default;
        
        template <hw::Display D, hw::Timer T>
        hw::output_flags_t compute_update(D &display, T &timer, const hw::Event &event)
        {
            hw::output_flags_t output_flags = static_cast<hw::output_flags_t>(hw::OutputFlags::None);
            
            // Debug printing for all events except TickEvent
            if constexpr (EnableDebug)
            {
                if (std::holds_alternative<hw::EncoderEvent>(event))
                {
                    debug::print_encoder_event(std::get<hw::EncoderEvent>(event));
                }
                else if (std::holds_alternative<hw::TimerEvent>(event))
                {
                    debug::print_timer_event(std::get<hw::TimerEvent>(event));
                }
            }
            
            // Handle encoder events
            if (std::holds_alternative<hw::EncoderEvent>(event))
            {
                const auto& encoder_event = std::get<hw::EncoderEvent>(event);
                
                // Clear alarm if active
                if (state.alarm_state == AlarmState::active)
                {
                    state.alarm_state = AlarmState::cleared;
                }
                else
                {
                    bool was_menu_on = state.menu_on;
                    process_menu(encoder_event);
                    
                    // Update display after menu processing
                    ui::NormalFont normal_font;
                    
                    if (state.menu_on)
                    {
                        // Show menu
                        ui::MenuPainter<D, ui::NormalFont> menu_painter(display, normal_font);
                        menu_painter.update(state);
                    }
                    else if (was_menu_on)
                    {
                        // Menu was just turned off, show time immediately
                        ui::BigFont big_font;
                        ui::TimePainter<D, ui::NormalFont, ui::BigFont> time_painter(display, normal_font, big_font);
                        bool alarm_is_on = (state.alarm_state == AlarmState::on || 
                                          state.alarm_state == AlarmState::active);
                        time_painter.update(state.time, alarm_is_on);
                    }
                }
            }
            
            // Handle timer events - update time display
            if (std::holds_alternative<hw::TimerEvent>(event))
            {
                const auto& timer_event = std::get<hw::TimerEvent>(event);
                
                // Unpack current time from timer event
                Time current_time(timer_event.timestamp);
                
                // Update state time
                state.time = current_time;
                
                // Maintain alarm state
                maintain_alarm_state();
                
                // Set beeper flag if alarm is active
                if (state.alarm_state == AlarmState::active)
                {
                    output_flags |= static_cast<hw::output_flags_t>(hw::OutputFlags::Beep);
                }
                
                // Create fonts
                ui::NormalFont normal_font;
                ui::BigFont big_font;
                
                // Update display based on menu state
                if (state.menu_on)
                {
                    // Show menu
                    ui::MenuPainter<D, ui::NormalFont> menu_painter(display, normal_font);
                    menu_painter.update(state);
                }
                else
                {
                    // Show time
                    ui::TimePainter<D, ui::NormalFont, ui::BigFont> time_painter(display, normal_font, big_font);
                    bool alarm_is_on = (state.alarm_state == AlarmState::on || 
                                      state.alarm_state == AlarmState::active);
                    time_painter.update(current_time, alarm_is_on);
                }
                
                // Schedule next timer event at the next decimal minute change
                auto next_minute = current_time.compute_next_minute_change();
                timer.set_next_clock_event_time(next_minute);
            }
            
            return output_flags;
        }
        
    private:
        State state{};
        
        // Menu line indices
        static constexpr int MENU_LINE_RUN_TOP = 0;
        static constexpr int MENU_LINE_ALARM_ON_OFF = 1;
        static constexpr int MENU_LINE_ALARM_HOUR = 2;
        static constexpr int MENU_LINE_ALARM_MINUTE = 3;
        static constexpr int MENU_LINE_SET_HOUR = 4;
        static constexpr int MENU_LINE_SET_MINUTE = 5;
        static constexpr int MENU_LINE_SET_DAY = 6;
        static constexpr int MENU_LINE_SET_MONTH = 7;
        static constexpr int MENU_LINE_SET_YEAR = 8;
        static constexpr int MENU_LINE_RUN_BOTTOM = 9;
        static constexpr int MENU_LINE_COUNT = 10;
        
        bool is_editable_line(int line) const
        {
            return line >= MENU_LINE_ALARM_ON_OFF && line <= MENU_LINE_SET_YEAR;
        }
        
        void process_menu(const hw::EncoderEvent& encoder_event)
        {
            // If menu is off and encoder is used turn menu on
            if (!state.menu_on)
            {
                state.menu_on = true;
                state.menu_line = MENU_LINE_RUN_TOP;
                state.menu_edit_mode = false;
                return;
            }
            
            // If menu is on
            if (state.menu_on)
            {
                if (encoder_event.pressed)
                {
                    if (state.menu_edit_mode)
                    {
                        // Exit edit mode
                        state.menu_edit_mode = false;
                    }
                    else if (state.menu_line == MENU_LINE_RUN_TOP || state.menu_line == MENU_LINE_RUN_BOTTOM)
                    {
                        // If on "run" line, exit menu
                        state.menu_on = false;
                        state.menu_edit_mode = false;
                    }
                    else if (is_editable_line(state.menu_line))
                    {
                        // Enter edit mode for editable lines
                        state.menu_edit_mode = true;
                    }
                }
                else
                {
                    // Encoder rotation
                    if (state.menu_edit_mode)
                    {
                        // Edit the value
                        edit_value(encoder_event.delta);
                    }
                    else
                    {
                        // Scroll menu with encoder delta
                        int new_line = static_cast<int>(state.menu_line) + encoder_event.delta;
                        
                        // Wrap around
                        if (new_line < 0)
                        {
                            new_line = MENU_LINE_COUNT - 1;
                        }
                        else if (new_line >= MENU_LINE_COUNT)
                        {
                            new_line = 0;
                        }
                        
                        state.menu_line = static_cast<uint8_t>(new_line);
                    }
                }
            }
        }
        
        void edit_value(int delta)
        {
            switch (state.menu_line)
            {
            case MENU_LINE_ALARM_ON_OFF:
                // Toggle alarm on/off with any rotation
                if (delta != 0)
                {
                    if (state.alarm_state == AlarmState::off)
                    {
                        state.alarm_state = AlarmState::on;
                    }
                    else
                    {
                        state.alarm_state = AlarmState::off;
                    }
                }
                break;
            case MENU_LINE_ALARM_HOUR:
                state.alarm_hour = wrap_value(static_cast<int>(state.alarm_hour), delta, 0, 9);
                break;
            case MENU_LINE_ALARM_MINUTE:
                state.alarm_minute = wrap_value(static_cast<int>(state.alarm_minute), delta, 0, 99);
                break;
            case MENU_LINE_SET_HOUR:
            {
                int new_val = wrap_value(static_cast<int>(state.time.hour), delta, 0, 9);
                state.time.hour = static_cast<uint32_t>(new_val);
                break;
            }
            case MENU_LINE_SET_MINUTE:
            {
                int new_val = wrap_value(static_cast<int>(state.time.minute), delta, 0, 99);
                state.time.minute = static_cast<uint32_t>(new_val);
                break;
            }
            case MENU_LINE_SET_DAY:
            {
                int new_val = wrap_value(static_cast<int>(state.time.day), delta, 0, 9);
                state.time.day = static_cast<uint32_t>(new_val);
                break;
            }
            case MENU_LINE_SET_MONTH:
            {
                int new_val = wrap_value(static_cast<int>(state.time.month), delta, 0, 12);
                state.time.month = static_cast<uint32_t>(new_val);
                break;
            }
            case MENU_LINE_SET_YEAR:
            {
                int new_val = wrap_value(static_cast<int>(state.time.year), delta, 0, 1023);
                state.time.year = static_cast<uint32_t>(new_val);
                break;
            }
            }
        }
        
        int wrap_value(int value, int delta, int min_val, int max_val)
        {
            int new_val = value + delta;
            int range = max_val - min_val + 1;
            
            // Wrap around when exceeding bounds
            while (new_val > max_val) new_val -= range;
            while (new_val < min_val) new_val += range;
            
            return new_val;
        }
        
        void maintain_alarm_state()
        {
            bool time_matches_alarm = (state.time.hour == state.alarm_hour && 
                                      state.time.minute == state.alarm_minute);
            
            switch (state.alarm_state)
            {
            case AlarmState::off:
                // Stay off
                break;
                
            case AlarmState::on:
                // If time matches alarm time, activate
                if (time_matches_alarm)
                {
                    state.alarm_state = AlarmState::active;
                }
                break;
                
            case AlarmState::active:
                // Stay active (cleared by encoder event)
                break;
                
            case AlarmState::cleared:
                // If time no longer matches alarm time, return to on
                if (!time_matches_alarm)
                {
                    state.alarm_state = AlarmState::on;
                }
                break;
            }
        }
    };

} // namespace rr
