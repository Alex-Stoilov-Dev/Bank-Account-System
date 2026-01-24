# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(bank_account_system)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
add_compile_options(-Wall -Werror)

# Define directories
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/includes")
add_compile_definitions(PROJECT_ROOT="${CMAKE_SOURCE_DIR}")

# Locate MySQL Library and Headers manually to avoid FindMySQL errors
find_library(MYSQL_LIB NAMES mysqlclient)
find_path(MYSQL_INCLUDE_DIR NAMES mysql/mysql.h)

# Compile all source files
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

# Create our executable file
add_executable(bank_account_system ${SRC_FILES})

# Link Include Directories and Libraries
if(MYSQL_LIB AND MYSQL_INCLUDE_DIR)
    # Add your own includes AND the MySQL system includes
    target_include_directories(bank_account_system PRIVATE ${INCLUDE_DIR} ${MYSQL_INCLUDE_DIR})
    # Link the actual library file to the executable
    target_link_libraries(bank_account_system PRIVATE ${MYSQL_LIB})
else()
    message(FATAL_ERROR "Could not find MySQL client library or headers! Make sure the dev package (e.g., libmysqlclient-dev) is installed.")
endif()