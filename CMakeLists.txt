cmake_minimum_required(VERSION 3.16)

project(SudokuSolver
        VERSION 0.1
        LANGUAGES CXX)

option(TESTS_ENABLE "" ON)

add_subdirectory(3rdparty/cxxopts)
add_subdirectory(logger)
add_subdirectory(cmd)
add_subdirectory(app)
add_subdirectory(engine)

if (${TESTS_ENABLE})
    add_subdirectory(3rdparty/googletest)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif ()