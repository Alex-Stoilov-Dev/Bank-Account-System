cmake_minimum_required(VERSION 3.10)
project(Bank-Account)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++23")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable(Bank-Account ${source_files})