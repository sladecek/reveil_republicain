#include "reveil.h"
#include <gtest/gtest.h>

namespace reveil {
namespace test {

// Test fixture for Calculator tests
class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;
};

TEST_F(CalculatorTest, AddPositiveNumbers) {
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(10, 20), 30);
}

TEST_F(CalculatorTest, AddNegativeNumbers) {
    EXPECT_EQ(calc.add(-2, -3), -5);
    EXPECT_EQ(calc.add(-10, 5), -5);
}

TEST_F(CalculatorTest, AddZero) {
    EXPECT_EQ(calc.add(0, 0), 0);
    EXPECT_EQ(calc.add(5, 0), 5);
    EXPECT_EQ(calc.add(0, 5), 5);
}

TEST_F(CalculatorTest, SubtractPositiveNumbers) {
    EXPECT_EQ(calc.subtract(5, 3), 2);
    EXPECT_EQ(calc.subtract(10, 20), -10);
}

TEST_F(CalculatorTest, SubtractNegativeNumbers) {
    EXPECT_EQ(calc.subtract(-5, -3), -2);
    EXPECT_EQ(calc.subtract(-10, 5), -15);
}

TEST_F(CalculatorTest, MultiplyPositiveNumbers) {
    EXPECT_EQ(calc.multiply(2, 3), 6);
    EXPECT_EQ(calc.multiply(10, 5), 50);
}

TEST_F(CalculatorTest, MultiplyByZero) {
    EXPECT_EQ(calc.multiply(5, 0), 0);
    EXPECT_EQ(calc.multiply(0, 5), 0);
}

TEST_F(CalculatorTest, MultiplyNegativeNumbers) {
    EXPECT_EQ(calc.multiply(-2, 3), -6);
    EXPECT_EQ(calc.multiply(-2, -3), 6);
}

// Tests for greet function
TEST(GreetTest, BasicGreeting) {
    EXPECT_EQ(greet("World"), "Hello, World! Welcome to Reveil.");
}

TEST(GreetTest, EmptyName) {
    EXPECT_EQ(greet(""), "Hello, ! Welcome to Reveil.");
}

TEST(GreetTest, NameWithSpaces) {
    EXPECT_EQ(greet("John Doe"), "Hello, John Doe! Welcome to Reveil.");
}

} // namespace test
} // namespace reveil
