#ifndef DEMOCORE_GRAPHICS_MANAGER_H
#define DEMOCORE_GRAPHICS_MANAGER_H

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <string>

class GraphicsManager
{
    public:
    GraphicsManager();
    ~GraphicsManager();
    void init(std::string name, int w, int h);
    void terminate();
    
    private:
    SDL_Window * window = nullptr;

};

#endif