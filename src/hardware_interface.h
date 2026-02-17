// Hardware interface for the republican alarm clock. 
// The interface will be used both by the real hardware and the simulator.

#pragma once

#include <chrono>
#include <concepts>
#include <cstdint>  
#include <type_traits>  
#include <variant>
#include <optional>

namespace  rr::hw {

    template <typename T>
    concept Display = requires(T display, std::uint8_t byte) {
        { display.init_transfer() } -> std::same_as<void>;
        { display.send_pixels(byte) } -> std::same_as<void>;
        { display.finish_transfer() } -> std::same_as<void>;
    };

    struct Clock {
        using rep = std::uint32_t;
        using period = std::ratio<1>;
        using duration = std::chrono::duration<rep, period>;
        using time_point = std::chrono::time_point<Clock>;
        static constexpr bool is_steady = true;
    };

    struct ClockEvent {
        Clock::time_point timestamp{};
    };

    struct EncoderEvent {
        int delta{}; // Change in encoder position
        bool pressed{}; // Whether the encoder button is pressed
    };

    using Event = std::variant<ClockEvent, EncoderEvent>;

    template <typename T>
    concept EventSource = requires(T source) {
        { source.poll_event() } -> std::same_as<std::optional<Event>>;
    };

    template <typename T>
    concept Interface = Display<T> && EventSource<T>;

} // namespace rr::hw