cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(claudio VERSION 0.1.0 LANGUAGES C CXX)

# Package Discovery
find_package(clipp CONFIG REQUIRED)

# File Discovery
file(GLOB_RECURSE SRC  ${PROJECT_SOURCE_DIR}/src/*.cpp )

# Add executables
add_executable(claudio ${SRC})

# Link libraries
target_link_libraries(claudio PRIVATE clipp::clipp)
