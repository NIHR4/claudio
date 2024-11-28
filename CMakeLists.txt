cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(claudio VERSION 0.1.0 LANGUAGES C CXX)

if(CLAUDIO_NOT_INTERACTIVE) 

    add_compile_definitions(CLAUDIO_NOT_INTERACTIVE)

endif()


#defines
add_compile_definitions(WIN32_LEAN_AND_MEAN)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

#building statically
#add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)

# add external build for antlrcpp
include(ExternalAntlr4Cpp)

# add antlr4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# Path discovery
find_path(COLORCONSOLE_INCLUDE_DIRS "colorconsole.hpp")


# Package Discovery
find_package(clipp CONFIG REQUIRED)

# File Discovery
file(GLOB_RECURSE SRC  ${PROJECT_SOURCE_DIR}/src/*.cpp )

# Add executables
add_executable(claudio ${SRC})

# Link libraries
target_link_libraries(claudio PRIVATE clipp::clipp antlr4_shared)

# Target includes
target_include_directories(claudio PRIVATE ${COLORCONSOLE_INCLUDE_DIRS})