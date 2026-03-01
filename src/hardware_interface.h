// Hardware interface for the republican alarm clock.
// The interface will be used both by the real hardware and the simulator.

#pragma once

#include <chrono>
#include <concepts>
#include <cstdint>
#include <type_traits>
#include <variant>
#include <optional>

namespace rr::hw
{


    enum class BitsPerPixel: uint8_t
    {
        b1 = 1,
        b2 = 2,
        b4 = 4,
        b8 = 8
    };

    using pixel_t = std::uint8_t;
    using color_t = std::uint8_t;
    using x_t = std::uint8_t;
    using y_t = std::uint16_t;

    struct window_t
    {
        x_t x;
        y_t y;
        x_t width;
        y_t height;
    };

    template <typename T>
    concept Display = requires(T display, const window_t &w, pixel_t pixel) {
        { display.start_window(w) } -> std::same_as<void>;
        { display.send_pixel(pixel) } -> std::same_as<void>;
        { display.finish_window() } -> std::same_as<void>;
        { display.update() } -> std::same_as<void>;
    };


    struct Clock
    {
        using rep = std::uint32_t;
        using period = std::ratio<1>;
        using duration = std::chrono::duration<rep, period>;
        using time_point = std::chrono::time_point<Clock>;
        static constexpr bool is_steady = true;
    };

    template <typename T>
    concept Timer = requires(T timer, Clock::time_point time) {
        { timer.set_next_clock_event_time(time) } -> std::same_as<void>;
    };
  
    // Clock events sent to the update function when the reaches a new time point.
    // The event can wake the system up if it is asleep.
    struct ClockEvent
    {
        Clock::time_point timestamp{};
    };

    // Encoder events sent to the update function when the encoder is turned or pressed.
    // The events wake the system up if it is asleep, and are used to navigate the menu and set the alarm.
    struct EncoderEvent
    {
        int delta{};    // Change in encoder position
        bool pressed{}; // Whether the encoder button is pressed
    };

    // Quick ticks sent to the update function when the display is awake.
    struct TickEvent
    {
        int counter{}; // Tick counter, incremented on each tick
    };

    using Event = std::variant<ClockEvent, EncoderEvent, TickEvent>;

    using output_flags_t = std::uint8_t;
    enum class OutputFlags : output_flags_t
    {
        None = 0,
        Beep = 1 << 0,
        Sleep = 1 << 1,
        Backlight = 1 << 2,
    };

} // namespace rr::hw