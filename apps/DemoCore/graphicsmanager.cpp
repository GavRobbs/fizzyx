#include <graphicsmanager.h>
#include <SDL.h>

GraphicsManager::GraphicsManager()
{

}

GraphicsManager::~GraphicsManager()
{

}

void GraphicsManager::init(std::string name, int w, int h)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
}

void GraphicsManager::terminate()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}