#pragma once

#include "hardware_interface.h"
#include "renderer.h"
#include "concrete_fonts.h"
#include "time_painter.h"
#include "rr_time.h"

#include <concepts>
#include <variant>

namespace rr
{

    class ReveilRepublicain
    {
    public:
        ReveilRepublicain() {}
        
        template <hw::Display D, hw::Timer T>
        hw::output_flags_t compute_update(D &display, T &timer, const hw::Event &event)
        {
            // Handle clock events - update time display
            if (std::holds_alternative<hw::ClockEvent>(event))
            {
                const auto& clock_event = std::get<hw::ClockEvent>(event);
                
                // Unpack current time from clock event
                Time current_time(clock_event.timestamp);
                
                // Create fonts
                ui::NormalFont normal_font;
                ui::BigFont big_font;
                
                // Create time painter and update display
                ui::TimePainter<D, ui::NormalFont, ui::BigFont> painter(display, normal_font, big_font);
                painter.update(current_time);
            }
            
            return static_cast<hw::output_flags_t>(hw::OutputFlags::None);
        }
    };

} // namespace rr
