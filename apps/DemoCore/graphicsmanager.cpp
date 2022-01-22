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
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
}

void GraphicsManager::terminate()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GraphicsManager::clear(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
}

void GraphicsManager::display()
{
    SDL_RenderPresent(renderer);
}