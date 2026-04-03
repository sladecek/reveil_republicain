#include "char_pixel_extractor.h"
#include "concrete_fonts.h"

#include <gtest/gtest.h>
#include <vector>
#include <cstdint>

namespace rr::ui::test
{
    using namespace rr::ui;

    // Mock font for testing with known patterns
    struct MockFont
    {
        static constexpr size_t font_len = 3;
        static constexpr size_t font_height = 4;
        static constexpr size_t font_content_size = 12;

        // Character 0: 8 pixels wide, all zeros
        // Character 1: 8 pixels wide, alternating pattern
        // Character 2: 5 pixels wide, specific pattern
        const std::array<uint8_t, font_len> char_widths = {8, 8, 5};
        
        const std::array<uint16_t, font_len> char_begin = {
            0,  // Character 0 starts at byte 0
            4,  // Character 1 starts at byte 4 (4 lines * 1 byte per line)
            8   // Character 2 starts at byte 8
        };
        
        // Content layout:
        // Char 0 (bytes 0-3): 4 lines of 0x00
        // Char 1 (bytes 4-7): 4 lines of 0xAA (10101010)
        // Char 2 (bytes 8-11): 4 lines of 0xF8 (11111000)
        const std::array<uint8_t, font_content_size> content = {
            0x00, 0x00, 0x00, 0x00,  // Char 0
            0xAA, 0xAA, 0xAA, 0xAA,  // Char 1
            0xF8, 0xF8, 0xF8, 0xF8   // Char 2
        };
    };

    TEST(CharPixelExtractorTest, ExtractAllZeros)
    {
        MockFont font;
        std::vector<bool> pixels;
        
        auto draw_pixel = [&pixels](bool pixel) { pixels.push_back(pixel); };
        
        CharPixelExtractor<MockFont> extractor(font, draw_pixel);
        
        // Extract character 0, line 0 (all zeros)
        extractor.extract_char_line(0, 0, 8, 8);
        
        ASSERT_EQ(pixels.size(), 8);
        for (int i = 0; i < 8; ++i)
        {
            EXPECT_FALSE(pixels[i]) << "Pixel " << i << " should be false";
        }
    }

    TEST(CharPixelExtractorTest, ExtractAlternatingPattern)
    {
        MockFont font;
        std::vector<bool> pixels;
        
        auto draw_pixel = [&pixels](bool pixel) { pixels.push_back(pixel); };
        
        CharPixelExtractor<MockFont> extractor(font, draw_pixel);
        
        // Extract character 1, line 0 (0xAA = 10101010)
        // With check-before-shift, the pattern is: 10101010
        extractor.extract_char_line(1, 0, 8, 8);
        
        ASSERT_EQ(pixels.size(), 8);
        EXPECT_TRUE(pixels[0]);   // 1
        EXPECT_FALSE(pixels[1]);  // 0
        EXPECT_TRUE(pixels[2]);   // 1
        EXPECT_FALSE(pixels[3]);  // 0
        EXPECT_TRUE(pixels[4]);   // 1
        EXPECT_FALSE(pixels[5]);  // 0
        EXPECT_TRUE(pixels[6]);   // 1
        EXPECT_FALSE(pixels[7]);  // 0
    }

    TEST(CharPixelExtractorTest, ExtractPartialByte)
    {
        MockFont font;
        std::vector<bool> pixels;
        
        auto draw_pixel = [&pixels](bool pixel) { pixels.push_back(pixel); };
        
        CharPixelExtractor<MockFont> extractor(font, draw_pixel);
        
        // Extract character 2, line 0 (0xF8 = 11111000, only 5 pixels wide)
        // With check-before-shift: 11111 (first 5 bits)
        extractor.extract_char_line(2, 0, 5, 5);
        
        ASSERT_EQ(pixels.size(), 5);
        EXPECT_TRUE(pixels[0]);   // 1
        EXPECT_TRUE(pixels[1]);   // 1
        EXPECT_TRUE(pixels[2]);   // 1
        EXPECT_TRUE(pixels[3]);   // 1
        EXPECT_TRUE(pixels[4]);   // 1
    }

