set(ThisName MathLibrary)

set(SOURCES vector2.cpp vector3.cpp mat22.cpp mat33.cpp)
set(HEADERS ../../include/math/vector2.h ../../include/math/vector3.h ../../include/math/mat22.h ../../include/math/mat33.h ../../include/math/mathutils.h)

add_library(${ThisName} ${SOURCES} ${HEADERS})
target_include_directories(${ThisName} PUBLIC ../../include/math/)