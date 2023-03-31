add_executable(array_d_test array_d_test.cpp)
target_link_libraries(array_d_test array_d doctest::doctest)
add_test(NAME array_d_test COMMAND array_d_test)

