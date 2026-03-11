cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        test
        test.cpp
        ${CMAKE_SOURCE_DIR}/src/utilities/Logger.cpp
)
target_link_libraries(
        test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test)

target_include_directories(test
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src/algorithms
        ${CMAKE_SOURCE_DIR}/src/utilities
)