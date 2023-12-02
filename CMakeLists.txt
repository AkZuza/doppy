cmake_minimum_required(VERSION 3.5)
project("Doppy")

# set cpp properties
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)

# set global build directory pattern
# build/bin/(os)-(arch)-(build)/(project-name)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/bin/${CMAKE_SYSTEM}-${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_BUILD_TYPE}/${CMAKE_PROJECT_NAME}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/archive/${CMAKE_SYSTEM}-${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_BUILD_TYPE}/${CMAKE_PROJECT_NAME}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/lib/${CMAKE_SYSTEM}-${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_BUILD_TYPE}/${CMAKE_PROJECT_NAME}")

# add glfw dependency
add_subdirectory(dependencies/glfw)

# set glad library
set(GLAD_SOURCE_DIR ${CMAKE_SOURCE_DIR}/dependencies/glad)
add_subdirectory(${GLAD_SOURCE_DIR}/cmake glad_cmake)

# add doppy library
add_subdirectory(doppy)

# examples
add_subdirectory(examples/hello_world) # to test if this project structure works
add_subdirectory(examples/hello_window)