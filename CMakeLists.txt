cmake_minimum_required(VERSION 3.8)

set(ThisName Fizzyx)

project(${ThisName} LANGUAGES C CXX)

include(CTest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(extern/SDL2)
add_subdirectory(extern/googletest)
add_subdirectory(src/fizzyx)
add_subdirectory(tests)
add_subdirectory(apps)
