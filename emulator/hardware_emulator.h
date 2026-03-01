#pragma once

#include "hardware_interface.h"
#include "reveil.h"
#include <array>
#include <optional>
#include <chrono>

namespace emulator
{

    class HardwareEmulator
    {
    public:
        static constexpr int DISPLAY_WIDTH = 200;
        static constexpr int DISPLAY_HEIGHT = 200;
        static constexpr rr::hw::BitsPerPixel BITS_PER_PIXEL = rr::hw::BitsPerPixel::b2;
        static constexpr int PIXELS_PER_BYTE = 8 / static_cast<int>(BITS_PER_PIXEL);

        HardwareEmulator(rr::ReveilRepublicain &reveil)
            : reveil_(reveil),
              awake_(true),
              beep_flag_(false),
              backlight_flag_(false),
              current_time_(rr::hw::Clock::time_point{}),
              next_alarm_time_(std::nullopt),
              tick_counter_(0)
        {
            // Initialize display buffer to black
            display_buffer_.fill(0x00); // All pixels black (00)
        }

        // Display interface implementation
        void start_window(const rr::hw::window_t &w)
        {
            current_window_ = w;
            window_pixel_index_ = 0;
        }

        void send_pixel(rr::hw::pixel_t pixel)
        {
            if (!current_window_.has_value())
                return;

            const auto &w = current_window_.value();

            // Each byte contains 4 pixels (2 bits each)
            for (int i = 0; i < PIXELS_PER_BYTE; ++i)
            {
                int pixel_in_window = window_pixel_index_++;
                if (pixel_in_window >= w.width * w.height)
                    break;

                int local_x = pixel_in_window % w.width;
                int local_y = pixel_in_window / w.width;
                int global_x = w.x + local_x;
                int global_y = w.y + local_y;

                if (global_x < DISPLAY_WIDTH && global_y < DISPLAY_HEIGHT)
                {
                    int buffer_index = global_y * DISPLAY_WIDTH + global_x;
                    // Extract 2 bits for this pixel (from MSB to LSB)
                    int shift = 6 - (i * 2);
                    rr::hw::pixel_t pixel_value = (pixel >> shift) & 0x03;
                    display_buffer_[buffer_index] = pixel_value;
                }
            }
        }

        void finish_window()
        {
            current_window_ = std::nullopt;
        }

        void update()
        {
            // Display update is handled by rendering in ImGui
        }

        // Timer interface implementation
        void set_next_clock_event_time(rr::hw::Clock::time_point time)
        {
            next_alarm_time_ = time;
        }

        // Get pixel color for rendering (returns 2-bit value: 00, 01, 10, 11)
        rr::hw::pixel_t get_pixel(int x, int y) const
        {
            if (x < 0 || x >= DISPLAY_WIDTH || y < 0 || y >= DISPLAY_HEIGHT)
                return 0;
            return display_buffer_[y * DISPLAY_WIDTH + x];
        }

        // Convert 2-bit pixel value to RGB color
        void get_pixel_color(rr::hw::pixel_t pixel, float &r, float &g, float &b) const
        {
            switch (pixel & 0x03)
            {
            case 0x00: // Black
                r = 0.0f;
                g = 0.0f;
                b = 0.0f;
                break;
            case 0x01: // White
                r = 1.0f;
                g = 1.0f;
                b = 1.0f;
                break;
            case 0x02: // Yellow
                r = 1.0f;
                g = 1.0f;
                b = 0.0f;
                break;
            case 0x03: // Red
                r = 1.0f;
                g = 0.0f;
                b = 0.0f;
                break;
            }
        }

        // Handle encoder button presses
        void handle_encoder_plus()
        {
            rr::hw::EncoderEvent event{1, false};
            process_event(event);
        }

        void handle_encoder_minus()
        {
            rr::hw::EncoderEvent event{-1, false};
            process_event(event);
        }

        void handle_encoder_press()
        {
            rr::hw::EncoderEvent event{0, true};
            process_event(event);
        }

        // Handle tick events (called every second when awake)
        void handle_tick()
        {
            if (awake_)
            {
                rr::hw::TickEvent event{tick_counter_++};
                process_event(event);
            }
        }

        // Update time and check for alarms
        void update_time(rr::hw::Clock::time_point new_time)
        {
            auto old_time = current_time_;
            current_time_ = new_time;

            // Check if alarm should trigger
            if (next_alarm_time_.has_value() &&
                old_time < next_alarm_time_.value() &&
                current_time_ >= next_alarm_time_.value())
            {
                rr::hw::ClockEvent event{current_time_};
                process_event(event);
            }
        }

        // Getters for UI state
        bool is_awake() const { return awake_; }
        bool is_beeping() const { return beep_flag_; }
        bool is_backlight_on() const { return backlight_flag_; }
        rr::hw::Clock::time_point get_current_time() const { return current_time_; }
        std::optional<rr::hw::Clock::time_point> get_next_alarm() const { return next_alarm_time_; }

        // Get countdown to next alarm in seconds
        std::optional<int64_t> get_countdown_seconds() const
        {
            if (!next_alarm_time_.has_value())
                return std::nullopt;

            auto diff = next_alarm_time_.value() - current_time_;
            return std::chrono::duration_cast<std::chrono::seconds>(diff).count();
        }
        
        // Get current tick counter
        int get_tick_counter() const { return tick_counter_; }
        
        // Process output flags from compute_update
        void process_output_flags(rr::hw::output_flags_t flags)
        {
            beep_flag_ = (flags & static_cast<rr::hw::output_flags_t>(rr::hw::OutputFlags::Beep)) != 0;
            backlight_flag_ = (flags & static_cast<rr::hw::output_flags_t>(rr::hw::OutputFlags::Backlight)) != 0;

            bool sleep_flag = (flags & static_cast<rr::hw::output_flags_t>(rr::hw::OutputFlags::Sleep)) != 0;
            if (sleep_flag)
            {
                awake_ = false;
            }
            else
            {
                awake_ = true;
            }
        }

    private:
        void process_event(const rr::hw::Event &event)
        {
            rr::hw::output_flags_t flags = reveil_.compute_update(*this, *this, event);

            // Process output flags
            beep_flag_ = (flags & static_cast<rr::hw::output_flags_t>(rr::hw::OutputFlags::Beep)) != 0;
            backlight_flag_ = (flags & static_cast<rr::hw::output_flags_t>(rr::hw::OutputFlags::Backlight)) != 0;

            bool sleep_flag = (flags & static_cast<rr::hw::output_flags_t>(rr::hw::OutputFlags::Sleep)) != 0;
            if (sleep_flag)
            {
                awake_ = false;
            }
            else
            {
                awake_ = true;
            }
        }

        rr::ReveilRepublicain &reveil_;
        std::array<rr::hw::pixel_t, DISPLAY_WIDTH * DISPLAY_HEIGHT> display_buffer_;
        std::optional<rr::hw::window_t> current_window_;
        int window_pixel_index_;

        bool awake_;
        bool beep_flag_;
        bool backlight_flag_;
        rr::hw::Clock::time_point current_time_;
        std::optional<rr::hw::Clock::time_point> next_alarm_time_;
        int tick_counter_;
    };

} // namespace emulator
