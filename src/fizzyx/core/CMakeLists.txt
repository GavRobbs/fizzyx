set(ThisName FizzyxCore)
set(SOURCES physicsentity.cpp physicssolver.cpp)
set(HEADERS ../../../include/fizzyx/core/physicsentity.h ../../../include/fizzyx/core/physicssolver.h)

add_library(${ThisName} STATIC ${SOURCES} ${HEADERS})
target_link_libraries(${ThisName} PUBLIC MathLibrary)
target_include_directories(${ThisName} PUBLIC ../../../include/fizzyx/core)