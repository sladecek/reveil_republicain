// Time representation with packed fields for the republican alarm clock.

#include "rr_time.h"
#include <chrono>
#include <ctime>
#include <algorithm>

namespace rr
{

    Time::Time(hw::Clock::time_point time_point)
    {
        // Convert time_point UTC to Paris time
        constexpr int longitude_of_paris_observatory_s = 561;
        auto paris_seconds = time_point.time_since_epoch().count() + longitude_of_paris_observatory_s;
        
        // Extract days and SI seconds in the day
        int si_seconds_in_day = paris_seconds % 86400;
        int days_since_epoch = paris_seconds / 86400;
        
        // Find julian day in the table of years
        int jd = hw::Clock::jd_zero + days_since_epoch;
        int jd_offset = jd - JD_ZERO;
        
        // Handle overflow by wrapping (incorrect but viable)
        int max_jd_offset = first_day_jd[YEAR_COUNT - 1];
        if (jd_offset < 0 || jd_offset > max_jd_offset + 365) {
            jd_offset = ((jd_offset % (max_jd_offset + 365)) + (max_jd_offset + 365)) % (max_jd_offset + 365);
        }
        
        // Binary search to find the year
        auto it = std::upper_bound(first_day_jd.begin(), first_day_jd.end(), jd_offset);
        if (it == first_day_jd.begin()) {
            // Before first year in table, use first year
            year = FIRST_YEAR;
            it = first_day_jd.begin() + 1;
        }
        --it;  // Go back to the year that starts before or at this JD
        int year_index = it - first_day_jd.begin();
        year = FIRST_YEAR + year_index;
        
        // Subtract year start to get day of year
        int day_of_year_val = jd_offset - *it;
        
        // Compute month, decade, and day
        // Works for regular months (0-11) and complementary days (month=12)
        month = day_of_year_val / 30;
        int day_of_month = day_of_year_val % 30;
        decade = day_of_month / 10;
        day = day_of_month % 10;
        
        // Convert SI seconds to decimal time
        // Total decimal time units in a day = 100000 (10h * 100m * 100s)
        // SI seconds in a day = 86400
        // Use int64_t to avoid overflow
        int decimal_units = (static_cast<int64_t>(si_seconds_in_day) * 100000) / 86400;
        
        hour = decimal_units / 10000;
        int remainder = decimal_units % 10000;
        minute = remainder / 100;
        second = remainder % 100;
    }

    hw::Clock::time_point Time::pack() const
    {
        // Get JD offset for the start of this Republican year
        int year_index = year - FIRST_YEAR;
        if (year_index < 0 || year_index >= YEAR_COUNT) {
            // Out of range, return epoch
            return hw::Clock::time_point{};
        }
        
        int jd_offset = first_day_jd[year_index];
        
        // Add day of year
        jd_offset += day_of_year();
        
        // Convert to JD
        int jd = JD_ZERO + jd_offset;
        
        // Convert to days since epoch
        int days_since_epoch = jd - hw::Clock::jd_zero;
        
        // Convert decimal time to SI seconds
        // decimal_units = hour * 10000 + minute * 100 + second
        // Use int64_t to avoid overflow and add rounding
        int decimal_units = hour * 10000 + minute * 100 + second;
        int si_seconds_in_day = (static_cast<int64_t>(decimal_units) * 86400 + 50000) / 100000;
        
        // Combine Paris time
        int paris_seconds = days_since_epoch * 86400 + si_seconds_in_day;
        
        // Subtract 1 hour to convert from Paris to UTC
        int utc_seconds = paris_seconds - 3600;
        
        return hw::Clock::time_point(hw::Clock::duration(utc_seconds));
    }

    hw::Clock::time_point Time::compute_next_minute_change() const
    {
        // Set second to 0 and pack to get current minute boundary
        Time current_minute = *this;
        current_minute.second = 0;
        auto current_time = current_minute.pack();
        
        // Add one decimal minute in SI seconds (86400 / 1000 = 86.4 seconds)
        // Round to 87 seconds to ensure we move to the next minute
        auto next_minute = current_time + hw::Clock::duration(87);
        
        return next_minute;
    }

    int Time::day_of_year() const
    {
        if (month == 12) {
            // Complementary days
            return 360 + day;
        }
        return month * 30 + decade * 10 + day;
    }

} // namespace rr
