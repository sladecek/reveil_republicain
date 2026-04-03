#include "text_layout_calculator.h"

#include <gtest/gtest.h>

namespace rr::ui::test
{
    using namespace rr::ui;

    TEST(TextLayoutCalculatorTest, AlignLeftStringFits)
    {
        auto layout = TextLayoutCalculator::compute_horizontal_alignment(100, 50, Align::left);

        EXPECT_EQ(layout.left_padding, 0);
        EXPECT_EQ(layout.text_width, 50);
        EXPECT_EQ(layout.right_padding, 50);
        EXPECT_EQ(layout.left_padding + layout.text_width + layout.right_padding, 100);
    }

    TEST(TextLayoutCalculatorTest, AlignCenterStringFits)
    {
        auto layout = TextLayoutCalculator::compute_horizontal_alignment(100, 50, Align::center);

        EXPECT_EQ(layout.left_padding, 25);
        EXPECT_EQ(layout.text_width, 50);
        EXPECT_EQ(layout.right_padding, 25);
        EXPECT_EQ(layout.left_padding + layout.text_width + layout.right_padding, 100);
    }

    TEST(TextLayoutCalculatorTest, AlignRightStringFits)
    {
        auto layout = TextLayoutCalculator::compute_horizontal_alignment(100, 50, Align::right);

        EXPECT_EQ(layout.left_padding, 50);
        EXPECT_EQ(layout.text_width, 50);
        EXPECT_EQ(layout.right_padding, 0);
        EXPECT_EQ(layout.left_padding + layout.text_width + layout.right_padding, 100);
    }

    TEST(TextLayoutCalculatorTest, AlignCenterStringFitsOddWidth)
    {
        // String width 51 in window width 100 -> left padding 24, right padding 25
        auto layout = TextLayoutCalculator::compute_horizontal_alignment(100, 51, Align::center);

        EXPECT_EQ(layout.left_padding, 24);
        EXPECT_EQ(layout.text_width, 51);
        EXPECT_EQ(layout.right_padding, 25);
        EXPECT_EQ(layout.left_padding + layout.text_width + layout.right_padding, 100);
    }

    TEST(TextLayoutCalculatorTest, AlignStringTooWide)
    {
        // String width 150 exceeds window width 100
        auto layout = TextLayoutCalculator::compute_horizontal_alignment(100, 150, Align::center);

        EXPECT_EQ(layout.left_padding, 0);
        EXPECT_EQ(layout.text_width, 100);  // Truncated to window width
        EXPECT_EQ(layout.right_padding, 0);
        EXPECT_EQ(layout.left_padding + layout.text_width + layout.right_padding, 100);
    }

    TEST(TextLayoutCalculatorTest, AlignEmptyString)
    {
        auto layout_left = TextLayoutCalculator::compute_horizontal_alignment(100, 0, Align::left);
        EXPECT_EQ(layout_left.left_padding, 0);
        EXPECT_EQ(layout_left.text_width, 0);
        EXPECT_EQ(layout_left.right_padding, 100);

        auto layout_center = TextLayoutCalculator::compute_horizontal_alignment(100, 0, Align::center);
        EXPECT_EQ(layout_center.left_padding, 50);
        EXPECT_EQ(layout_center.text_width, 0);
        EXPECT_EQ(layout_center.right_padding, 50);

        auto layout_right = TextLayoutCalculator::compute_horizontal_alignment(100, 0, Align::right);
        EXPECT_EQ(layout_right.left_padding, 100);
        EXPECT_EQ(layout_right.text_width, 0);
        EXPECT_EQ(layout_right.right_padding, 0);
    }

    TEST(TextLayoutCalculatorTest, AlignStringExactlyFits)
    {
        // String exactly fits window width
        auto layout = TextLayoutCalculator::compute_horizontal_alignment(100, 100, Align::center);

        EXPECT_EQ(layout.left_padding, 0);
        EXPECT_EQ(layout.text_width, 100);
        EXPECT_EQ(layout.right_padding, 0);
        EXPECT_EQ(layout.left_padding + layout.text_width + layout.right_padding, 100);
    }

    TEST(TextLayoutCalculatorTest, CalculateClippingNoClip)
    {
        // Character fits completely within text width
        hw::x_t max_pixels = TextLayoutCalculator::calculate_clipping(10, 20, 100);
        EXPECT_EQ(max_pixels, 20);  // Full character width
    }

    TEST(TextLayoutCalculatorTest, CalculateClippingPartialClip)
    {
        // Character extends beyond text width
        hw::x_t max_pixels = TextLayoutCalculator::calculate_clipping(90, 20, 100);
        EXPECT_EQ(max_pixels, 10);  // Only 10 pixels visible (100 - 90)
    }

    TEST(TextLayoutCalculatorTest, CalculateClippingFullClip)
    {
        // Character starts beyond text width
        hw::x_t max_pixels = TextLayoutCalculator::calculate_clipping(100, 20, 100);
        EXPECT_EQ(max_pixels, 0);  // Completely clipped
    }

    TEST(TextLayoutCalculatorTest, CalculateClippingAtBoundary)
    {
        // Character ends exactly at text width
        hw::x_t max_pixels = TextLayoutCalculator::calculate_clipping(80, 20, 100);
        EXPECT_EQ(max_pixels, 20);  // Full character visible
    }

    TEST(TextLayoutCalculatorTest, CalculateClippingZeroWidth)
    {
        // Zero-width character
        hw::x_t max_pixels = TextLayoutCalculator::calculate_clipping(10, 0, 100);
        EXPECT_EQ(max_pixels, 0);
    }

} // namespace rr::ui::test
