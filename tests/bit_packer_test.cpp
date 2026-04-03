#include "bit_packer.h"

#include <gtest/gtest.h>
#include <vector>
#include <cstdint>

namespace rr::ui::test
{
    using namespace rr::ui;

    TEST(BitPackerTest, Pack2BitsPerPixel_4Pixels)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<2> packer(send_byte);

        packer.start_line();
        packer.draw_pixel(0b11); // First pixel (bits 7-6)
        packer.draw_pixel(0b10); // Second pixel (bits 5-4)
        packer.draw_pixel(0b01); // Third pixel (bits 3-2)
        packer.draw_pixel(0b00); // Fourth pixel (bits 1-0)
        packer.end_line();

        ASSERT_EQ(bytes.size(), 1);
        EXPECT_EQ(bytes[0], 0b11100100); // 0xE4
    }

    TEST(BitPackerTest, Pack2BitsPerPixel_PartialByte)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<2> packer(send_byte);

        packer.start_line();
        packer.draw_pixel(0b11); // First pixel
        packer.draw_pixel(0b01); // Second pixel
        // Only 2 pixels, should be MSB-aligned in the byte
        packer.end_line();

        ASSERT_EQ(bytes.size(), 1);
        // 11 01 00 00 (MSB aligned, remaining bits are 0)
        EXPECT_EQ(bytes[0], 0b11010000); // 0xD0
    }

    TEST(BitPackerTest, Pack2BitsPerPixel_MultipleBytesExact)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<2> packer(send_byte);

        packer.start_line();
        // First byte: 11 10 01 00
        packer.draw_pixel(0b11);
        packer.draw_pixel(0b10);
        packer.draw_pixel(0b01);
        packer.draw_pixel(0b00);
        // Second byte: 00 01 10 11
        packer.draw_pixel(0b00);
        packer.draw_pixel(0b01);
        packer.draw_pixel(0b10);
        packer.draw_pixel(0b11);
        packer.end_line();

        ASSERT_EQ(bytes.size(), 2);
        EXPECT_EQ(bytes[0], 0b11100100); // 0xE4
        EXPECT_EQ(bytes[1], 0b00011011); // 0x1B
    }

    TEST(BitPackerTest, Pack2BitsPerPixel_MultipleBytesPartial)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<2> packer(send_byte);

        packer.start_line();
        // First byte: 11 10 01 00
        packer.draw_pixel(0b11);
        packer.draw_pixel(0b10);
        packer.draw_pixel(0b01);
        packer.draw_pixel(0b00);
        // Partial second byte: 11 00 (then MSB-aligned)
        packer.draw_pixel(0b11);
        packer.end_line();

        ASSERT_EQ(bytes.size(), 2);
        EXPECT_EQ(bytes[0], 0b11100100); // 0xE4
        EXPECT_EQ(bytes[1], 0b11000000); // 0xC0 (MSB aligned)
    }

    TEST(BitPackerTest, Pack2BitsPerPixel_MultipleLines)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<2> packer(send_byte);

        // First line: 2 pixels
        packer.start_line();
        packer.draw_pixel(0b11);
        packer.draw_pixel(0b00);
        packer.end_line();

        // Second line: 3 pixels
        packer.start_line();
        packer.draw_pixel(0b10);
        packer.draw_pixel(0b01);
        packer.draw_pixel(0b10);
        packer.end_line();

        ASSERT_EQ(bytes.size(), 2);
        EXPECT_EQ(bytes[0], 0b11000000); // Line 1: 11 00 (MSB aligned)
        EXPECT_EQ(bytes[1], 0b10011000); // Line 2: 10 01 10 (MSB aligned)
    }

    TEST(BitPackerTest, Pack1BitPerPixel_8Pixels)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<1> packer(send_byte);

        packer.start_line();
        packer.draw_pixel(1);
        packer.draw_pixel(0);
        packer.draw_pixel(1);
        packer.draw_pixel(1);
        packer.draw_pixel(0);
        packer.draw_pixel(0);
        packer.draw_pixel(1);
        packer.draw_pixel(0);
        packer.end_line();

        ASSERT_EQ(bytes.size(), 1);
        EXPECT_EQ(bytes[0], 0b10110010); // 0xB2
    }

    TEST(BitPackerTest, Pack1BitPerPixel_PartialByte)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<1> packer(send_byte);

        packer.start_line();
        packer.draw_pixel(1);
        packer.draw_pixel(0);
        packer.draw_pixel(1);
        // Only 3 pixels, should be MSB-aligned
        packer.end_line();

        ASSERT_EQ(bytes.size(), 1);
        EXPECT_EQ(bytes[0], 0b10100000); // 0xA0 (MSB aligned)
    }

    TEST(BitPackerTest, Pack4BitsPerPixel_2Pixels)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<4> packer(send_byte);

        packer.start_line();
        packer.draw_pixel(0b1111); // First pixel (upper nibble)
        packer.draw_pixel(0b0101); // Second pixel (lower nibble)
        packer.end_line();

        ASSERT_EQ(bytes.size(), 1);
        EXPECT_EQ(bytes[0], 0b11110101); // 0xF5
    }

    TEST(BitPackerTest, Pack4BitsPerPixel_PartialByte)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<4> packer(send_byte);

        packer.start_line();
        packer.draw_pixel(0b1010); // Only 1 pixel, should be in upper nibble
        packer.end_line();

        ASSERT_EQ(bytes.size(), 1);
        EXPECT_EQ(bytes[0], 0b10100000); // 0xA0 (MSB aligned)
    }

    TEST(BitPackerTest, EmptyLine)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<2> packer(send_byte);

        packer.start_line();
        packer.end_line();

        // No bytes should be sent for an empty line
        EXPECT_EQ(bytes.size(), 0);
    }

    TEST(BitPackerTest, GetPackedPixelsCount)
    {
        std::vector<uint8_t> bytes;
        auto send_byte = [&bytes](uint8_t byte) { bytes.push_back(byte); };

        BitPacker<2> packer(send_byte);

        packer.start_line();
        EXPECT_EQ(packer.get_packed_pixels(), 0);

        packer.draw_pixel(0b11);
        EXPECT_EQ(packer.get_packed_pixels(), 1);

        packer.draw_pixel(0b10);
        EXPECT_EQ(packer.get_packed_pixels(), 2);

        packer.draw_pixel(0b01);
        EXPECT_EQ(packer.get_packed_pixels(), 3);

        packer.draw_pixel(0b00);
        // After drawing 4 pixels (full byte), the byte is complete but not yet sent
        EXPECT_EQ(packer.get_packed_pixels(), 4);
        
        // Drawing one more pixel will trigger the send and reset
        packer.draw_pixel(0b11);
        EXPECT_EQ(packer.get_packed_pixels(), 1);
    }

    TEST(BitPackerTest, PixelsPerByteConstant)
    {
        EXPECT_EQ(BitPacker<1>::pixels_per_byte, 8);
        EXPECT_EQ(BitPacker<2>::pixels_per_byte, 4);
        EXPECT_EQ(BitPacker<4>::pixels_per_byte, 2);
    }

} // namespace rr::ui::test
