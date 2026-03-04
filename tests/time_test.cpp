#include "rr_time.h"

#include <gtest/gtest.h>
#include <chrono>

namespace rr::test
{

    TEST(TimeTest, ConstructFromTimePoint)
    {
        // Test construction from a Unix timestamp
        // Using a known timestamp (March 4, 2026, 12:00:00 UTC in Gregorian calendar)
        // The Time struct should convert this to Republican calendar with decimal time
        
        // Using system_clock to create a specific timestamp
        std::tm tm = {};
        tm.tm_year = 2026 - 1900;  // years since 1900
        tm.tm_mon = 3 - 1;          // 0-based months (March)
        tm.tm_mday = 4;             // day of month
        tm.tm_hour = 12;            // hour (Gregorian 24h time)
        tm.tm_min = 0;              // minute
        tm.tm_sec = 0;              // second
        tm.tm_isdst = -1;           // auto-detect DST
        
        std::time_t time = std::mktime(&tm);
        auto sys_time = std::chrono::system_clock::from_time_t(time);
        
        // Convert to hw::Clock::time_point
        auto duration = std::chrono::duration_cast<hw::Clock::duration>(
            sys_time.time_since_epoch()
        );
        hw::Clock::time_point time_point(duration);
        
        // Construct Time from time_point
        Time t(time_point);
        
        // Verify that fields are within valid ranges for Republican calendar
        EXPECT_GE(t.second, 0);
        EXPECT_LT(t.second, 100);    // 0-99 decimal seconds
        EXPECT_GE(t.minute, 0);
        EXPECT_LT(t.minute, 100);    // 0-99 decimal minutes
        EXPECT_GE(t.hour, 0);
        EXPECT_LT(t.hour, 10);       // 0-9 decimal hours
        EXPECT_GE(t.day, 1);
        EXPECT_LE(t.day, 30);        // 1-30 days per month
        EXPECT_GE(t.decade, 0);
        EXPECT_LE(t.decade, 2);      // 0-2 decades per month
        EXPECT_GE(t.month, 1);
        EXPECT_LE(t.month, 13);      // 1-12 months + complementary days
        EXPECT_GE(t.year, 0);        // Year since Republican era
    }

    TEST(TimeTest, PackAndUnpack)
    {
        // Create a time_point
        hw::Clock::time_point original(hw::Clock::duration(1000000));
        
        // Construct Time, then pack back
        Time t(original);
        hw::Clock::time_point repacked = t.pack();
        
        // The repacked time should be close to the original
        // May differ due to:
        // - Conversion between Gregorian and Republican calendars
        // - Rounding in decimal time conversion
        // - Loss of sub-second precision
        auto diff = std::abs(
            static_cast<int64_t>(repacked.time_since_epoch().count()) -
            static_cast<int64_t>(original.time_since_epoch().count())
        );
        
        // Should be within reasonable tolerance (a few decimal seconds)
        // 1 decimal second = 0.864 Gregorian seconds
        EXPECT_LT(diff, 100);  // Allow up to 100 Gregorian seconds tolerance
    }

    TEST(TimeTest, ComputeNextMinuteChange)
    {
        // Create a time_point at some point during a decimal minute
        std::tm tm = {};
        tm.tm_year = 2026 - 1900;
        tm.tm_mon = 3 - 1;
        tm.tm_mday = 4;
        tm.tm_hour = 12;
        tm.tm_min = 0;
        tm.tm_sec = 45;              // 45 Gregorian seconds into the minute
        tm.tm_isdst = -1;
        
        std::time_t time = std::mktime(&tm);
        auto sys_time = std::chrono::system_clock::from_time_t(time);
        auto duration = std::chrono::duration_cast<hw::Clock::duration>(
            sys_time.time_since_epoch()
        );
        hw::Clock::time_point time_point(duration);
        
        Time t(time_point);
        hw::Clock::time_point next_minute = t.compute_next_minute_change();
        
        // Next decimal minute should occur in the future
        EXPECT_GT(next_minute.time_since_epoch().count(),
                  time_point.time_since_epoch().count());
        
        // The difference should be less than one decimal minute
        // 1 decimal minute = 86.4 Gregorian seconds
        auto diff = next_minute.time_since_epoch().count() - 
                    time_point.time_since_epoch().count();
        EXPECT_GT(diff, 0);
        EXPECT_LE(diff, 87);  // Should be at most one decimal minute (86.4s + rounding)
    }

