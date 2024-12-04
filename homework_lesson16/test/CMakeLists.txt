set(PROJ_NAME "containers_tests")

set(LIST_TEST_FILE "list_tests.cpp")
set(ARRAY_TEST_FILE "array_tests.cpp")
set(CONTAINERS_TEST_FILE "containers_tests.cpp")

set(FUNC_NAME_MYCONTAINER "MyContainer")
set(MAIN_FILE_MYCONTAINER "MyContainer.cpp")

set(FUNC_NAME_MYLIST "MyList")
set(MAIN_FILE_MYLIST "MyList.cpp")

set(FUNC_NAME_MYARRAY "MyArray")
set(MAIN_FILE_MYARRAY "MyArray.cpp")

cmake_minimum_required(VERSION 3.30)

# add_executable(${PROJ_NAME} ${LIST_TEST_FILE} ${ARRAY_TEST_FILE})
add_executable(${PROJ_NAME} ${CONTAINERS_TEST_FILE} ${LIST_TEST_FILE} ${ARRAY_TEST_FILE}) 

target_link_libraries(${PROJ_NAME} PRIVATE gtest gtest_main)

target_link_libraries(${PROJ_NAME} PUBLIC ${FUNC_NAME_MYCONTAINER} compiler_flags)
target_link_libraries(${PROJ_NAME} PUBLIC ${FUNC_NAME_MYLIST} compiler_flags)
target_link_libraries(${PROJ_NAME} PUBLIC ${FUNC_NAME_MYARRAY} compiler_flags)

target_include_directories(${PROJ_NAME} PUBLIC ${PROJECT_BINARY_DIR})