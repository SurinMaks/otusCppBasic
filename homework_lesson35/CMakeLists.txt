cmake_minimum_required(VERSION 3.1)

SET(PROJ_NAME "tork_words")

project(${PROJ_NAME} VERSION 0.1.0 LANGUAGES C CXX)

add_executable(${PROJ_NAME} topk_words.cpp func.cpp)