#### #### #### #### #### #### SETUP #### #### #### #### #### ####
# Minimum required version of CMake.
cmake_minimum_required(VERSION 3.20)

# Project name.
project(3D_Project)

# Create a library out of the backend code.
add_library(Rasterizer
    src/Framebuffer.cpp
)

# Add include dir.
target_include_directories(Rasterizer PUBLIC inc)

find_package(X11 REQUIRED)

target_link_libraries(Rasterizer PUBLIC X11::X11)

target_compile_features(Rasterizer PUBLIC cxx_std_23)

target_compile_options(Rasterizer PRIVATE
    -Wall -Wextra -Wpedantic
)

# Create executable file named "rasterizer".
add_executable(rasterizer main.cpp)

# Link Server libraries to the exectuable.
target_link_libraries(rasterizer PRIVATE Rasterizer)

#### #### #### #### #### #### SETUP #### #### #### #### #### ####



# Use c++23.
#set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)