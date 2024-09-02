cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(clarion-pp VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SRC  ${PROJECT_SOURCE_DIR}/src/*.cpp )


add_executable(clarion-pp ${SRC})

