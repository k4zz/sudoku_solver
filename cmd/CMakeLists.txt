cmake_minimum_required(VERSION 3.20)

project(cmd)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
        PUBLIC
        src/BoardPrinter.cpp
        src/BoardPrinter.h)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(${PROJECT_NAME} logger)