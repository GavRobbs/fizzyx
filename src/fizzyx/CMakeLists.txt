set(LibName Fizzyx)
set(SOURCES physicsworld.cpp)
set(HEADERS ${CMAKE_SOURCE_DIR}/include/fizzyx/physicsworld.h)

set(CoreName FizzyxCore)
set(CORE_SOURCES core/physicsentity.cpp core/physicssolver.cpp)
set(CORE_HEADERS ../../include/fizzyx/core/physicsentity.h ../../include/fizzyx/core/physicssolver.h)

set(MathLibName MathLibrary)

set(MATH_SOURCES math/vector2.cpp math/vector3.cpp math/mat22.cpp math/mat33.cpp)
set(MATH_HEADERS ../../include/fizzyx/math/vector2.h ../../include/fizzyx/math/vector3.h ../../include/fizzyx/math/mat22.h ../../include/fizzyx/math/mat33.h ../../include/fizzyx/math/mathutils.h)

set(TutorialName FizzyxTutorial)
set(TutorialSourcesFolder tutorial)
set(TutorialHeadersFolder ../../include/fizzyx/tutorial)
set(TUTORIAL_SOURCES ${TutorialSourcesFolder}/pointmass.cpp ${TutorialSourcesFolder}/nullsolver.cpp)
set(TUTORIAL_HEADERS ${TutorialHeadersFolder}/pointmass.h ${TutorialHeadersFolder}/nullsolver.h)

add_library(${MathLibName} STATIC ${MATH_SOURCES} ${MATH_HEADERS})
target_include_directories(${MathLibName} PUBLIC ../../include/fizzyx/math/)

add_library(${CoreName} STATIC ${CORE_SOURCES} ${CORE_HEADERS})
target_link_libraries(${CoreName} PUBLIC MathLibrary)
target_include_directories(${CoreName} PUBLIC ../../include/fizzyx/core)

add_library(${LibName} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${LibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/fizzyx)
target_link_libraries(${LibName} PUBLIC FizzyxCore MathLibrary)

add_library(${TutorialName} STATIC ${TUTORIAL_SOURCES} ${TUTORIAL_HEADERS})
target_include_directories(${LibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/fizzyx)
target_link_libraries(${TutorialName} PUBLIC ${LibName})