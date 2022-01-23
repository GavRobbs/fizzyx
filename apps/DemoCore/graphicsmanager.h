#ifndef DEMOCORE_GRAPHICS_MANAGER_H
#define DEMOCORE_GRAPHICS_MANAGER_H

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <string>
#include <math/vector2.h>

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


    struct Color
    {
        uint8_t r, g, b, a;
        Color():r(255), g(255), b(255), a(255)
        {

        }
        Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a):r(_r), g(_g), b(_b), a(_a)
        {

        }
    };

    void drawRectFilled(const math::Vector2 &origin_position, const int & width, const int & height, const Color & color, const float & rotation_degrees = 0.0f, const math::Vector2 & scale = math::Vector2{1.0f, 1.0f});

    void drawRectOutline(const math::Vector2 &origin_position, const int & width, const int & height, const Color & color, const float & rotation_degrees = 0.0f, const math::Vector2 & scale = math::Vector2{1.0f, 1.0f});

    void drawPoint(const math::Vector2 &position, const Color & color, const float &pointSize = 4.0f);

    
    private:
    SDL_Window * window{nullptr};
    SDL_Renderer * renderer{nullptr};
};

#endif