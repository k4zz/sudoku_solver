cmake_minimum_required(VERSION 3.20)

project(Tests)

add_executable(${PROJECT_NAME} TestBoard.cpp)
target_link_libraries(${PROJECT_NAME} gtest gtest_main engine)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})