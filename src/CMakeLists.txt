set(LibName Fizzyx)
set(CoreName FizzyxCore)
set(CollisionLibName FizzyxCollision)
set(MathLibName MathLibrary)

set(TutorialLibName FizzyxTutorial)
set(TUTORIAL_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/bodies/pointmass.cpp ${CMAKE_CURRENT_SOURCE_DIR}/narrowphasedetectors/nulldetector.cpp ${CMAKE_CURRENT_SOURCE_DIR}/narrowphasedetectors/pointmasscollisiondetector.cpp ${CMAKE_CURRENT_SOURCE_DIR}/narrowphasedetectors/simplecollisiondetector.cpp ${CMAKE_CURRENT_SOURCE_DIR}/solvers/nullsolver.cpp ${CMAKE_CURRENT_SOURCE_DIR}/solvers/simplelinearsolver.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/acceleration/unoptimizedstore.cpp)
set(TUTORIAL_HEADERS ${CMAKE_SOURCE_DIR}/include/bodies/pointmass.h ${CMAKE_SOURCE_DIR}/include/narrowphasedetectors/nulldetector.h ${CMAKE_SOURCE_DIR}/include/narrowphasedetectors/pointmasscollisiondetector.h ${CMAKE_SOURCE_DIR}/include/narrowphasedetectors/simplecollisiondetector.h ${CMAKE_SOURCE_DIR}/include/solvers/nullsolver.h ${CMAKE_SOURCE_DIR}/include/solvers/simplelinearsolver.h ${CMAKE_SOURCE_DIR}/include/acceleration/unoptimizedstore.h)

add_library(${MathLibName} STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/math/vector2.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/math/vector3.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/math/mat22.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/math/mat33.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/math/mathutils.cpp
    ${CMAKE_SOURCE_DIR}/include/fizzyx/math/vector2.h 
    ${CMAKE_SOURCE_DIR}/include/fizzyx/math/vector3.h 
    ${CMAKE_SOURCE_DIR}/include/fizzyx/math/mat22.h 
    ${CMAKE_SOURCE_DIR}/include/fizzyx/math/mat33.h 
    ${CMAKE_SOURCE_DIR}/include/fizzyx/math/mathutils.h
)
target_include_directories(${MathLibName} PRIVATE ${CMAKE_SOURCE_DIR}/include/)

add_library(${CoreName} STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/bodies/physicsentity.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/solvers/physicssolver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/forcegenerators/forcegenerator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/acceleration/accelerationstructure.cpp
    ${CMAKE_SOURCE_DIR}/include/fizzyx/bodies/physicsentity.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/solvers/physicssolver.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/forcegenerators/forcegenerator.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/acceleration/accelerationstructure.h
)
target_link_libraries(${CoreName} PUBLIC MathLibrary)
target_include_directories(${CoreName} PUBLIC ${CMAKE_SOURCE_DIR}/include/)

add_library(${CollisionLibName} STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/collision_utils/collisiondetector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/collision_utils/collisionshape.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/collision_utils/circle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/collision_utils/box.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/collision_utils/polygon.cpp
    ${CMAKE_SOURCE_DIR}/include/fizzyx/collision_utils/collisiondetector.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/collision_utils/collisionshape.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/collision_utils/circle.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/collision_utils/box.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/collision_utils/polygon.h
)
target_link_libraries(${CollisionLibName} PUBLIC FizzyxCore)
target_include_directories(${CollisionLibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/)

add_library(${LibName} STATIC 
    ${CMAKE_SOURCE_DIR}/src/physicsworld.cpp
    ${CMAKE_SOURCE_DIR}/include/fizzyx/physicsworld.h
)
target_include_directories(${LibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(${LibName} PUBLIC FizzyxCore MathLibrary FizzyxCollision)

add_library(${TutorialLibName} STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/bodies/pointmass.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/narrowphasedetectors/nulldetector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/narrowphasedetectors/pointmasscollisiondetector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/narrowphasedetectors/simplecollisiondetector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/solvers/nullsolver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/solvers/simplelinearsolver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/acceleration/unoptimizedstore.cpp
    ${CMAKE_SOURCE_DIR}/include/fizzyx/bodies/pointmass.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/narrowphasedetectors/nulldetector.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/narrowphasedetectors/pointmasscollisiondetector.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/narrowphasedetectors/simplecollisiondetector.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/solvers/nullsolver.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/solvers/simplelinearsolver.h
    ${CMAKE_SOURCE_DIR}/include/fizzyx/acceleration/unoptimizedstore.h
)
target_include_directories(${TutorialLibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(${TutorialLibName} PUBLIC Fizzyx)