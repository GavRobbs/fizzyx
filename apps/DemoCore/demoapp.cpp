#include <demoapp.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl.h>
#include <backends/imgui_impl_sdlrenderer.h>

DemoApp::DemoApp(std::string windowName, int width, int height)
{
    graphicsManager.init(windowName, width, height);
    sceneManager = SceneManager{};
}

void DemoApp::setup()
{

}

void DemoApp::tearDown()
{

}

void DemoApp::drawGUI()
{

}

void DemoApp::drawScene()
{
    /* DO NOT CLEAR THE SCENE HERE, it is done automatically in the loop */

}
    
DemoApp::~DemoApp()
{
    graphicsManager.terminate();
}
    
void DemoApp::mainLoop()
{
    SDL_Event e;
    lastTime = SDL_GetTicks();

    while(running)
    {
        //This bit of code locks us into 60 fps
        uint32_t newTime = SDL_GetTicks();
        uint32_t delta = newTime - lastTime;
        if(delta < 17)
        {
            continue;
        } else{

            lastTime = newTime;
            dt = ((float)delta) / 1000.0f;
        }
        
        updateLogic();

        while( SDL_PollEvent( &e ) != 0 )
        {
            ImGui_ImplSDL2_ProcessEvent(&e);
            if( e.type == SDL_QUIT )
            {
                running = false;
            } else{
                processEvent(e);
            }
        }

        graphicsManager.enableGUI();
        drawGUI();
        ImGui::Render();
        graphicsManager.clear(0, 0, 0, 0);
        sceneManager.update(dt);
        drawScene();
        graphicsManager.display();

        SDL_Delay(1);
    }
}

void DemoApp::updateLogic()
{
    
}

void DemoApp::processEvent(const SDL_Event &event)
{

}

bool DemoApp::isRunning()
{
    return running;
}

GraphicsManager & DemoApp::getGraphicsManager()
{
    return graphicsManager;
}

SceneManager & DemoApp::getSceneManager()
{
    return sceneManager;
}