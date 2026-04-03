#include "line_renderer.h"
#include "generated/concrete_fonts.h"
#include "bit_packer.h"

#include <gtest/gtest.h>
#include <vector>

namespace rr::ui::test
{
    using namespace rr::ui;

    TEST(LineRendererTest, RenderTextLine)
    {
        NormalFont font;
        LineRenderer<hw::BitsPerPixel::b2, NormalFont> line_renderer(font);

        std::vector<uint8_t> output_bytes;
        auto send_byte = [&output_bytes](uint8_t byte) { output_bytes.push_back(byte); };
        BitPacker<2> packer(send_byte);

        // Create a simple string with digit "1"
        String str = {
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            NULL_CHAR,
            NULL_CHAR,
            NULL_CHAR
        };

        HorizontalLayout layout{0, 10, 190};  // Left-aligned, 10px text, rest padding
        
        // Render line 10 of the font (within the character height)
        line_renderer.render_line(packer, 10, font.font_height, 200, layout, str, 0, 3);

        // Should have sent some bytes (200 pixels / 4 pixels per byte = 50 bytes)
        // But end_line() should have been called, which sends the last partial byte
        EXPECT_GT(output_bytes.size(), 0);
        EXPECT_LE(output_bytes.size(), 50);
    }

    TEST(LineRendererTest, RenderBackgroundLine)
    {
        NormalFont font;
        LineRenderer<hw::BitsPerPixel::b2, NormalFont> line_renderer(font);

        std::vector<uint8_t> output_bytes;
        auto send_byte = [&output_bytes](uint8_t byte) { output_bytes.push_back(byte); };
        BitPacker<2> packer(send_byte);

        String str = {NULL_CHAR, NULL_CHAR, NULL_CHAR, NULL_CHAR};
        HorizontalLayout layout{0, 0, 200};
        
        // Render line beyond font height (should be all background)
        line_renderer.render_line(packer, 30, font.font_height, 200, layout, str, 0, 3);

        EXPECT_EQ(output_bytes.size(), 50);  // 200 pixels / 4 = 50 bytes
        
        // All pixels should be background (value 0)
        // With 2 bits per pixel and background = 0, all bytes should be 0x00
        for (uint8_t byte : output_bytes)
        {
            EXPECT_EQ(byte, 0x00) << "Background line should have all zero bytes";
        }
    }

    TEST(LineRendererTest, RenderLineWithPadding)
    {
        NormalFont font;
        LineRenderer<hw::BitsPerPixel::b2, NormalFont> line_renderer(font);

        std::vector<uint8_t> output_bytes;
        auto send_byte = [&output_bytes](uint8_t byte) { output_bytes.push_back(byte); };
        BitPacker<2> packer(send_byte);

        String str = {
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            NULL_CHAR,
            NULL_CHAR,
            NULL_CHAR
        };

        // Center alignment with padding on both sides
        HorizontalLayout layout{95, 10, 95};  // Centered, 10px text
        
        line_renderer.render_line(packer, 10, font.font_height, 200, layout, str, 0, 3);

        EXPECT_GT(output_bytes.size(), 0);
        EXPECT_LE(output_bytes.size(), 50);
    }

    TEST(LineRendererTest, RenderEmptyString)
    {
        NormalFont font;
        LineRenderer<hw::BitsPerPixel::b2, NormalFont> line_renderer(font);

        std::vector<uint8_t> output_bytes;
        auto send_byte = [&output_bytes](uint8_t byte) { output_bytes.push_back(byte); };
        BitPacker<2> packer(send_byte);

        String empty_str = {NULL_CHAR, NULL_CHAR, NULL_CHAR, NULL_CHAR};
        HorizontalLayout layout{0, 0, 100};  // All padding
        
        line_renderer.render_line(packer, 10, font.font_height, 100, layout, empty_str, 0, 3);

        EXPECT_EQ(output_bytes.size(), 25);  // 100 pixels / 4 = 25 bytes
        
        // All should be background
        for (uint8_t byte : output_bytes)
        {
            EXPECT_EQ(byte, 0x00);
        }
    }

    TEST(LineRendererTest, RenderMultipleCharacters)
    {
        NormalFont font;
        LineRenderer<hw::BitsPerPixel::b2, NormalFont> line_renderer(font);

        std::vector<uint8_t> output_bytes;
        auto send_byte = [&output_bytes](uint8_t byte) { output_bytes.push_back(byte); };
        BitPacker<2> packer(send_byte);

        // String "123"
        String str_123 = {
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            static_cast<uint16_t>(fragment_index::nr) + 2,  // "2"
            static_cast<uint16_t>(fragment_index::nr) + 3,  // "3"
            NULL_CHAR
        };

        hw::x_t text_width = font.char_widths[4] + font.char_widths[5] + font.char_widths[6];
        HorizontalLayout layout{0, text_width, static_cast<hw::x_t>(200 - text_width)};
        
        line_renderer.render_line(packer, 10, font.font_height, 200, layout, str_123, 0, 3);

        EXPECT_EQ(output_bytes.size(), 50);
    }

