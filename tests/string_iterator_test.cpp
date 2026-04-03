#include "string_iterator.h"
#include "concrete_fonts.h"

#include <gtest/gtest.h>
#include <vector>

namespace rr::ui::test
{
    using namespace rr::ui;

    TEST(StringIteratorTest, MeasureEmptyString)
    {
        NormalFont font;
        StringIterator<NormalFont> iterator(font);

        String empty_str = {NULL_CHAR, NULL_CHAR, NULL_CHAR, NULL_CHAR};

        hw::x_t width = iterator.measure_width(empty_str);

        EXPECT_EQ(width, 0);
    }

    TEST(StringIteratorTest, MeasureSingleFragment)
    {
        NormalFont font;
        StringIterator<NormalFont> iterator(font);

        // Create string with single digit fragment
        String str = {
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            NULL_CHAR,
            NULL_CHAR,
            NULL_CHAR
        };

        hw::x_t width = iterator.measure_width(str);

        // Fragment 1 contains char 4, check its width
        hw::x_t expected_width = font.char_widths[4];
        EXPECT_EQ(width, expected_width);
        EXPECT_GT(width, 0);
    }

    TEST(StringIteratorTest, MeasureMultipleFragments)
    {
        NormalFont font;
        StringIterator<NormalFont> iterator(font);

        // Create string "123"
        String str_123 = {
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            static_cast<uint16_t>(fragment_index::nr) + 2,  // "2"
            static_cast<uint16_t>(fragment_index::nr) + 3,  // "3"
            NULL_CHAR
        };

        hw::x_t width = iterator.measure_width(str_123);

        // Fragments 1, 2, 3 contain chars 4, 5, 6
        hw::x_t expected_width = font.char_widths[4] + font.char_widths[5] + font.char_widths[6];
        EXPECT_EQ(width, expected_width);
        EXPECT_GT(width, 0);
    }

    TEST(StringIteratorTest, IterateEmptyString)
    {
        NormalFont font;
        StringIterator<NormalFont> iterator(font);

        String empty_str = {NULL_CHAR, NULL_CHAR, NULL_CHAR, NULL_CHAR};

        int callback_count = 0;
        iterator.iterate(empty_str, [&](uint8_t, hw::x_t, hw::x_t) {
            callback_count++;
        });

        EXPECT_EQ(callback_count, 0);
    }

    TEST(StringIteratorTest, IterateSingleCharacter)
    {
        NormalFont font;
        StringIterator<NormalFont> iterator(font);

        String str = {
            static_cast<uint16_t>(fragment_index::nr) + 0,  // "0"
            NULL_CHAR,
            NULL_CHAR,
            NULL_CHAR
        };

        std::vector<uint8_t> chars;
        std::vector<hw::x_t> positions;
        std::vector<hw::x_t> widths;

        iterator.iterate(str, [&](uint8_t ch, hw::x_t x, hw::x_t w) {
            chars.push_back(ch);
            positions.push_back(x);
            widths.push_back(w);
        });

        ASSERT_EQ(chars.size(), 1);
        EXPECT_EQ(chars[0], 3);  // Character index for "0"
        EXPECT_EQ(positions[0], 0);  // First character starts at x=0
        EXPECT_EQ(widths[0], font.char_widths[3]);
    }

    TEST(StringIteratorTest, IterateMultipleCharacters)
    {
        NormalFont font;
        StringIterator<NormalFont> iterator(font);

        String str_123 = {
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            static_cast<uint16_t>(fragment_index::nr) + 2,  // "2"
            static_cast<uint16_t>(fragment_index::nr) + 3,  // "3"
            NULL_CHAR
        };

        std::vector<uint8_t> chars;
        std::vector<hw::x_t> positions;
        std::vector<hw::x_t> widths;

        iterator.iterate(str_123, [&](uint8_t ch, hw::x_t x, hw::x_t w) {
            chars.push_back(ch);
            positions.push_back(x);
            widths.push_back(w);
        });

        ASSERT_EQ(chars.size(), 3);
        
        // Check character indices
        EXPECT_EQ(chars[0], 4);  // "1"
        EXPECT_EQ(chars[1], 5);  // "2"
        EXPECT_EQ(chars[2], 6);  // "3"

        // Check positions (should be cumulative)
        EXPECT_EQ(positions[0], 0);
        EXPECT_EQ(positions[1], font.char_widths[4]);
        EXPECT_EQ(positions[2], font.char_widths[4] + font.char_widths[5]);

        // Check widths
        EXPECT_EQ(widths[0], font.char_widths[4]);
        EXPECT_EQ(widths[1], font.char_widths[5]);
        EXPECT_EQ(widths[2], font.char_widths[6]);
    }

    TEST(StringIteratorTest, IterateReturnsCorrectTotalWidth)
    {
        NormalFont font;
        StringIterator<NormalFont> iterator(font);

        String str_123 = {
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            static_cast<uint16_t>(fragment_index::nr) + 2,  // "2"
            static_cast<uint16_t>(fragment_index::nr) + 3,  // "3"
            NULL_CHAR
        };

        hw::x_t total_width = iterator.iterate(str_123, [](auto&&...) {});

        hw::x_t expected_width = font.char_widths[4] + font.char_widths[5] + font.char_widths[6];
        EXPECT_EQ(total_width, expected_width);
    }

    TEST(StringIteratorTest, IteratePartialString)
    {
        NormalFont font;
        StringIterator<NormalFont> iterator(font);

        // String with 2 fragments and 2 NULL_CHARs
        String str = {
            static_cast<uint16_t>(fragment_index::nr) + 1,  // "1"
            static_cast<uint16_t>(fragment_index::nr) + 2,  // "2"
            NULL_CHAR,
            NULL_CHAR
        };

        int callback_count = 0;
        iterator.iterate(str, [&](uint8_t, hw::x_t, hw::x_t) {
            callback_count++;
        });

        EXPECT_EQ(callback_count, 2);  // Only 2 characters, not 4
    }

    TEST(StringIteratorTest, MeasureWidthMatchesIterateSum)
    {
        NormalFont font;
        StringIterator<NormalFont> iterator(font);

        String str = {
            static_cast<uint16_t>(fragment_index::nr) + 1,
            static_cast<uint16_t>(fragment_index::nr) + 2,
            static_cast<uint16_t>(fragment_index::nr) + 3,
            NULL_CHAR
        };

        hw::x_t measured_width = iterator.measure_width(str);

        hw::x_t iterated_width = 0;
        iterator.iterate(str, [&](uint8_t, hw::x_t, hw::x_t w) {
            iterated_width += w;
        });

        EXPECT_EQ(measured_width, iterated_width);
    }

} // namespace rr::ui::test
