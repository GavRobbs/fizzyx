set(ThisName Fizzyx)
set(SOURCES physicsworld.cpp)
set(HEADERS ${CMAKE_SOURCE_DIR}/include/fizzyx/physicsworld.h)

add_subdirectory(core)

add_library(${ThisName} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${ThisName} PUBLIC ${CMAKE_SOURCE_DIR}/include/fizzyx)
target_link_libraries(${ThisName} PUBLIC FizzyxCore MathLibrary)