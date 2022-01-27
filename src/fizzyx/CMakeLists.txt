set(LibName Fizzyx)
set(SOURCES physicsworld.cpp)
set(HEADERS ${CMAKE_SOURCE_DIR}/include/fizzyx/physicsworld.h)

set(CoreName FizzyxCore)
set(CORE_SOURCES core/physicsentity.cpp core/physicssolver.cpp core/forcegenerator.cpp)
set(CORE_HEADERS ../../include/fizzyx/core/physicsentity.h ../../include/fizzyx/core/physicssolver.h ../../include/fizzyx/core/forcegenerator.h)

set(CollisionLibName FizzyxCollision)
set(COLLISION_SOURCES collision/collisiondetector.cpp)
set(COLLISION_HEADERS ../../include/fizzyx/collision/collisiondetector.h)

set(MathLibName MathLibrary)
set(MATH_SOURCES math/vector2.cpp math/vector3.cpp math/mat22.cpp math/mat33.cpp math/mathutils.cpp)
set(MATH_HEADERS ../../include/fizzyx/math/vector2.h ../../include/fizzyx/math/vector3.h ../../include/fizzyx/math/mat22.h ../../include/fizzyx/math/mat33.h ../../include/fizzyx/math/mathutils.h)

set(TutorialName FizzyxTutorial)
set(TutorialSourcesFolder tutorial)
set(TutorialHeadersFolder ../../include/fizzyx/tutorial)
set(TUTORIAL_SOURCES ${TutorialSourcesFolder}/pointmass.cpp ${TutorialSourcesFolder}/nullsolver.cpp ${TutorialSourcesFolder}/nulldetector.cpp)
set(TUTORIAL_HEADERS ${TutorialHeadersFolder}/pointmass.h ${TutorialHeadersFolder}/nullsolver.h ${TutorialHeadersFolder}/nulldetector.h)

add_library(${MathLibName} STATIC ${MATH_SOURCES} ${MATH_HEADERS})
target_include_directories(${MathLibName} PUBLIC ../../include/fizzyx/)

add_library(${CoreName} STATIC ${CORE_SOURCES} ${CORE_HEADERS})
target_link_libraries(${CoreName} PUBLIC MathLibrary FizzyxCollision)
target_include_directories(${CoreName} PUBLIC ../../include/fizzyx/)

add_library(${CollisionLibName} STATIC ${COLLISION_SOURCES} ${COLLISION_HEADERS})
target_link_libraries(${CollisionLibName} PUBLIC FizzyxCore)
target_include_directories(${CollisionLibName} PUBLIC ../../include/fizzyx/)

add_library(${LibName} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${LibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/fizzyx/)
target_link_libraries(${LibName} PUBLIC FizzyxCore MathLibrary FizzyxCollision)

add_library(${TutorialName} STATIC ${TUTORIAL_SOURCES} ${TUTORIAL_HEADERS})
target_include_directories(${LibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/fizzyx)
target_link_libraries(${TutorialName} PUBLIC ${LibName})