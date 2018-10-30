cmake_minimum_required(VERSION 3.8)
project(underscore CXX)

include_directories("src")

set(SOURCE_FILES
        src/underscore.hpp
        )

if (CMAKE_CXX_COMPILER_ID MATCHES Clang)
    add_compile_options(
            -Weverything
            -Wno-c++98-compat
            -Wno-padded
            -Wno-global-constructors
            -Wno-exit-time-destructors
            -Wno-weak-vtables
            -Wundefined-func-template)
endif ()

# shared library libunderscore_shared
add_library(underscore_shared SHARED ${SOURCE_FILES})

# linker settings
set_target_properties(underscore_shared PROPERTIES LINKER_LANGUAGE CXX)

# compiler settings
target_compile_features(underscore_shared PUBLIC cxx_std_11)


# Catch2 (v2.4.2) based Unit Tests
set(TEST_FILES
        tests/catch.hpp
        tests/testing.cpp
        tests/tests_main.cpp)

add_executable(underscore_tests ${SOURCE_FILES} ${TEST_FILES})

target_include_directories(underscore_tests PUBLIC
        src
        tests)

set_target_properties(underscore_tests PROPERTIES LINKER_LANGUAGE CXX)
target_compile_features(underscore_tests PUBLIC cxx_std_11)

