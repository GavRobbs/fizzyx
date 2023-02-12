
add_executable(VectorTests vectortests.cpp)
target_link_libraries(VectorTests PRIVATE MathLibrary gtest_main)
target_include_directories(VectorTests PRIVATE ${CMAKE_SOURCE_DIR}/include/)

add_executable(MatrixTests matrixtests.cpp)
target_link_libraries(MatrixTests PRIVATE MathLibrary gtest_main)
target_include_directories(MatrixTests PRIVATE ${CMAKE_SOURCE_DIR}/include/)

add_test(NAME VectorTests COMMAND VectorTests)
add_test(NAME MatrixTests COMMAND MatrixTests)