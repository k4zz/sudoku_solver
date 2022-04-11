cmake_minimum_required(VERSION 3.20)

project(engine)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE src/Board.cpp src/Solver.cpp src/Checker.cpp src/Validator.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE logger)