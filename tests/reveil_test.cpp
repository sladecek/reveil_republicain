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
            ReveilRepublicain reveil;
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
            hw::ClockEvent event{hw::Clock::time_point{}};
            hw::output_flags_t flags = reveil.compute_update(display, timer, event);
            
            EXPECT_GE(flags, 0);
        }

        TEST_F(ReveilTest, HandlesEncoderEvent)
        {
            hw::EncoderEvent event{1, false};
            hw::output_flags_t flags = reveil.compute_update(display, timer, event);
            
            EXPECT_GE(flags, 0);
        }

    } // namespace test
} // namespace rr
