cmake_minimum_required(VERSION 3.0)
project(apue_code)

set(SRC ${PROJECT_SOURCE_DIR}/common/error.c ${PROJECT_SOURCE_DIR}/common/log.c)
set(HEAD ${PROJECT_SOURCE_DIR}/common)

add_subdirectory(ch01)
add_subdirectory(ch02)
add_subdirectory(ch03)
add_subdirectory(ch04)
