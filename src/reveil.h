#pragma once

#include "hardware_interface.h"
#include "renderer.h"
#include "concrete_fonts.h"

#include <concepts>
#include <variant>

namespace rr
{

    class ReveilRepublicain
    {
    public:
        ReveilRepublicain() : current_color_(0) {}
        
        template <hw::Display D, hw::Timer T>
        hw::output_flags_t compute_update(D &display, T &timer, const hw::Event &event)
        {
            // Handle clock events - cycle colors every second
            if (std::holds_alternative<hw::ClockEvent>(event))
            {
                const auto& clock_event = std::get<hw::ClockEvent>(event);
                
                // Create a renderer for the full display
                hw::window_t full_window{0, 0, 200, 200};
                ui::NormalFont font;
                ui::Renderer<hw::BitsPerPixel::b2, D, ui::NormalFont> renderer(display, full_window, font);
                
                // Cycle through colors: 0 (black), 1 (white), 2 (yellow), 3 (red)
                current_color_ = (current_color_ + 1) % 4;
                renderer.fill(current_color_);
                
                display.update();
            }
            
            return static_cast<hw::output_flags_t>(hw::OutputFlags::None);
        }
        
    private:
        hw::color_t current_color_;
    };

} // namespace rr
