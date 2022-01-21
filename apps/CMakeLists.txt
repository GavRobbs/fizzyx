set(ThisName DemoCore)

set(SOURCES DemoCore/demoapp.cpp DemoCore/ecs.cpp DemoCore/graphicsmanager.cpp)
set(HEADERS DemoCore/demoapp.h DemoCore/ecs.h DemoCore/graphicsmanager.h)

add_library(${ThisName} STATIC ${SOURCES} ${HEADERS})
target_link_libraries(${ThisName} PUBLIC MathLibrary Fizzyx)
target_include_directories(${ThisName} PUBLIC DemoCore/)

add_subdirectory(Fireworks/)