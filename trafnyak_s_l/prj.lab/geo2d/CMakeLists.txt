add_library(geo2d geo2d.cpp include/geo2d/geo2d.hpp)
set_property(TARGET geo2d PROPERTY CXX_STANDARD 20)
target_include_directories(geo2d PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS geo2d)