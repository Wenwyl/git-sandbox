#include "mylib/string_utils.hpp"
#include <sstream>

namespace mylib {

std::string toUpper(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}

std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

std::string trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(static_cast<unsigned char>(*start))) {
        ++start;
    }
    
    auto end = str.end();
    do {
        --end;
    } while (std::distance(start, end) > 0 && std::isspace(static_cast<unsigned char>(*end)));
    
    return std::string(start, end + 1);
}

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

bool isPalindrome(const std::string& str) {
    if (str.empty()) {
        return true;
    }
    
    auto left = str.begin();
    auto right = str.end() - 1;
    
    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !std::isalnum(static_cast<unsigned char>(*left))) {
            ++left;
        }
        while (left < right && !std::isalnum(static_cast<unsigned char>(*right))) {
            --right;
        }
        
        if (std::tolower(static_cast<unsigned char>(*left)) != 
            std::tolower(static_cast<unsigned char>(*right))) {
            return false;
        }
        
        ++left;
        --right;
    }
    
    return true;
}

} // namespace mylib
