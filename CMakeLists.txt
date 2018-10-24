cmake_minimum_required (VERSION 3.8)
project (underscore CXX)

include_directories(.)

set(SOURCE_FILES
    underscore.cpp)

if(CMAKE_CXX_COMPILER_ID MATCHES Clang)
    add_compile_options(
            -Weverything
            -Wno-c++98-compat
            -Wno-padded
            -Wno-global-constructors
            -Wno-exit-time-destructors
            -Wno-weak-vtables)
endif()

# library in shared and static flavors
add_library(underscore_shared SHARED ${SOURCE_FILES})
add_library(underscore_static STATIC ${SOURCE_FILES})

# linker settings
set_target_properties(underscore_shared PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(underscore_static PROPERTIES LINKER_LANGUAGE CXX)

# compiler settings
target_compile_features(underscore_shared PUBLIC cxx_std_11)
target_compile_features(underscore_static PUBLIC cxx_std_11)

# executables for testing, one for testing shared library, another for the static one
# As testing becomes more complex, add test suite here. SUGGESTION: use catch2 for formal unit tests
set(TEST_FILES
    testing.cpp)

add_executable(underscore_shared_tests ${TEST_FILES})
add_executable(underscore_static_tests ${TEST_FILES})

# link the test binaries
set_target_properties(underscore_shared_tests PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(underscore_static_tests PROPERTIES LINKER_LANGUAGE CXX)

target_compile_features(underscore_shared_tests PUBLIC cxx_std_11)
target_compile_features(underscore_static_tests PUBLIC cxx_std_11)

target_link_libraries(underscore_shared_tests underscore_shared)
target_link_libraries(underscore_static_tests underscore_static)

