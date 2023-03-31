add_executable(rational_test rational_test.cpp)
add_executable(array_d_test array_d_test.cpp)

target_link_libraries(rational_test rational doctest::doctest)
target_link_libraries(array_d_test array_d doctest::doctest)

add_test(NAME rational_test COMMAND rational_test)
add_test(NAME array_d_test COMMAND array_d_test)

