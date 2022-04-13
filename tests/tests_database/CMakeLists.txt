project(test_database)

file(GLOB test_files_paths
        "*.csv")

if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/include/TestFilesPaths.h)
    file(WRITE include/TestFilesPaths.h
            "#pragma once\n"
            )

    foreach (test_file ${test_files_paths})
        get_filename_component(FILE_VAR ${test_file} NAME_WE)
        string(TOUPPER ${FILE_VAR} FILE_VAR)
        set(LINE "constexpr const char* ${FILE_VAR} = \"${test_file}\"\;\n")
        file(APPEND include/TestFilesPaths.h ${LINE})
    endforeach ()
endif ()

add_library(${PROJECT_NAME} INTERFACE)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

target_include_directories(${PROJECT_NAME} INTERFACE include)

message(STATUS "${PROJECT_NAME}")