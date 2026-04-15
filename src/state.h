/// State structure for the alarm clock
#pragma once

#include "rr_time.h"
#include <cstdint>

namespace rr
{

    struct State
    {
        Time time{};

        uint8_t menu_line : 4 {0};         // 4 bits for menu line
        uint8_t menu_on : 1 {false};       // 1 bit for menu on/off
        uint8_t alarm_active : 1 {false};  // 1 bit for alarm active
        uint8_t alarm_cleared : 1 {false}; // 1 bit for alarm cleared
        uint8_t alarm_hour : 4 {0};        // 4 bits for alarm hour (0-9 decades)
        uint8_t alarm_minute : 5 {0};      // 5 bits for alarm minute (0-31)
    };

} // namespace rr
