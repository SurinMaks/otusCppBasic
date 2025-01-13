cmake_minimum_required(VERSION 3.5)

project(smart_pointers)

add_executable(01_lifetime 01_lifetime.cpp)
set_target_properties(01_lifetime PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(02_raw_pointer 02_raw_pointer.cpp)
set_target_properties(02_raw_pointer PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(03_smart_ptr 03_smart_ptr.cpp)
set_target_properties(03_smart_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(04_unique_ptr 04_unique_ptr.cpp)
set_target_properties(04_unique_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(05_shared_ptr 05_shared_ptr.cpp)
set_target_properties(05_shared_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(06_cycle_ref 06_cycle_ref.cpp)
set_target_properties(06_cycle_ref PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(07_weak_ptr 07_weak_ptr.cpp)
set_target_properties(07_weak_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

