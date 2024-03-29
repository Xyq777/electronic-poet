cmake_minimum_required(VERSION 3.0.0)
project(Electronic-poet VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 99)
add_executable(Electronic-poet main.c)
add_subdirectory(module)
target_link_libraries(Electronic-poet Module)
target_link_libraries(MyExecutable ${CMAKE_SOURCE_DIR}/cgo_poem.so)