    TEST(TimeTest, DayOfYear)
    {
        // Test day of year calculation
        std::tm tm = {};
        tm.tm_year = 2026 - 1900;
        tm.tm_mon = 1 - 1;  // January
        tm.tm_mday = 1;
        tm.tm_hour = 0;
        tm.tm_min = 0;
        tm.tm_sec = 0;
        tm.tm_isdst = -1;
        
        std::time_t time = std::mktime(&tm);
        auto sys_time = std::chrono::system_clock::from_time_t(time);
        auto duration = std::chrono::duration_cast<hw::Clock::duration>(
            sys_time.time_since_epoch()
        );
        hw::Clock::time_point time_point(duration);
        
        Time t(time_point);
        
        // Day of year should be: month * 30 + decade * 10 + day
        int expected = t.month * 30 + t.decade * 10 + t.day;
        EXPECT_EQ(t.day_of_year(), expected);
        
        // For complementary days (month == 12), it should be 360 + day
        // Create a test time for the last day of the Republican year
        std::tm tm2 = {};
        tm2.tm_year = 2025 - 1900;
        tm2.tm_mon = 9 - 1;  // September
        tm2.tm_mday = 21;    // Just before new year
        tm2.tm_hour = 23;
        tm2.tm_min = 59;
        tm2.tm_sec = 0;
        tm2.tm_isdst = -1;
        
        std::time_t time2 = std::mktime(&tm2);
        auto sys_time2 = std::chrono::system_clock::from_time_t(time2);
        auto duration2 = std::chrono::duration_cast<hw::Clock::duration>(
            sys_time2.time_since_epoch()
        );
        hw::Clock::time_point time_point2(duration2);
        Time complementary(time_point2);
        
        // This should be near the end of the year (month 11 or complementary days)
        if (complementary.month == 12) {
            // Complementary days: 360 + day
            EXPECT_EQ(complementary.day_of_year(), 360 + complementary.day);
        } else {
            // Regular month
            EXPECT_EQ(complementary.day_of_year(), 
                      complementary.month * 30 + complementary.decade * 10 + complementary.day);
        }
    }

    TEST(TimeTest, RoundTripConsistency)
    {
        // Test that pack(Time(tp)) ≈ tp
        // Use the epoch of Republican calendar for a known good case
        std::tm tm = {};
        tm.tm_year = 2025 - 1900;
        tm.tm_mon = 9 - 1;  // September
        tm.tm_mday = 22;    // Around autumn equinox
        tm.tm_hour = 12;
        tm.tm_min = 0;
        tm.tm_sec = 0;
        tm.tm_isdst = -1;
        
        std::time_t time = std::mktime(&tm);
        auto sys_time = std::chrono::system_clock::from_time_t(time);
        auto duration = std::chrono::duration_cast<hw::Clock::duration>(
            sys_time.time_since_epoch()
        );
        hw::Clock::time_point original(duration);
        
        Time t(original);
        hw::Clock::time_point repacked = t.pack();
        
        // The repacked time should be close to the original
        // Allow some tolerance for rounding in decimal time conversion
        auto diff = std::abs(
            static_cast<int64_t>(repacked.time_since_epoch().count()) -
            static_cast<int64_t>(original.time_since_epoch().count())
        );
        
        // Should be within a few seconds (decimal time rounding)
        EXPECT_LT(diff, 2);  // Allow up to 2 seconds difference
    }

    TEST(TimeTest, DecimalTimeConversion)
    {
        // Test that decimal time is properly calculated
        // Noon in standard time should be around 5:00:00 in decimal time
        // (12h / 24h) * 10 = 5 decimal hours
        std::tm tm = {};
        tm.tm_year = 2025 - 1900;
        tm.tm_mon = 9 - 1;
        tm.tm_mday = 22;
        tm.tm_hour = 12;  // Noon standard time
        tm.tm_min = 0;
        tm.tm_sec = 0;
        tm.tm_isdst = -1;
        
        std::time_t time = std::mktime(&tm);
        auto sys_time = std::chrono::system_clock::from_time_t(time);
        auto duration = std::chrono::duration_cast<hw::Clock::duration>(
            sys_time.time_since_epoch()
        );
        hw::Clock::time_point time_point(duration);
        
        Time t(time_point);
        
        // At noon standard time (with Paris +1h = 13:00), decimal time should be:
        // (13 * 3600) / 86400 * 100000 = 54166.67 decimal units
        // = 5 hours, 41 minutes, 66 seconds (approximately)
        EXPECT_GE(t.hour, 4);
        EXPECT_LE(t.hour, 6);  // Should be around 5
    }

    TEST(TimeTest, NextMinuteChangeIsAccurate)
    {
        // Create a time at a specific decimal time
        std::tm tm = {};
        tm.tm_year = 2025 - 1900;
        tm.tm_mon = 9 - 1;
        tm.tm_mday = 22;
        tm.tm_hour = 12;
        tm.tm_min = 0;
        tm.tm_sec = 0;
        tm.tm_isdst = -1;
        
        std::time_t time = std::mktime(&tm);
        auto sys_time = std::chrono::system_clock::from_time_t(time);
        auto duration = std::chrono::duration_cast<hw::Clock::duration>(
            sys_time.time_since_epoch()
        );
        hw::Clock::time_point time_point(duration);
        
        Time t(time_point);
        hw::Clock::time_point next = t.compute_next_minute_change();
        
        // The time at next minute should have second = 0 and minute = original + 1
        Time t_next(next);
        EXPECT_EQ(t_next.second, 0);
        EXPECT_EQ(t_next.minute, (t.minute + 1) % 100);
        
        // If minute wrapped, hour should increment
        if (t.minute == 99) {
            EXPECT_EQ(t_next.hour, (t.hour + 1) % 10);
        }
    }

} // namespace rr::test
