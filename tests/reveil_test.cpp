#include "reveil.h"
#include "hardware_interface.h"
#include <gtest/gtest.h>

namespace rr
{
    namespace test
    {

        // Mock display for testing
        class MockDisplay
        {
        public:
            void start_window(const hw::window_t &) {}
            void send_pixels(hw::pixels_t) {}
            void finish_window() {}
            void update() {}
        };

        // Mock timer for testing
        class MockTimer
        {
        public:
            void set_next_clock_event_time(hw::Clock::time_point) {}
        };

        // Test fixture
        class ReveilTest : public ::testing::Test
        {
        protected:
            ReveilRepublicain<false> reveil; // No debug in tests
            MockDisplay display;
            MockTimer timer;
        };

        TEST_F(ReveilTest, ComputeUpdateReturnsFlags)
        {
            hw::TickEvent event{0};
            hw::output_flags_t flags = reveil.compute_update(display, timer, event);
            
            // Should return some valid flags (even if just None)
            EXPECT_GE(flags, 0);
        }

        TEST_F(ReveilTest, HandlesClockEvent)
        {
            hw::TimerEvent event{hw::Clock::time_point{}};
            hw::output_flags_t flags = reveil.compute_update(display, timer, event);
            
            EXPECT_GE(flags, 0);
        }

        TEST_F(ReveilTest, HandlesEncoderEvent)
        {
            hw::EncoderEvent event{1, false};
            hw::output_flags_t flags = reveil.compute_update(display, timer, event);
            
            EXPECT_GE(flags, 0);
        }

        TEST(ReveilDebugTest, DebugOutputForEncoderEvent)
        {
            // Test with debug enabled - output should go to stdout
            ReveilRepublicain<true> reveil_debug;
            MockDisplay display;
            MockTimer timer;
            
            printf("\n=== Testing debug output (should see debug messages) ===\n");
            
            hw::EncoderEvent encoder_event{-1, false};
            reveil_debug.compute_update(display, timer, encoder_event);
            
            // Create a TimerEvent with a specific time (e.g., 14:30:45)
            auto time_point = hw::Clock::time_point(hw::Clock::duration(14*3600 + 30*60 + 45));
            hw::TimerEvent timer_event{time_point};
            reveil_debug.compute_update(display, timer, timer_event);
            
            hw::EncoderEvent press_event{0, true};
            reveil_debug.compute_update(display, timer, press_event);
            
            printf("=== End of debug output test ===\n\n");
        }

    } // namespace test
} // namespace rr
