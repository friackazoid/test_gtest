cmake_minimum_required(VERSION 3.12)

project(test_gtest)

# generate compile_commands.json; used by YCM
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES}) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Werror)

add_executable(test_gtest main.cpp)

# add gtest


find_package(GTest REQUIRED)
message("PackageName_LIBRARIES: ${GTEST_LIBRARIES}")

add_executable(test_main test_main.cpp)
target_include_directories(test_main PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(
    test_main
    PRIVATE
    GTest::gtest
    GTest::gmock)

enable_testing()
add_test(NAME test_main COMMAND test_main)
