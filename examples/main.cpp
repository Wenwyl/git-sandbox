#include <iostream>
#include <vector>
#include "mylib/math_utils.hpp"
#include "mylib/string_utils.hpp"

int main() {
    std::cout << "=== Modern C++ Project Demo ===" << std::endl;
    std::cout << std::endl;

    // Math utilities demonstration
    std::cout << "Math Utilities:" << std::endl;
    std::cout << "---------------" << std::endl;
    
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Numbers: ";
    for (const auto& n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Sum: " << mylib::sum(numbers) << std::endl;
    std::cout << "Mean: " << mylib::mean(numbers) << std::endl;
    
    std::cout << "Factorial of 5: " << mylib::factorial(5) << std::endl;
    
    std::cout << "Prime numbers from 1 to 20: ";
    for (int i = 1; i <= 20; ++i) {
        if (mylib::isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl << std::endl;

    // String utilities demonstration
    std::cout << "String Utilities:" << std::endl;
    std::cout << "-----------------" << std::endl;
    
    std::string text = "Hello, World!";
    std::cout << "Original: " << text << std::endl;
    std::cout << "Uppercase: " << mylib::toUpper(text) << std::endl;
    std::cout << "Lowercase: " << mylib::toLower(text) << std::endl;
    
    std::string spacedText = "   trimmed text   ";
    std::cout << "Before trim: '" << spacedText << "'" << std::endl;
    std::cout << "After trim: '" << mylib::trim(spacedText) << "'" << std::endl;
    
    std::string csv = "apple,banana,cherry,date";
    std::cout << "Splitting '" << csv << "' by ',': ";
    auto parts = mylib::split(csv, ',');
    for (const auto& part : parts) {
        std::cout << "[" << part << "] ";
    }
    std::cout << std::endl;
    
    std::string palindrome1 = "racecar";
    std::string palindrome2 = "hello";
    std::cout << "Is '" << palindrome1 << "' a palindrome? " 
              << (mylib::isPalindrome(palindrome1) ? "Yes" : "No") << std::endl;
    std::cout << "Is '" << palindrome2 << "' a palindrome? " 
              << (mylib::isPalindrome(palindrome2) ? "Yes" : "No") << std::endl;
    
    std::cout << std::endl;
    std::cout << "=== Demo Complete ===" << std::endl;
    
    return 0;
}
