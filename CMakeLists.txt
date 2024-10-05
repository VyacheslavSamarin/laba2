cmake_minimum_required(VERSION 3.10)

set(CMLIB_AUTHOR_NAME "Вячеслав Самарин" CACHE STRING "")
set(CMLIB_AUTHOR_EMAIL "vyacheslav_samarin@bk.ru" CACHE STRING "")
set(CMLIB_DESCRIPTION "ООП, лабораторная работа номер 2, вариант 3" CACHE STRING "")

project(test VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

set(
    TEST_SOURCES
    include/Octal.hpp
    src/Octal.cpp
    test/test_lab.cpp
)


add_executable(
    lab_1_tests
    ${TEST_SOURCES}
)


target_include_directories(
    lab_1_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
)

target_link_libraries(
    lab_1_tests
    gtest 
    gtest_main
)

enable_testing()

add_test(NAME ProjectTests COMMAND lab_1_tests)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(
        lab_1_tests PRIVATE
        /W4
    )
else ()
    target_compile_options(
        lab_1_tests PRIVATE
        -Wall
        -Wextra
        -Wshadow
        -Wcast-align
        -Wconversion
        -Wsign-conversion
        -Wfloat-equal
        -Wpedantic
        -Werror
        -pedantic
        -O2
    )
endif()