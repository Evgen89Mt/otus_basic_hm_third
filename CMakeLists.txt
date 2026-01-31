cmake_minimum_required(VERSION 3.2)

project(03.home_work)

# stl
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add dir to project
add_subdirectory(lib/wr_file)
add_subdirectory(src)