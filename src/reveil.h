// Main class for the French Calender Alarm Clock

#pragma once

#include "hardware_interface.h"
#include "renderer.h"
#include "generated/concrete_fonts.h"
#include "time_painter.h"
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
            
            // Handle timer events - update time display
            if (std::holds_alternative<hw::TimerEvent>(event))
            {
                const auto& timer_event = std::get<hw::TimerEvent>(event);
                
                // Unpack current time from timer event
                Time current_time(timer_event.timestamp);
                
                // Create fonts
                ui::NormalFont normal_font;
                ui::BigFont big_font;
                
                // Create time painter and update display
                ui::TimePainter<D, ui::NormalFont, ui::BigFont> painter(display, normal_font, big_font);
                painter.update(current_time);
                
                // Timer events are sent only on initialization or when explicitly requested
                // No automatic rescheduling here
            }
            
            return static_cast<hw::output_flags_t>(hw::OutputFlags::None);
        }
        private:
        State state{};
    };

} // namespace rr
