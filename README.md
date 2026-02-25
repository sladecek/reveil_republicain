# Reveil Republicain

A C++ project demonstrating CMake, Clang, Google Test, and ImGui integration.

## References

- https://quantum5.ca/2022/03/09/art-of-time-keeping-part-4-french-republican-calendar/
- https://github.com/Mubelotix/calendrier?tab=readme-ov-file

## Project Structure

```
reveil_republicain/
├── CMakeLists.txt          # Root CMake configuration
├── src/                    # Source code
│   ├── CMakeLists.txt
│   ├── reveil.h            # Library header
│   └── reveil.cpp          # Library implementation
├── tests/                  # Test code
│   ├── CMakeLists.txt
│   └── reveil_test.cpp     # Unit tests
└── emulator/               # ImGui GUI application
    ├── CMakeLists.txt
    └── main.cpp            # Emulator application
```

## Prerequisites

- CMake (>= 3.14)
- Clang compiler
- Git (for fetching dependencies)
- OpenGL development libraries
- X11 development libraries (Linux):
  ```bash
  sudo apt-get install libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev
  ```

## Building the Project

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build
cmake --build . -j$(nproc)
```

## Running Tests

```bash
# From the build directory
ctest --output-on-failure

# Or run the test executable directly
./tests/reveil_tests
```

## Running the Emulator

The emulator is an ImGui-based graphical application that simulates the Republican Alarm Clock hardware:

```bash
# From the build directory
./emulator/emulator
```

### Emulator Features

The emulator provides a complete hardware simulation:

**Display (200x200 pixels)**
- 2-bit color display showing 4 colors:
  - `00` - Black
  - `01` - White
  - `10` - Yellow
  - `11` - Red
- Real-time rendering of the device screen

**Encoder Controls**
- **➕ Plus**: Increment encoder (delta = +1)
- **➖ Minus**: Decrement encoder (delta = -1)
- **⏺ Press**: Press the encoder button

**Status Display**
- Current time (HH:MM:SS format)
- Alarm countdown timer
- Awake/Sleeping state indicator
- 🔊 Beep indicator when alarm is triggered
- Backlight state (changes background color)

**Timing**
- Real-time clock simulation (1 real second = 1 simulated second)
- Tick events sent every second when device is awake
- Alarm triggering when countdown reaches zero

**Hardware Interface Implementation**
- The emulator implements both the `Display` and `Timer` concepts from `hardware_interface.h`
- Sends appropriate events (ClockEvent, EncoderEvent, TickEvent) to the ReveilRepublicain instance
- Processes output flags (Beep, Sleep, Backlight) and updates UI accordingly

## Library Features

The `reveil` library provides:

- **Hardware abstraction layer**: Concepts for Display and Timer interfaces
- **Event system**: ClockEvent, EncoderEvent, TickEvent
- **Output flags**: Beep, Sleep, Backlight control
- **ReveilRepublicain class**: Main alarm clock logic (ready for implementation)

## Example Usage

```cpp
#include "reveil.h"
#include <iostream>

int main() {
    reveil::Calculator calc;
    std::cout << "2 + 3 = " << calc.add(2, 3) << std::endl;
    std::cout << reveil::greet("Developer") << std::endl;
    return 0;
}
```

## Architecture

### Hardware Interface

The project uses C++20 concepts to define hardware interfaces:

```cpp
template <typename T>
concept Display = requires(T display, const window_t &w, pixel_t pixel) {
    { display.start_window(w) } -> std::same_as<void>;
    { display.send_pixel(pixel) } -> std::same_as<void>;
    { display.finish_window() } -> std::same_as<void>;
    { display.update() } -> std::same_as<void>;
};

template <typename T>
concept Timer = requires(T timer, Clock::time_point time) {
    { timer.set_next_clock_event_time(time) } -> std::same_as<void>;
};
```

This allows the same `ReveilRepublicain` code to work with both real hardware and the emulator.

## References

- [French Republican Calendar](https://quantum5.ca/2022/03/09/art-of-time-keeping-part-4-french-republican-calendar/)
- [Calendrier Implementation](https://github.com/Mubelotix/calendrier?tab=readme-ov-file)
- [Arduino Rotary Encoder](https://www.instructables.com/A-Complete-Arduino-Rotary-Solution/)

## License

MIT License


MIT License
