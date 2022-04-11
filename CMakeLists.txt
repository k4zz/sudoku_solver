cmake_minimum_required(VERSION 3.20)

project(SudokuSolver
        VERSION 0.1
        LANGUAGES CXX)

option(TESTS_ENABLE "" ON)

add_subdirectory(logger)
add_subdirectory(cmd)
add_subdirectory(app)
add_subdirectory(engine)

if (${TESTS_ENABLE})
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif ()