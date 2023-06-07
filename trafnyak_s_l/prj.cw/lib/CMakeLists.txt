add_library(course_work_lib lib.cpp course_work.hpp)

target_link_libraries(course_work_lib PRIVATE nlohmann_json::nlohmann_json)

set_property(TARGET course_work_lib PROPERTY CXX_STANDARD 20)
target_include_directories(course_work_lib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS course_work_lib)