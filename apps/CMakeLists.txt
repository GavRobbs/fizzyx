set(ThisName DemoCore)

set(SOURCES DemoCore/demoapp.cpp DemoCore/ecs.cpp DemoCore/graphicsmanager.cpp DemoCore/basiccomponents.cpp)
set(HEADERS DemoCore/demoapp.h DemoCore/ecs.h DemoCore/graphicsmanager.h DemoCore/basiccomponents.h)

set(IMGUIPATH ../extern/imgui/)
set(GUILibrary_HEADERS ${IMGUIPATH}/imgui.h ${IMGUIPATH}/backends/imgui_impl_sdl.h ${IMGUIPATH}/backends/imgui_impl_sdlrenderer.h)
set(GUILibrary_SOURCES ${IMGUIPATH}/imgui.cpp ${IMGUIPATH}/backends/imgui_impl_sdl.cpp ${IMGUIPATH}/backends/imgui_impl_sdlrenderer.cpp ${IMGUIPATH}/imgui_draw.cpp ${IMGUIPATH}/imgui_tables.cpp ${IMGUIPATH}/imgui_widgets.cpp ${IMGUIPATH}/imgui_demo.cpp)

add_library(${ThisName} STATIC ${SOURCES} ${HEADERS} ${GUILibrary_SOURCES} ${GUILibrary_HEADERS})
target_link_libraries(${ThisName} PUBLIC MathLibrary Fizzyx SDL2::SDL2)
target_include_directories(${ThisName} PUBLIC DemoCore/ ${IMGUIPATH})

add_executable(Fireworks Fireworks/fireworks.cpp Fireworks/particlespawner.cpp Fireworks/fireworkscomponents.cpp Fireworks/particlespawner.h Fireworks/fireworkscomponents.h)
target_link_libraries(Fireworks PUBLIC DemoCore FizzyxTutorial)
target_include_directories(Fireworks PUBLIC DemoCore/ Fireworks/)

add_executable(ForceGenerator ForceGenerator/forcegeneratordemo.cpp ForceGenerator/forcegeneratordemo.h ForceGenerator/anchoredspringfg.cpp ForceGenerator/anchoredspringfg.h)
target_link_libraries(ForceGenerator PUBLIC DemoCore FizzyxTutorial)
target_include_directories(ForceGenerator PUBLIC DemoCore/ ForceGenerator/)