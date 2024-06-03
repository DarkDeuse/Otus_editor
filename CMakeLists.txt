cmake_minimum_required(VERSION 3.20) 
project(editor)

add_library(editor_lib INTERFACE)
set_target_properties(editor_lib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(editor_lib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(editor main.cpp)
target_compile_options(editor PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(editor PRIVATE editor_lib)

install(TARGETS editor DESTINATION bin)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake")
include(package)
add_package("editor" "01")
