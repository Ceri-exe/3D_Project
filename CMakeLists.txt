#### #### #### #### #### #### SETUP #### #### #### #### #### ####
# Minimum required version of CMake.
cmake_minimum_required(VERSION 3.10)

# Project name.
project(3D_Project)

# Use c++23.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#### #### #### #### #### #### SETUP #### #### #### #### #### ####

# Create a library out of the backend code.
add_library(Rasterizer
    src/Framebuffer.cpp
)

# Add include dir.
target_include_directories(Rasterizer PUBLIC inc)

# Create executable file named "rasterizer".
add_executable(rasterizer main.cpp)

# Link Server libraries to the exectuable.
target_link_libraries(rasterizer PRIVATE Rasterizer)
