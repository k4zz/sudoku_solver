cmake_minimum_required(VERSION 3.20)

project(test_engine)

add_executable(${PROJECT_NAME} TestEngine.cpp)
target_link_libraries(${PROJECT_NAME} gtest gtest_main engine)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})