set(ThisName Fireworks)

add_executable(${ThisName} fireworks.cpp)
target_link_libraries(${ThisName} PUBLIC DemoCore)