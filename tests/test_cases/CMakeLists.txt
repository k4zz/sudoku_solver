cmake_minimum_required(VERSION 3.16)

project(Tests)

add_executable(${PROJECT_NAME} TestBoard.cpp TestValidator.cpp TestSolverBruteForce.cpp TestSolverBruteForcePrio.cpp TestSudokus.cpp)
target_link_libraries(${PROJECT_NAME} gtest gtest_main engine test_database)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
