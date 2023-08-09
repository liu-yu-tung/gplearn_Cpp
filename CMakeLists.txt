cmake_minimum_required(VERSION 3.12)  # Minimum required version of CMake

# Set the project name and version
project(gplearn-Cpp VERSION 1.0)

# Set C++ standard version
set(CMAKE_CXX_STANDARD 20)

# Add an executable target
add_executable(main 
    src/gplearn/functions.cpp
    src/gplearn/fitness.cpp
    src/gplearn/genetic.cpp    
    src/gplearn/_program_node.cpp    
    src/gplearn/_program.cpp    
    src/sklearn/base.cpp
    src/main.cpp
)

target_include_directories(main PRIVATE
    inc
    inc/gplearn
    inc/sklearn
)


# Optionally, you can set additional compiler options
# For example, to enable warnings and optimization:
# if(MSVC)
#     target_compile_options(MyExecutable PRIVATE /W4 /O2)
# else()
#     target_compile_options(MyExecutable PRIVATE -Wall -Wextra -O2)
# endif()

