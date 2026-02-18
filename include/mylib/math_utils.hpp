#pragma once

#include <vector>
#include <numeric>
#include <cmath>

namespace mylib {

/**
 * @brief Calculate the sum of a vector of numbers
 * @tparam T Numeric type
 * @param values Vector of values to sum
 * @return Sum of all values
 */
template<typename T>
T sum(const std::vector<T>& values) {
    return std::accumulate(values.begin(), values.end(), T{0});
}

/**
 * @brief Calculate the mean (average) of a vector of numbers
 * @tparam T Numeric type
 * @param values Vector of values
 * @return Mean value, or 0 if empty
 */
template<typename T>
double mean(const std::vector<T>& values) {
    if (values.empty()) {
        return 0.0;
    }
    return static_cast<double>(sum(values)) / values.size();
}

/**
 * @brief Calculate the factorial of a non-negative integer
 * @param n Non-negative integer
 * @return Factorial of n
 * @throws std::invalid_argument if n is negative
 */
unsigned long long factorial(int n);

/**
 * @brief Check if a number is prime
 * @param n Number to check
 * @return true if n is prime, false otherwise
 */
bool isPrime(int n);

} // namespace mylib
