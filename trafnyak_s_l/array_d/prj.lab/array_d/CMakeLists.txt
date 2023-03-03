cmake_minimum_required(VERSION 3.24)

add_library(array_d array_d.cpp include/array_d/array_d.hpp)

target_include_directories(array_d PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS array_d)

set(CMAKE_CXX_STANDARD 20)

