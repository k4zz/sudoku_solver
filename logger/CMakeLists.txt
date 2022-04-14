cmake_minimum_required(VERSION 3.16)

project(logger)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)

target_compile_options(${PROJECT_NAME} INTERFACE -Wall -Wextra -pedantic -Werror)