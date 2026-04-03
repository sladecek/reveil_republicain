#pragma once

#include <cstdint>
#include <functional>

namespace rr::ui
{
    // Generic bit packer that packs pixels into bytes with configurable bits per pixel.
    // This class handles the bit-packing logic for converting pixel values into packed bytes,
    // where multiple pixels are stored in a single byte. Pixels are packed from MSB to LSB.
    template <int BitsPerPixel>
    class BitPacker
    {
    public:
        static_assert(BitsPerPixel > 0 && BitsPerPixel <= 8, "BitsPerPixel must be between 1 and 8");
        static_assert(8 % BitsPerPixel == 0, "BitsPerPixel must evenly divide 8");

        static constexpr int pixels_per_byte = 8 / BitsPerPixel;

        using ByteCallback = std::function<void(uint8_t)>;

        explicit BitPacker(ByteCallback send_byte)
            : send_byte_(send_byte)
            , packed_bits_(0)
            , packed_pixels_(0)
        {
        }

        void start_line()
        {
            packed_bits_ = 0;
            packed_pixels_ = 0;
        }

        void end_line()
        {
            // Send any remaining pixels in the current byte
            if (packed_pixels_ > 0)
            {
                // Shift remaining bits to align to MSB
                int remaining_bits = (pixels_per_byte - packed_pixels_) * BitsPerPixel;
                packed_bits_ <<= remaining_bits;
                send_byte_(packed_bits_);
            }
        }

        void draw_pixel(uint8_t pixel_value)
        {
            if (packed_pixels_ >= pixels_per_byte)
            {
                // Byte is full, send it
                send_byte_(packed_bits_);
                start_line();
            }
            // Pack pixel from MSB to LSB
            packed_bits_ <<= BitsPerPixel;
            packed_bits_ |= pixel_value;
            packed_pixels_ += 1;
        }

        uint8_t get_packed_pixels() const { return packed_pixels_; }

        int get_packed_bits() const { return packed_bits_; }

    private:
        ByteCallback send_byte_;
        int packed_bits_;
        uint8_t packed_pixels_;
    };

} // namespace rr::ui
