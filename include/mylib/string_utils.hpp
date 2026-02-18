#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

namespace mylib {

/**
 * @brief Convert a string to uppercase
 * @param str Input string
 * @return Uppercase version of the string
 */
std::string toUpper(const std::string& str);

/**
 * @brief Convert a string to lowercase
 * @param str Input string
 * @return Lowercase version of the string
 */
std::string toLower(const std::string& str);

/**
 * @brief Trim whitespace from both ends of a string
 * @param str Input string
 * @return Trimmed string
 */
std::string trim(const std::string& str);

/**
 * @brief Split a string by a delimiter
 * @param str Input string
 * @param delimiter Delimiter character
 * @return Vector of substrings
 */
std::vector<std::string> split(const std::string& str, char delimiter);

/**
 * @brief Check if a string is a palindrome
 * @param str Input string
 * @return true if the string is a palindrome, false otherwise
 */
bool isPalindrome(const std::string& str);

} // namespace mylib
