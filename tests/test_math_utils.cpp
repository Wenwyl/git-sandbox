#include <gtest/gtest.h>
#include "mylib/math_utils.hpp"
#include <vector>

// Test sum function
TEST(MathUtilsTest, SumPositiveNumbers) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    EXPECT_EQ(mylib::sum(numbers), 15);
}

TEST(MathUtilsTest, SumEmptyVector) {
    std::vector<int> numbers;
    EXPECT_EQ(mylib::sum(numbers), 0);
}

TEST(MathUtilsTest, SumSingleElement) {
    std::vector<int> numbers = {42};
    EXPECT_EQ(mylib::sum(numbers), 42);
}

TEST(MathUtilsTest, SumNegativeNumbers) {
    std::vector<int> numbers = {-1, -2, -3};
    EXPECT_EQ(mylib::sum(numbers), -6);
}

// Test mean function
TEST(MathUtilsTest, MeanPositiveNumbers) {
    std::vector<int> numbers = {2, 4, 6, 8, 10};
    EXPECT_DOUBLE_EQ(mylib::mean(numbers), 6.0);
}

TEST(MathUtilsTest, MeanEmptyVector) {
    std::vector<int> numbers;
    EXPECT_DOUBLE_EQ(mylib::mean(numbers), 0.0);
}

TEST(MathUtilsTest, MeanSingleElement) {
    std::vector<int> numbers = {42};
    EXPECT_DOUBLE_EQ(mylib::mean(numbers), 42.0);
}

// Test factorial function
TEST(MathUtilsTest, FactorialZero) {
    EXPECT_EQ(mylib::factorial(0), 1);
}

TEST(MathUtilsTest, FactorialOne) {
    EXPECT_EQ(mylib::factorial(1), 1);
}

TEST(MathUtilsTest, FactorialPositive) {
    EXPECT_EQ(mylib::factorial(5), 120);
    EXPECT_EQ(mylib::factorial(6), 720);
}

TEST(MathUtilsTest, FactorialNegativeThrows) {
    EXPECT_THROW(mylib::factorial(-1), std::invalid_argument);
}

TEST(MathUtilsTest, FactorialOverflowThrows) {
    EXPECT_THROW(mylib::factorial(21), std::overflow_error);
}

TEST(MathUtilsTest, FactorialMaxValue) {
    // 20! is the largest factorial that fits in unsigned long long
    EXPECT_EQ(mylib::factorial(20), 2432902008176640000ULL);
}

// Test isPrime function
TEST(MathUtilsTest, IsPrimeNegative) {
    EXPECT_FALSE(mylib::isPrime(-5));
}

TEST(MathUtilsTest, IsPrimeZeroAndOne) {
    EXPECT_FALSE(mylib::isPrime(0));
    EXPECT_FALSE(mylib::isPrime(1));
}

TEST(MathUtilsTest, IsPrimeSmallPrimes) {
    EXPECT_TRUE(mylib::isPrime(2));
    EXPECT_TRUE(mylib::isPrime(3));
    EXPECT_TRUE(mylib::isPrime(5));
    EXPECT_TRUE(mylib::isPrime(7));
}

TEST(MathUtilsTest, IsPrimeComposites) {
    EXPECT_FALSE(mylib::isPrime(4));
    EXPECT_FALSE(mylib::isPrime(6));
    EXPECT_FALSE(mylib::isPrime(8));
    EXPECT_FALSE(mylib::isPrime(9));
}

TEST(MathUtilsTest, IsPrimeLargerNumbers) {
    EXPECT_TRUE(mylib::isPrime(17));
    EXPECT_TRUE(mylib::isPrime(19));
    EXPECT_FALSE(mylib::isPrime(20));
    EXPECT_FALSE(mylib::isPrime(21));
}
