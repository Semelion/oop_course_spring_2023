set(CMAKE_TOOLCHAIN_FILE "/home/semelion/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_subdirectory(lib)

add_executable(course_work main.cpp)

target_link_libraries(course_work PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(course_work PRIVATE course_work_lib)

install(DIRECTORY src/ DESTINATION ${CMAKE_INSTALL_BINDIR}/)

#add_custom_command(
#        TARGET ${cours_spring_2023}  POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        ${CMAKE_CURRENT_BINARY_DIR}/src/config.json
#        ${CMAKE_CURRENT_BINARY_DIR}/bin/src/config.json)
#
#add_custom_command(
#        TARGET ${cours_spring_2023}  POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        ${CMAKE_CURRENT_BINARY_DIR}/src/function.txt
#        ${CMAKE_CURRENT_BINARY_DIR}/bin/src/function.txt)
#
#add_custom_command(
#        TARGET ${cours_spring_2023}  POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        ${CMAKE_CURRENT_BINARY_DIR}/src/start_of_code.txt
#        ${CMAKE_CURRENT_BINARY_DIR}/bin/src/start_of_code.txt)
