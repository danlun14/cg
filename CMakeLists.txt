cmake_minimum_required(VERSION 3.13.4)
project(SimpleProject)

set(root ${CMAKE_CURRENT_LIST_DIR})
list(APPEND CMAKE_MODULE_PATH ${root}/cmake)

add_subdirectory(src)