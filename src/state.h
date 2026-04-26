/// State structure for the alarm clock
#pragma once

#include "rr_time.h"
#include <cstdint>

namespace rr
{

    enum class AlarmState : uint8_t
    {
        off = 0,
        on = 1,
        active = 2,
        cleared = 3
    };

    struct State
    {
        Time time{};

        uint8_t menu_line : 4 {0};         // 4 bits for menu line
        uint8_t menu_on : 1 {false};       // 1 bit for menu on/off
        AlarmState alarm_state {AlarmState::off}; // Alarm state
        uint8_t alarm_hour : 4 {0};        // 4 bits for alarm hour (0-9 decades)
        uint8_t alarm_minute : 5 {0};      // 5 bits for alarm minute (0-31)
    };

} // namespace rr
