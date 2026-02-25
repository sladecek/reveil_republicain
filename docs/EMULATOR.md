# Hardware Emulator Implementation

## Overview

This document describes the hardware emulator implementation for the Reveil Republicain (Republican Alarm Clock) project.

## Components

### 1. HardwareEmulator Class (`emulator/hardware_emulator.h`)

The `HardwareEmulator` class implements both the `Display` and `Timer` concepts defined in `hardware_interface.h`.

#### Display Implementation

- **Resolution**: 200x200 pixels
- **Color depth**: 2 bits per pixel (4 colors)
  - `00` - Black
  - `01` - White  
  - `10` - Yellow
  - `11` - Red
- **Buffer**: Internal array storing all pixel data
- **Methods**:
  - `start_window(window_t)` - Begin drawing to a specific window region
  - `send_pixel(pixel_t)` - Send a byte containing 4 pixels (2 bits each)
  - `finish_window()` - Complete window drawing
  - `update()` - Trigger display refresh

#### Timer Implementation

- **Clock**: Custom clock with 1-second resolution
- **Methods**:
  - `set_next_clock_event_time(time_point)` - Set when the next alarm should trigger
- **Functionality**: Automatically sends `ClockEvent` when the alarm time is reached

#### Event Handling

The emulator can send three types of events to the `ReveilRepublicain` instance:

1. **ClockEvent** - Sent when alarm time is reached
2. **EncoderEvent** - Sent when encoder buttons are pressed
   - Plus button: delta = +1
   - Minus button: delta = -1
   - Press button: pressed = true
3. **TickEvent** - Sent every second when device is awake

#### Output Flag Processing

After each event, the emulator processes output flags returned by `compute_update()`:

- **Beep** (`0x01`) - Displays speaker icon in UI
- **Sleep** (`0x02`) - Puts device to sleep (stops tick events)
- **Backlight** (`0x04`) - Changes background color

### 2. GUI Implementation (`emulator/main.cpp`)

The ImGui-based interface provides:

#### Status Display
- Current time (HH:MM:SS)
- Alarm countdown
- Wake/Sleep state
- Beep indicator (🔊)

#### Controls
- Three buttons simulating rotary encoder:
  - ➖ Minus
  - ⏺ Press
  - ➕ Plus

#### Display Rendering
- 200x200 pixel grid
- Each pixel rendered as 2x2 screen pixels (400x400 display area)
- Real-time color mapping from 2-bit values to RGB

#### Timing
- Real-time clock updates every second
- Tick events sent when awake
- Background color changes based on backlight state

## Architecture Benefits

1. **Concept-based design**: The same `ReveilRepublicain` class works with both emulator and real hardware
2. **Zero-overhead abstraction**: Templates ensure no runtime cost
3. **Testability**: Easy to create mock implementations for unit tests
4. **Visual feedback**: ImGui provides immediate visual feedback during development

## Usage Example

```cpp
// Create the alarm clock instance
rr::ReveilRepublicain reveil;

// Create hardware emulator
emulator::HardwareEmulator hardware(reveil);

// Simulate encoder press
hardware.handle_encoder_plus();

// Update time
auto time = rr::hw::Clock::time_point(rr::hw::Clock::duration(100));
hardware.update_time(time);

// Send tick
hardware.handle_tick();

// Check state
bool awake = hardware.is_awake();
bool beeping = hardware.is_beeping();
```

## Future Enhancements

1. Add keyboard shortcuts for encoder controls
2. Implement faster time simulation mode
3. Add debug overlay showing internal state
4. Sound effects for beep flag
5. Save/load alarm settings
6. Multiple alarm support visualization
