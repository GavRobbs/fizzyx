#ifndef DEMOAPP_H
#define DEMOAPP_H

#include "graphicsmanager.h"
#include "ecs.h"

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

    /* Override this function to initialize the necessary parameters/variables for your demo application */
    virtual void setup();

    /* Override this if you need to clean up anything you've initialized as necessary */
    virtual void tearDown();

    GraphicsManager & getGraphicsManager();
    SceneManager & getSceneManager();

    protected:
    bool running{true};
    GraphicsManager graphicsManager;
    SceneManager sceneManager;

    /* Process input events from SDL in this function */
    virtual void processEvent(const SDL_Event &event);

    /* Draw the IMGUI interface and process inputs to them as necessary */
    virtual void drawGUI();

    /* Do any other drawing you want here that doesn't necessarily pertain to the scene graph */
    virtual void drawScene();

    /* Update any application wide logic as necessary */
    virtual void updateLogic();

    /* Stores the time elapsed since the last frame */
    float dt;

    private:
    uint32_t lastTime;

};

#endif