#pragma once

#include "hardware_interface.h"
#include "reveil.h"
#include <array>
#include <optional>

namespace stm32
{

/// STM32 hardware implementation of the Display and Timer concepts.
template<typename ReveilType>
class Stm32Hardware
{
public:
    static constexpr int DISPLAY_WIDTH = 200;
    static constexpr int DISPLAY_HEIGHT = 200;
    static constexpr rr::hw::BitsPerPixel BITS_PER_PIXEL = rr::hw::BitsPerPixel::b2;
    static constexpr int PIXELS_PER_BYTE = 8 / static_cast<int>(BITS_PER_PIXEL);

    Stm32Hardware(ReveilType &reveil);

    // -- Display interface -------------------------------------------------------
    void start_window(const rr::hw::window_t &w);
    void send_pixels(rr::hw::pixels_t pixel);
    void finish_window();
    void update();

    // -- Timer interface ---------------------------------------------------------
    void set_next_clock_event_time(rr::hw::Clock::time_point time);

    // -- Event / output processing -----------------------------------------------
    void process_event(const rr::hw::Event &event);
    void process_output_flags(rr::hw::output_flags_t flags);

private:
    ReveilType &reveil;
    std::array<rr::hw::pixels_t, DISPLAY_WIDTH * DISPLAY_HEIGHT> display_buffer;
    std::optional<rr::hw::window_t> current_window;
    int window_pixel_index;
};

// -- Template implementations (TODO stubs) -----------------------------------

template<typename ReveilType>
Stm32Hardware<ReveilType>::Stm32Hardware(ReveilType &reveil)
    : reveil(reveil),
      display_buffer{},
      current_window(std::nullopt),
      window_pixel_index(0)
{
    // TODO: Initialize display buffer to black (all pixels 0x00)
    // TODO: Initialize GPIO for EPD (SPI pins, DC, RST, BUSY)
    // TODO: Initialize GPIO for buzzer / backlight / encoder
    // TODO: Initialize RTC for timekeeping
}

template<typename ReveilType>
void Stm32Hardware<ReveilType>::start_window(const rr::hw::window_t &w)
{
    // TODO: Configure EPD window registers for the rectangular region
    //       EPD_W21_WriteCMD(0x11);  // Set RAM X address range
    //       EPD_W21_WriteCMD(0x44);  // Set RAM Y address range
    //       Then set cursor to (w.x, w.y)
    current_window = w;
    window_pixel_index = 0;
}

template<typename ReveilType>
void Stm32Hardware<ReveilType>::send_pixels(rr::hw::pixels_t pixel)
{
    // TODO: Write packed pixel data to EPD display RAM
    //       Each byte holds 4 pixels (2 bits each).
    //       Iterate over the 4 pixel slots in the byte, compute the
    //       global (x, y) position, and write to the EPD RAM.
    //
    //       EPD_W21_WriteDATA(pixel);
    //
    //       Use current_window and window_pixel_index to track position.
    //       Stop when the window area is filled.

    if (!current_window.has_value())
        return;

    const auto &w = current_window.value();

    for (int i = 0; i < PIXELS_PER_BYTE; ++i)
    {
        int pixel_in_window = window_pixel_index++;
        if (pixel_in_window >= w.width * w.height)
            break;

        int local_x = pixel_in_window % w.width;
        int local_y = pixel_in_window / w.width;
        int global_x = w.x + local_x;
        int global_y = w.y + local_y;

        if (global_x < DISPLAY_WIDTH && global_y < DISPLAY_HEIGHT)
        {
            int buffer_index = global_y * DISPLAY_WIDTH + global_x;
            int shift = 6 - (i * 2);
            rr::hw::pixels_t pixel_value = (pixel >> shift) & 0x03;
            display_buffer[buffer_index] = pixel_value;
        }
    }
}

template<typename ReveilType>
void Stm32Hardware<ReveilType>::finish_window()
{
    // TODO: Finalize EPD write and reset cursor
    current_window = std::nullopt;
}

template<typename ReveilType>
void Stm32Hardware<ReveilType>::update()
{
    // TODO: Trigger EPD full refresh / partial update
    //       PIC_display(display_buffer);
    //       EPD_refresh();
    //
    //       On first call, perform a full refresh.
    //       On subsequent calls, a partial update may suffice.
}

template<typename ReveilType>
void Stm32Hardware<ReveilType>::set_next_clock_event_time(rr::hw::Clock::time_point time)
{
    // TODO: Program the RTC alarm to fire at the given time point
    //       HAL_RTC_SetAlarm_IT(&hrtc, &alarm, RTC_FORMAT_BIN);
    //
    //       The alarm interrupt handler should enqueue a TimerEvent
    //       to be processed by process_event().
}

template<typename ReveilType>
void Stm32Hardware<ReveilType>::process_event(const rr::hw::Event &event)
{
    // TODO: Call reveil.compute_update(*this, *this, event) and
    //       forward the returned flags to process_output_flags().
    //
    //       rr::hw::output_flags_t flags = reveil.compute_update(*this, *this, event);
    //       process_output_flags(flags);
}

template<typename ReveilType>
void Stm32Hardware<ReveilType>::process_output_flags(rr::hw::output_flags_t flags)
{
    // TODO: Interpret each flag bit and drive the corresponding peripheral:
    //
    //       OutputFlags::Beep      -> start / stop buzzer (PWM timer)
    //       OutputFlags::Sleep     -> EPD_sleep() + enter low-power mode
    //       OutputFlags::Backlight -> turn backlight LED on / off
    //
    //       beep_flag     = (flags & static_cast<output_flags_t>(OutputFlags::Beep)) != 0;
    //       backlight_flag = ...
    //       sleep_flag     = ...
}

} // namespace stm32
