enable_testing()

add_executable(
    ir_test
    ir_test.cpp
)

target_link_libraries(
    ir_test
    GTest::gtest_main
    IRLib
)

include(GoogleTest)
gtest_discover_tests(ir_test)
