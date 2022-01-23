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

    void clear(int r, int g, int b, int a);
    void display();

    void enableGUI();
    
    private:
    SDL_Window * window{nullptr};
    SDL_Renderer * renderer{nullptr};
};

#endif