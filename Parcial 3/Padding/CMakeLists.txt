cmake_minimum_required(VERSION 3.26)
project(Padding CUDA)

set(CMAKE_CUDA_STANDARD 17)

add_executable(Padding main.cu)

set_target_properties(Padding PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
