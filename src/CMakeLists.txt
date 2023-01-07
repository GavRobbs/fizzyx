set(LibName Fizzyx)
set(SOURCES ${CMAKE_SOURCE_DIR}/src/physicsworld.cpp)
set(HEADERS ${CMAKE_SOURCE_DIR}/include/physicsworld.h)

set(CoreName FizzyxCore)
set(CORE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/bodies/physicsentity.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/solvers/physicssolver.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/forcegenerators/forcegenerator.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/acceleration/accelerationstructure.cpp")
set(CORE_HEADERS "${CMAKE_SOURCE_DIR}/include/bodies/physicsentity.h" "${CMAKE_SOURCE_DIR}/include/solvers/physicssolver.h" "${CMAKE_SOURCE_DIR}/include/forcegenerators/forcegenerator.h" "${CMAKE_SOURCE_DIR}/include/acceleration/accelerationstructure.h")

set(CollisionLibName FizzyxCollision)
set(COLLISION_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/collision_utils/collisiondetector.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/collision_utils/collisionshape.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/collision_utils/circle.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/collision_utils/box.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/collision_utils/polygon.cpp")
set(COLLISION_HEADERS "${CMAKE_SOURCE_DIR}/include/collision_utils/collisiondetector.h" "${CMAKE_SOURCE_DIR}/include/collision_utils/collisionshape.h" "${CMAKE_SOURCE_DIR}/include/collision_utils/circle.h" "${CMAKE_SOURCE_DIR}/include/collision_utils/box.h" "${CMAKE_SOURCE_DIR}/include/collision_utils/polygon.h")

set(MathLibName MathLibrary)
set(MATH_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/math/vector2.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/math/vector3.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/math/mat22.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/math/mat33.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/math/mathutils.cpp")
set(MATH_HEADERS ${CMAKE_SOURCE_DIR}/include/math/vector2.h ${CMAKE_SOURCE_DIR}/include/math/vector3.h ${CMAKE_SOURCE_DIR}/include/math/mat22.h ${CMAKE_SOURCE_DIR}/include/math/mat33.h ${CMAKE_SOURCE_DIR}/include/math/mathutils.h)

set(TutorialLibName FizzyxTutorial)
set(TUTORIAL_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/bodies/pointmass.cpp ${CMAKE_CURRENT_SOURCE_DIR}/narrowphasedetectors/nulldetector.cpp ${CMAKE_CURRENT_SOURCE_DIR}/narrowphasedetectors/pointmasscollisiondetector.cpp ${CMAKE_CURRENT_SOURCE_DIR}/narrowphasedetectors/simplecollisiondetector.cpp ${CMAKE_CURRENT_SOURCE_DIR}/solvers/nullsolver.cpp ${CMAKE_CURRENT_SOURCE_DIR}/solvers/simplelinearsolver.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/acceleration/unoptimizedstore.cpp)
set(TUTORIAL_HEADERS ${CMAKE_SOURCE_DIR}/include/bodies/pointmass.h ${CMAKE_SOURCE_DIR}/include/narrowphasedetectors/nulldetector.h ${CMAKE_SOURCE_DIR}/include/narrowphasedetectors/pointmasscollisiondetector.h ${CMAKE_SOURCE_DIR}/include/narrowphasedetectors/simplecollisiondetector.h ${CMAKE_SOURCE_DIR}/include/solvers/nullsolver.h ${CMAKE_SOURCE_DIR}/include/solvers/simplelinearsolver.h ${CMAKE_SOURCE_DIR}/include/acceleration/unoptimizedstore.h)

add_library(${MathLibName} STATIC ${MATH_SOURCES} ${MATH_HEADERS})
target_include_directories(${MathLibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/)

add_library(${CoreName} STATIC ${CORE_SOURCES} ${CORE_HEADERS})
target_link_libraries(${CoreName} PUBLIC MathLibrary FizzyxCollision)
target_include_directories(${CoreName} PUBLIC ${CMAKE_SOURCE_DIR}/include/)

add_library(${CollisionLibName} STATIC ${COLLISION_SOURCES} ${COLLISION_HEADERS})
target_link_libraries(${CollisionLibName} PUBLIC FizzyxCore)
target_include_directories(${CollisionLibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/)

add_library(${LibName} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${LibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(${LibName} PUBLIC FizzyxCore MathLibrary FizzyxCollision)

add_library(${TutorialLibName} STATIC ${TUTORIAL_SOURCES} ${TUTORIAL_HEADERS})
target_include_directories(${TutorialLibName} PUBLIC ${CMAKE_SOURCE_DIR}/include/)
target_link_libraries(${TutorialLibName} PUBLIC Fizzyx)