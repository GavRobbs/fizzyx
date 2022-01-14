cmake_minimum_required(VERSION 3.8)

set(ThisName Fizzyx)

project(${ThisName} LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(extern/googletest)
add_subdirectory(src/math)
add_subdirectory(tests)
