#cmake_minimum_required(VERSION 3.24)

add_library(matrixs src/matrixs.cpp include/matrixs/matrixs.hpp)

target_include_directories(matrixs PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS matrixs)

set(CMAKE_CXX_STANDARD 20)

