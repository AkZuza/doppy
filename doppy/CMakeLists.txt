# Doppy Statically Linked library

# get source and header files
file(GLOB_RECURSE doppy_sources src/*.cpp)
file(GLOB_RECURSE doppy_headers include/*.h)

add_library(
    doppy STATIC ${doppy_sources} ${doppy_headers}
)

glad_add_library(glad_gl_core_45 STATIC API gl:core=4.5)

target_include_directories(doppy PUBLIC include ${CMAKE_SOURCE_DIR}/dependencies/glfw/include)
target_link_libraries(doppy PUBLIC glad_gl_core_45 glfw)