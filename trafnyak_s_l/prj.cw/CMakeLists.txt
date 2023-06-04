set(CMAKE_TOOLCHAIN_FILE "/home/semelion/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_subdirectory(lib)

add_executable(course_work main.cpp)

target_link_libraries(course_work PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(course_work PRIVATE course_work_lib)

target_include_directories(course_work PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:src>  # <prefix>/include/mylib
        )

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src DESTINATION ${CMAKE_BINARY_DIR})

install(TARGETS course_work DESTINATION bin)

add_custom_target(install_${PROJECT_NAME}
        ${CMAKE_COMMAND} -DCMAKE_INSTALL_CONFIG_NAME=${CMAKE_BUILD_TYPE}
        -P cmake_install.cmake
        )

#configure_file(${source}  ${copy} COPYONLY)
#install(TARGETS src/ DESTINATION bin)

#install(DIRECTORY src/ DESTINATION bin
#        FILES_MATCHING PATTERN "*.txt")

#add_custom_target(copy_target ALL
#        ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_RUNTIME_OUTPUT_DIR}/src
#        DEPENDS course_work
#        COMMENT "Copy neded folder to compiling executable"
#        )
#file(GLOB txt_files "${PROJECT_SOURCE_DIR}/src/*.txt")
#file(GLOB json_files "${PROJECT_SOURCE_DIR}/src/config.json")
#install(TARGETS txt_files DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIR})
#install(TARGETS json_files DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIR})
#install(DIRECTORY src/ DESTINATION ${CMAKE_INSTALL_BINDIR}/)

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
