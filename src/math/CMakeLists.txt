set(ThisName MathLibrary)

set(SOURCES vector2.cpp vector3.cpp mat22.cpp mat33.cpp)
set(HEADERS vector2.h vector3.h mat22.h mat33.h)

add_library(${ThisName} ${SOURCES} ${HEADERS})
target_include_directories(MathLibrary PUBLIC ../../include/math)