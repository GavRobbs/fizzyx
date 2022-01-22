set(ThisName DemoCore)

set(SOURCES DemoCore/demoapp.cpp DemoCore/ecs.cpp DemoCore/graphicsmanager.cpp)
set(HEADERS DemoCore/demoapp.h DemoCore/ecs.h DemoCore/graphicsmanager.h)

add_library(${ThisName} STATIC ${SOURCES} ${HEADERS})
target_link_libraries(${ThisName} PUBLIC MathLibrary Fizzyx SDL2::SDL2)
target_include_directories(${ThisName} PUBLIC DemoCore/)

add_executable(Fireworks Fireworks/fireworks.cpp)
target_link_libraries(Fireworks PUBLIC DemoCore)