#include <graphicsmanager.h>
#include <SDL.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl.h>
#include <backends/imgui_impl_sdlrenderer.h>
#include <math/mat22.h>
#include <math/mathutils.h>
#include <iostream>
#include <vector>

GraphicsManager::GraphicsManager()
{

}

GraphicsManager::~GraphicsManager()
{

}

void GraphicsManager::init(std::string name, int w, int h)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsLight();

    ImGui_ImplSDL2_InitForSDLRenderer(window);
    ImGui_ImplSDLRenderer_Init(renderer);
}

void GraphicsManager::terminate()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GraphicsManager::clear(int r=0, int g=0, int b=0, int a=0) const
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
}

void GraphicsManager::display() const
{
    ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
    SDL_RenderPresent(renderer);
}

void GraphicsManager::enableGUI()
{
    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
}

void GraphicsManager::drawRectFilled(const math::Vector2 &origin_position, const int & width, const int & height, const Color & color, const float & rotation_degrees, const math::Vector2 & scale) const
{
    SDL_FRect resultantPosition;
    resultantPosition.x = origin_position.x - ((float)width) * scale.x/ 2.0f;
    resultantPosition.y = origin_position.y - ((float)height) * scale.y / 2.0f;
    resultantPosition.w = (float)width;
    resultantPosition.h = (float)height;

    SDL_Texture * target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, (int)((float)width * scale.x), (int)((float)height * scale.y));
    SDL_SetRenderTarget(renderer, target);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, NULL);

    SDL_RenderCopyExF(renderer, target, NULL, &resultantPosition, rotation_degrees, NULL, SDL_FLIP_NONE);

    SDL_DestroyTexture(target);
    target = nullptr;   
}

void GraphicsManager::drawRectOutline(const math::Vector2 &origin_position, const int & width, const int & height, const Color & color, const float & rotation_degrees, const math::Vector2 & scale) const
{
    SDL_FRect resultantPosition;
    resultantPosition.x = origin_position.x - ((float)width) * scale.x/ 2.0f;
    resultantPosition.y = origin_position.y - ((float)height) * scale.y / 2.0f;
    resultantPosition.w = (float)width;
    resultantPosition.h = (float)height;

    SDL_Texture * target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, (int)((float)width * scale.x), (int)((float)height * scale.y));
    SDL_SetRenderTarget(renderer, target);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer, NULL);
    SDL_SetRenderTarget(renderer, NULL);

    SDL_RenderCopyExF(renderer, target, NULL, &resultantPosition, rotation_degrees, NULL, SDL_FLIP_NONE);

    SDL_DestroyTexture(target);
    target = nullptr; 
}

void GraphicsManager::drawPoint(const math::Vector2 &position, const Color & color, const float &pointSize) const
{
    SDL_RenderSetScale(renderer, pointSize, pointSize);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    //The scaling also affects positioning, so we have to remove the effect of pointSize on the position
    SDL_RenderDrawPointF(renderer, position.x/pointSize, position.y/pointSize);
    SDL_RenderSetScale(renderer, 1.0f, 1.0f);
}

void GraphicsManager::drawLine(const math::Vector2& start, const math::Vector2& end, const Color& color, const float& thickness) const
{
    SDL_RenderSetScale(renderer, thickness, thickness);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLineF(renderer, start.x/thickness, start.y/thickness, end.x/thickness, end.y/thickness);
    SDL_RenderSetScale(renderer, 1.0f, 1.0f);
}

void GraphicsManager::drawCircleOutline(const math::Vector2 &origin_position, float radius, const Color & color, const int& numSegments) const
{
    //360 degrees in a circle
    const float TWOPI = 6.2831853f;
    float step = TWOPI / (float)numSegments;

    /* Allocate the space for the lines here, we add an extra point to enable the formation of a closed loop*/
    SDL_FPoint * points = new SDL_FPoint[numSegments + 1];

    SDL_FPoint temp;

    for(int i = 0; i < numSegments; ++i)
    {
        temp.x = radius * std::cosf(step * (float)i) + origin_position.x;
        temp.y = radius * std::sinf(step * (float)i) + origin_position.y;
        points[i] = temp;
    }

    /* Manually add the final point to close the loop - we don't have to calculate it as cos 360 = 1 and sin 360 = 0 */
    temp.x = radius + origin_position.x;
    temp.y = 0 + origin_position.y;
    points[numSegments] = temp;

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLinesF(renderer, points, numSegments + 1);

    delete [] points;
}
