add_library(arrayt INTERFACE include/arrayt/arrayt.hpp)
set_property(TARGET arrayt PROPERTY CXX_STANDARD 20)
target_include_directories(arrayt PUBLIC INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS arrayt)
