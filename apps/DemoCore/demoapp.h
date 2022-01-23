#ifndef DEMOAPP_H
#define DEMOAPP_H

#include <graphicsmanager.h>
#include <string>
#include <imgui.h>
#include <backends/imgui_impl_sdl.h>
#include <backends/imgui_impl_sdlrenderer.h>

class DemoApp
{
    public:
    DemoApp(std::string windowName, int width, int height);
    virtual ~DemoApp();
    void mainLoop();
    bool isRunning();

    virtual void setup();
    virtual void tearDown();

    protected:
    bool running{true};
    GraphicsManager graphicsManager;

    virtual void processEvent(const SDL_Event &event);
    virtual void drawGUI();
    virtual void drawScene();
    virtual void updateLogic();

};

#endif