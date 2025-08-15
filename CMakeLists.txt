# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(bank_account_system)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wall -Werror)

# Define directories
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/includes")
add_compile_definitions(PROJECT_ROOT="${CMAKE_SOURCE_DIR}")

# Compiler all source files
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

# Create our executable file
add_executable(bank_account_system ${SRC_FILES})

# Add include directory for header files
target_include_directories(bank_account_system PRIVATE ${INCLUDE_DIR})
