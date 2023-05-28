add_executable(course_work main.cpp)
target_link_libraries(course_work PRIVATE nlohmann_json::nlohmann_json)

install(DIRECTORY src/ DESTINATION ${CMAKE_INSTALL_BINDIR}/)