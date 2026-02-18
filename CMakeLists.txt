cmake_minimum_required(VERSION 3.14)
project(GitSandbox VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(BUILD_TESTS "Build tests" ON)
option(BUILD_EXAMPLES "Build examples" ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Library
add_library(mylib
    src/math_utils.cpp
    src/string_utils.cpp
)

target_include_directories(mylib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# Example executable
if(BUILD_EXAMPLES)
    add_executable(example
        examples/main.cpp
    )
    target_link_libraries(example PRIVATE mylib)
endif()

# Testing
if(BUILD_TESTS)
    enable_testing()
    
    # Fetch Google Test
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_executable(unit_tests
        tests/test_math_utils.cpp
        tests/test_string_utils.cpp
    )
    
    target_link_libraries(unit_tests
        PRIVATE
        mylib
        gtest_main
        gtest
    )

    include(GoogleTest)
    gtest_discover_tests(unit_tests)
endif()
