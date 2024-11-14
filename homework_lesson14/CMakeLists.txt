SET(PROJ_NAME "List")
SET(ROOT_FILE "main.cpp")

set(FUNC_NAME_MYCONTAINER "MyContainer")
set(MAIN_FILE_MYCONTAINER "MyContainer.cpp")

set(FUNC_NAME_MYLIST "MyList")
set(MAIN_FILE_MYLIST "MyList.cpp")

SET(STANDARD "cxx_std_17")

set(HPP_DIR "../include")
set(SRC_DIR "src")

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE ${STANDARD})

cmake_minimum_required(VERSION 3.10)

project(${PROJ_NAME} VERSION 0.1)

add_subdirectory(${SRC_DIR})

add_executable(${PROJ_NAME} ${ROOT_FILE})

target_link_libraries(${PROJ_NAME} PUBLIC ${FUNC_NAME_MYCONTAINER} compiler_flags)
target_link_libraries(${PROJ_NAME} PUBLIC ${FUNC_NAME_MYLIST} compiler_flags)

target_include_directories(${PROJ_NAME} PUBLIC ${PROJECT_BINARY_DIR})