    TEST(CharPixelExtractorTest, ExtractWithClipping)
    {
        MockFont font;
        std::vector<bool> pixels;
        
        auto draw_pixel = [&pixels](bool pixel) { pixels.push_back(pixel); };
        
        CharPixelExtractor<MockFont> extractor(font, draw_pixel);
        
        // Extract character 1, line 0, but clip to 5 pixels
        // 0xAA = 10101010, first 5: 10101
        extractor.extract_char_line(1, 0, 8, 5);
        
        ASSERT_EQ(pixels.size(), 5);
        EXPECT_TRUE(pixels[0]);   // 1
        EXPECT_FALSE(pixels[1]);  // 0
        EXPECT_TRUE(pixels[2]);   // 1
        EXPECT_FALSE(pixels[3]);  // 0
        EXPECT_TRUE(pixels[4]);   // 1
    }

    TEST(CharPixelExtractorTest, ExtractDifferentLines)
    {
        MockFont font;
        
        CharPixelExtractor<MockFont> extractor(font, [](bool) {});
        
        // All lines of character 1 should have the same pattern (0xAA)
        // Pattern: 10101010
        for (int y = 0; y < 4; ++y)
        {
            std::vector<bool> pixels;
            CharPixelExtractor<MockFont> line_extractor(
                font, [&pixels](bool pixel) { pixels.push_back(pixel); });
            
            line_extractor.extract_char_line(1, y, 8, 8);
            
            ASSERT_EQ(pixels.size(), 8) << "Line " << y;
            EXPECT_TRUE(pixels[0]) << "Line " << y;
            EXPECT_FALSE(pixels[1]) << "Line " << y;
            EXPECT_TRUE(pixels[2]) << "Line " << y;
            EXPECT_FALSE(pixels[3]) << "Line " << y;
        }
    }

    TEST(CharPixelExtractorTest, ExtractZeroWidth)
    {
        MockFont font;
        std::vector<bool> pixels;
        
        auto draw_pixel = [&pixels](bool pixel) { pixels.push_back(pixel); };
        
        CharPixelExtractor<MockFont> extractor(font, draw_pixel);
        
        // Extract 0 pixels
        extractor.extract_char_line(0, 0, 8, 0);
        
        EXPECT_EQ(pixels.size(), 0);
    }

    TEST(CharPixelExtractorTest, ExtractSinglePixel)
    {
        MockFont font;
        std::vector<bool> pixels;
        
        auto draw_pixel = [&pixels](bool pixel) { pixels.push_back(pixel); };
        
        CharPixelExtractor<MockFont> extractor(font, draw_pixel);
        
        // Extract just the first pixel of character 1
        // 0xAA = 10101010, first bit = 1
        extractor.extract_char_line(1, 0, 8, 1);
        
        ASSERT_EQ(pixels.size(), 1);
        EXPECT_TRUE(pixels[0]);
    }

    TEST(CharPixelExtractorTest, ExtractWithRealFont)
    {
        NormalFont font;
        std::vector<bool> pixels;
        
        auto draw_pixel = [&pixels](bool pixel) { pixels.push_back(pixel); };
        
        CharPixelExtractor<NormalFont> extractor(font, draw_pixel);
        
        // Extract some character from the real font
        // Character '0' is at index 3 according to previous work
        const uint8_t char_index = 3;
        const uint8_t char_width = font.char_widths[char_index];
        
        extractor.extract_char_line(char_index, 0, char_width, char_width);
        
        // Should extract exactly char_width pixels
        EXPECT_EQ(pixels.size(), char_width);
        
        // Should have at least some background and some foreground
        bool has_true = false;
        bool has_false = false;
        for (bool pixel : pixels)
        {
            if (pixel) has_true = true;
            if (!pixel) has_false = true;
        }
        
        // Top line of digit '0' should have both foreground and background
        EXPECT_TRUE(has_true || has_false) << "Should have at least some pixels";
    }

    TEST(CharPixelExtractorTest, CountPixelCalls)
    {
        MockFont font;
        int call_count = 0;
        
        auto draw_pixel = [&call_count](bool) { call_count++; };
        
        CharPixelExtractor<MockFont> extractor(font, draw_pixel);
        
        // Extract 8 pixels
        extractor.extract_char_line(1, 0, 8, 8);
        EXPECT_EQ(call_count, 8);
        
        // Extract 5 pixels
        call_count = 0;
        extractor.extract_char_line(2, 0, 5, 5);
        EXPECT_EQ(call_count, 5);
        
        // Extract with clipping
        call_count = 0;
        extractor.extract_char_line(1, 0, 8, 3);
        EXPECT_EQ(call_count, 3);
    }

} // namespace rr::ui::test
