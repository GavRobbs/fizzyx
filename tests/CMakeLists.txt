
add_executable(VectorTests vectortests.cpp)
target_link_libraries(VectorTests PRIVATE MathLibrary gtest_main)

add_executable(MatrixTests matrixtests.cpp)
target_link_libraries(MatrixTests PRIVATE MathLibrary gtest_main)

add_test(NAME VectorTests COMMAND VectorTests)
add_test(NAME MatrixTests COMMAND MatrixTests)