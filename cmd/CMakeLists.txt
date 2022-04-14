cmake_minimum_required(VERSION 3.16)

project(cmd)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
        PUBLIC
        src/BoardPrinter.cpp
        include/BoardPrinter.h)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} logger engine cxxopts)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)