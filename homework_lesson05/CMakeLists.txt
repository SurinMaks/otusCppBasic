set(PROJ_NAME "guess_the_number")
set(MAIN_FILE "main.cpp")

set(FUNC_NAME_RANDOM_VALUE "random_value")
set(MAIN_FILE_RANDOM_VALUE "random_value.cpp")

set(FUNC_NAME_INPUT_DATA "input_data")
set(MAIN_FILE_INPUT_DATA "input_data.cpp")

set(FUNC_NAME_RESULT "result")
set(MAIN_FILE_RESULT "result.cpp")

SET(STANDARD "cxx_std_17")

set(HPP_DIR "../include")

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE ${STANDARD})

cmake_minimum_required(VERSION 3.12)

project(${PROJ_NAME} VERSION 2.3)

add_subdirectory(src)

add_executable(${PROJ_NAME} ${MAIN_FILE})

target_link_libraries(${PROJ_NAME} PUBLIC ${FUNC_NAME_RANDOM_VALUE} compiler_flags)
target_link_libraries(${PROJ_NAME} PUBLIC ${FUNC_NAME_INPUT_DATA} compiler_flags)
target_link_libraries(${PROJ_NAME} PUBLIC ${FUNC_NAME_RESULT} compiler_flags)

target_include_directories(${PROJ_NAME} PUBLIC ${PROJECT_BINARY_DIR})