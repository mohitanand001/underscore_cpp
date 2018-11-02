cmake_minimum_required(VERSION 3.8)
project(underscore CXX)

include_directories("src")

set(SOURCE_FILES
        src/underscore.hpp
        )

set(FORMATTABLE_TEST_FILES
        tests/testing.cpp
        tests/test_includes.hpp)

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

# check if clang-format is available
find_program(
  CLANG_FORMAT_EXE
  NAMES "clang-format"
  DOC "Path to clang-format executable"
  )
if(NOT CLANG_FORMAT_EXE)
  message(STATUS "clang-format not found.")
else()
  message(STATUS "clang-format found: ${CLANG_FORMAT_EXE}")
  set(DO_CLANG_FORMAT "${CLANG_FORMAT_EXE}" "-i -style=file")
endif()

# add custom target "clang-format-project-files"
# If you want to do a clang-format on a build before committing code invoke
# `make clang-format-project-files`
function(prepend var prefix)
  set(listVar "")

  foreach(f ${ARGN})
    list(APPEND listVar "${prefix}/${f}")
  endforeach()

  set(${var} "${listVar}" PARENT_SCOPE)
endfunction() #prepend(<files to format>)

if(CLANG_FORMAT_EXE)
  prepend(FILES_TO_FORMAT ${CMAKE_CURRENT_SOURCE_DIR} ${SOURCE_FILES})
  prepend(FILES_TO_FORMAT ${CMAKE_CURRENT_SOURCE_DIR} ${FORMATTABLE_TEST_FILES})

  add_custom_target(
    clang-format-project-files
    COMMAND ${CLANG_FORMAT_EXE} -i -style=file ${FILES_TO_FORMAT}
  )
endif()

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

