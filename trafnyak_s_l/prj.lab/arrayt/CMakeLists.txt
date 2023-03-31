#cmake_minimum_required(VERSION 3.24)

add_library(arrayt src/arrayt.cpp include/arrayt/arrayt.hpp)

target_include_directories(arrayt PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS arrayt)

set(CMAKE_CXX_STANDARD 20)