    TEST(LineRendererTest, RenderLineBelowFontHeight)
    {
        NormalFont font;
        LineRenderer<hw::BitsPerPixel::b2, NormalFont> line_renderer(font);

        std::vector<uint8_t> output_bytes;
        auto send_byte = [&output_bytes](uint8_t byte) { output_bytes.push_back(byte); };
        BitPacker<2> packer(send_byte);

        String str = {
            static_cast<uint16_t>(fragment_index::nr) + 1,
            NULL_CHAR,
            NULL_CHAR,
            NULL_CHAR
        };

        HorizontalLayout layout{0, 10, 90};
        
        // Line 100 is way beyond font height (24), should render all background
        line_renderer.render_line(packer, 100, font.font_height, 100, layout, str, 0, 3);

        EXPECT_EQ(output_bytes.size(), 25);
        
        for (uint8_t byte : output_bytes)
        {
            EXPECT_EQ(byte, 0x00);
        }
    }

    TEST(LineRendererTest, RenderWithDifferentColors)
    {
        NormalFont font;
        LineRenderer<hw::BitsPerPixel::b2, NormalFont> line_renderer(font);

        std::vector<uint8_t> output_bytes_bg0_fg3;
        auto send_byte1 = [&output_bytes_bg0_fg3](uint8_t byte) { output_bytes_bg0_fg3.push_back(byte); };
        BitPacker<2> packer1(send_byte1);

        std::vector<uint8_t> output_bytes_bg1_fg2;
        auto send_byte2 = [&output_bytes_bg1_fg2](uint8_t byte) { output_bytes_bg1_fg2.push_back(byte); };
        BitPacker<2> packer2(send_byte2);

        String str = {
            static_cast<uint16_t>(fragment_index::nr) + 1,
            NULL_CHAR,
            NULL_CHAR,
            NULL_CHAR
        };

        HorizontalLayout layout{0, 10, 90};
        
        // Render with bg=0, fg=3
        line_renderer.render_line(packer1, 10, font.font_height, 100, layout, str, 0, 3);
        
        // Render with bg=1, fg=2
        line_renderer.render_line(packer2, 10, font.font_height, 100, layout, str, 1, 2);

        EXPECT_GT(output_bytes_bg0_fg3.size(), 0);
        EXPECT_GT(output_bytes_bg1_fg2.size(), 0);
        
        // The outputs should be different (different colors)
        EXPECT_NE(output_bytes_bg0_fg3, output_bytes_bg1_fg2);
    }

    TEST(LineRendererTest, RenderTopLine)
    {
        NormalFont font;
        LineRenderer<hw::BitsPerPixel::b2, NormalFont> line_renderer(font);

        std::vector<uint8_t> output_bytes;
        auto send_byte = [&output_bytes](uint8_t byte) { output_bytes.push_back(byte); };
        BitPacker<2> packer(send_byte);

        String str = {
            static_cast<uint16_t>(fragment_index::nr) + 0,  // "0"
            NULL_CHAR,
            NULL_CHAR,
            NULL_CHAR
        };

        HorizontalLayout layout{0, 8, 92};
        
        // Render y=0 (top line)
        line_renderer.render_line(packer, 0, font.font_height, 100, layout, str, 0, 3);

        EXPECT_EQ(output_bytes.size(), 25);
    }

    TEST(LineRendererTest, RenderWithClipping)
    {
        NormalFont font;
        LineRenderer<hw::BitsPerPixel::b2, NormalFont> line_renderer(font);

        std::vector<uint8_t> output_bytes;
        auto send_byte = [&output_bytes](uint8_t byte) { output_bytes.push_back(byte); };
        BitPacker<2> packer(send_byte);

        // String "123" but text width only fits "12"
        String str_123 = {
            static_cast<uint16_t>(fragment_index::nr) + 1,
            static_cast<uint16_t>(fragment_index::nr) + 2,
            static_cast<uint16_t>(fragment_index::nr) + 3,
            NULL_CHAR
        };

        // Text width smaller than actual string width (clipping should occur)
        HorizontalLayout layout{0, 15, 85};
        
        line_renderer.render_line(packer, 10, font.font_height, 100, layout, str_123, 0, 3);

        EXPECT_EQ(output_bytes.size(), 25);
    }

    TEST(LineRendererTest, RenderNarrowWindow)
    {
        NormalFont font;
        LineRenderer<hw::BitsPerPixel::b2, NormalFont> line_renderer(font);

        std::vector<uint8_t> output_bytes;
        auto send_byte = [&output_bytes](uint8_t byte) { output_bytes.push_back(byte); };
        BitPacker<2> packer(send_byte);

        String str = {
            static_cast<uint16_t>(fragment_index::nr) + 0,
            NULL_CHAR,
            NULL_CHAR,
            NULL_CHAR
        };

        HorizontalLayout layout{0, 8, 0};
        
        // Very narrow window (just 8 pixels for the character)
        line_renderer.render_line(packer, 10, font.font_height, 8, layout, str, 0, 3);

        EXPECT_EQ(output_bytes.size(), 2);  // 8 pixels / 4 = 2 bytes
    }

} // namespace rr::ui::test
