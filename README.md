# Git Sandbox - Modern C++ Project

[![C++ CI](https://github.com/Wenwyl/git-sandbox/actions/workflows/ci.yml/badge.svg)](https://github.com/Wenwyl/git-sandbox/actions/workflows/ci.yml)

A modern C++ project template for practicing C++17/20 features and GitHub CI/CD pipelines. This project provides a clean, extensible structure that's easy to build upon.

## Features

- **Modern C++17** standards with clear project structure
- **CMake** build system for cross-platform compatibility
- **Google Test** integration for unit testing
- **GitHub Actions** CI/CD pipeline (Ubuntu, macOS, Windows)
- **Modular design** with separate library and examples
- **Comprehensive documentation** with Doxygen-style comments

## Project Structure

```
git-sandbox/
├── include/mylib/          # Public header files
│   ├── math_utils.hpp      # Mathematical utilities
│   └── string_utils.hpp    # String manipulation utilities
├── src/                    # Implementation files
│   ├── math_utils.cpp
│   └── string_utils.cpp
├── tests/                  # Unit tests
│   ├── test_math_utils.cpp
│   └── test_string_utils.cpp
├── examples/               # Example applications
│   └── main.cpp
├── docs/                   # Documentation
├── CMakeLists.txt          # CMake configuration
└── .github/workflows/      # CI/CD pipelines
    └── ci.yml
```

## Prerequisites

- **CMake** 3.14 or higher
- **C++17** compatible compiler:
  - GCC 7+ / Clang 5+ (Linux/macOS)
  - MSVC 2017+ (Windows)
- **Git** for version control

## Building the Project

### Quick Start

```bash
# Clone the repository
git clone https://github.com/Wenwyl/git-sandbox.git
cd git-sandbox

# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build .

# Run tests
ctest --output-on-failure

# Run the example program
./example  # On Unix-like systems
# or
.\Debug\example.exe  # On Windows
```

### Build Options

```bash
# Build in Release mode
cmake -DCMAKE_BUILD_TYPE=Release ..

# Disable tests
cmake -DBUILD_TESTS=OFF ..

# Disable examples
cmake -DBUILD_EXAMPLES=OFF ..
```

## Library Components

### Math Utilities (`mylib/math_utils.hpp`)

- `sum<T>()` - Calculate sum of numeric vector
- `mean<T>()` - Calculate mean/average
- `factorial()` - Compute factorial
- `isPrime()` - Check if number is prime

### String Utilities (`mylib/string_utils.hpp`)

- `toUpper()` / `toLower()` - Case conversion
- `trim()` - Remove whitespace from ends
- `split()` - Split string by delimiter
- `isPalindrome()` - Check for palindromes

## Testing

This project uses Google Test for unit testing. Tests are automatically downloaded and built by CMake.

```bash
# Run all tests
ctest --output-on-failure

# Run tests with verbose output
ctest -V

# Run specific test
./unit_tests --gtest_filter=MathUtilsTest.*
```

## Adding New Features

### Adding a New Function

1. **Declare** in appropriate header file (`include/mylib/*.hpp`)
2. **Implement** in corresponding source file (`src/*.cpp`)
3. **Test** by creating tests in `tests/test_*.cpp`
4. **Build and verify** with `cmake --build build && ctest --test-dir build`

### Creating a New Module

1. Create header file: `include/mylib/your_module.hpp`
2. Create implementation: `src/your_module.cpp`
3. Add to CMakeLists.txt library sources
4. Create tests: `tests/test_your_module.cpp`
5. Add tests to CMakeLists.txt test executable

## CI/CD Pipeline

The project includes a GitHub Actions workflow that:
- Builds on Ubuntu, macOS, and Windows
- Tests both Debug and Release configurations
- Runs all unit tests automatically
- Executes example program to verify integration

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Make your changes
4. Run tests to ensure nothing breaks
5. Commit your changes (`git commit -m 'Add amazing feature'`)
6. Push to the branch (`git push origin feature/amazing-feature`)
7. Open a Pull Request

## License

This project is a practice sandbox and is available for educational purposes.

## Learning Resources

- [Modern C++ Best Practices](https://github.com/cpp-best-practices/cppbestpractices)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [Google Test Documentation](https://google.github.io/googletest/)
- [GitHub Actions Documentation](https://docs.github.com/en/actions)
