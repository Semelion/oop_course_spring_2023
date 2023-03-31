#cmake_minimum_required(VERSION 3.24)

add_library(array_t src/array_t.cpp include/array_t/array_t.hpp)

target_include_directories(array_t PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS array_t)

set(CMAKE_CXX_STANDARD 20)

