add_executable(rational_test rational_test.cpp)
add_executable(arrayd_test arrayd_test.cpp)
add_executable(arrayt_test arrayt_test.cpp)

target_link_libraries(rational_test rational doctest::doctest)
target_link_libraries(arrayd_test arrayd doctest::doctest)
target_link_libraries(arrayt_test arrayt doctest::doctest)

add_test(NAME rational_test COMMAND rational_test)
add_test(NAME arrayd_test COMMAND arrayd_test)
add_test(NAME arrayt_test COMMAND arrayt_test)

