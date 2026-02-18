#include <gtest/gtest.h>
#include "mylib/string_utils.hpp"

// Test toUpper function
TEST(StringUtilsTest, ToUpperBasic) {
    EXPECT_EQ(mylib::toUpper("hello"), "HELLO");
}

TEST(StringUtilsTest, ToUpperEmpty) {
    EXPECT_EQ(mylib::toUpper(""), "");
}

TEST(StringUtilsTest, ToUpperMixed) {
    EXPECT_EQ(mylib::toUpper("HeLLo WoRLd"), "HELLO WORLD");
}

TEST(StringUtilsTest, ToUpperAlreadyUpper) {
    EXPECT_EQ(mylib::toUpper("HELLO"), "HELLO");
}

// Test toLower function
TEST(StringUtilsTest, ToLowerBasic) {
    EXPECT_EQ(mylib::toLower("HELLO"), "hello");
}

TEST(StringUtilsTest, ToLowerEmpty) {
    EXPECT_EQ(mylib::toLower(""), "");
}

TEST(StringUtilsTest, ToLowerMixed) {
    EXPECT_EQ(mylib::toLower("HeLLo WoRLd"), "hello world");
}

TEST(StringUtilsTest, ToLowerAlreadyLower) {
    EXPECT_EQ(mylib::toLower("hello"), "hello");
}

// Test trim function
TEST(StringUtilsTest, TrimBothSides) {
    EXPECT_EQ(mylib::trim("  hello  "), "hello");
}

TEST(StringUtilsTest, TrimLeftOnly) {
    EXPECT_EQ(mylib::trim("  hello"), "hello");
}

TEST(StringUtilsTest, TrimRightOnly) {
    EXPECT_EQ(mylib::trim("hello  "), "hello");
}

TEST(StringUtilsTest, TrimNoSpaces) {
    EXPECT_EQ(mylib::trim("hello"), "hello");
}

TEST(StringUtilsTest, TrimEmpty) {
    EXPECT_EQ(mylib::trim(""), "");
}

TEST(StringUtilsTest, TrimOnlySpaces) {
    EXPECT_EQ(mylib::trim("   "), "");
}

// Test split function
TEST(StringUtilsTest, SplitBasic) {
    auto result = mylib::split("a,b,c", ',');
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "b");
    EXPECT_EQ(result[2], "c");
}

TEST(StringUtilsTest, SplitEmpty) {
    auto result = mylib::split("", ',');
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "");
}

TEST(StringUtilsTest, SplitSingleElement) {
    auto result = mylib::split("hello", ',');
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "hello");
}

TEST(StringUtilsTest, SplitWithSpaces) {
    auto result = mylib::split("hello world test", ' ');
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "hello");
    EXPECT_EQ(result[1], "world");
    EXPECT_EQ(result[2], "test");
}

// Test isPalindrome function
TEST(StringUtilsTest, IsPalindromeSimple) {
    EXPECT_TRUE(mylib::isPalindrome("racecar"));
    EXPECT_TRUE(mylib::isPalindrome("radar"));
}

TEST(StringUtilsTest, IsPalindromeNotPalindrome) {
    EXPECT_FALSE(mylib::isPalindrome("hello"));
    EXPECT_FALSE(mylib::isPalindrome("world"));
}

TEST(StringUtilsTest, IsPalindromeSingleChar) {
    EXPECT_TRUE(mylib::isPalindrome("a"));
}

TEST(StringUtilsTest, IsPalindromeEmpty) {
    EXPECT_TRUE(mylib::isPalindrome(""));
}

TEST(StringUtilsTest, IsPalindromeCaseInsensitive) {
    EXPECT_TRUE(mylib::isPalindrome("RaceCar"));
    EXPECT_TRUE(mylib::isPalindrome("A"));
}

TEST(StringUtilsTest, IsPalindromeWithSpaces) {
    EXPECT_TRUE(mylib::isPalindrome("A man a plan a canal Panama"));
}

TEST(StringUtilsTest, IsPalindromeWithPunctuation) {
    EXPECT_TRUE(mylib::isPalindrome("race car!"));
}
