add_library(generator_IoT lib.cpp course_work.hpp)

target_link_libraries(generator_IoT PRIVATE nlohmann_json::nlohmann_json)

set_property(TARGET generator_IoT PROPERTY CXX_STANDARD 20)
target_include_directories(generator_IoT PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS generator_IoT)