#include "reveil.h"
#include <cstdio>

namespace rr {

    namespace debug
    {
        void print_encoder_event(const hw::EncoderEvent& event)
        {
            printf("[DEBUG] EncoderEvent: delta=%d, pressed=%s\n", 
                   event.delta, event.pressed ? "true" : "false");
        }

        void print_timer_event(const hw::TimerEvent& event)
        {
            // Convert timestamp to hours, minutes, seconds
            auto seconds_total = event.timestamp.time_since_epoch().count();
            int hours = (seconds_total / 3600) % 24;
            int minutes = (seconds_total / 60) % 60;
            int seconds = seconds_total % 60;
            
            printf("[DEBUG] TimerEvent: time=%02d:%02d:%02d\n", 
                   hours, minutes, seconds);
        }
    }

} // namespace rr
