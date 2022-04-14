cmake_minimum_required(VERSION 3.16)

project(engine)

add_library(${PROJECT_NAME} STATIC)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)

target_sources(${PROJECT_NAME} PRIVATE src/Board.cpp src/Solver.cpp src/Checker.cpp src/Validator.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE logger)