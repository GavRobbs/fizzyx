#include <graphicsmanager.h>
#include <SDL.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl.h>
#include <backends/imgui_impl_sdlrenderer.h>
#include <math/mat22.h>
#include <math/mathutils.h>
#include <iostream>

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

void GraphicsManager::clear(int r=0, int g=0, int b=0, int a=0)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
}

void GraphicsManager::display()
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

void GraphicsManager::drawRectFilled(const math::Vector2 &origin_position, const int & width, const int & height, const Color & color, const float & rotation_degrees, const math::Vector2 & scale)
{
    SDL_FRect resultantPosition;
    resultantPosition.x = origin_position.x - ((float)width) * scale.x/ 2.0f;
    resultantPosition.y = origin_position.y - ((float)height) * scale.y / 2.0f;
    resultantPosition.w = (float)width;
    resultantPosition.h = (float)height;

    SDL_Texture * target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, ((float)width) * scale.x, ((float)height) * scale.y);
    SDL_SetRenderTarget(renderer, target);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, NULL);

    SDL_RenderCopyExF(renderer, target, NULL, &resultantPosition, rotation_degrees, NULL, SDL_FLIP_NONE);

    SDL_DestroyTexture(target);
    target = nullptr;   
}

void GraphicsManager::drawRectOutline(const math::Vector2 &origin_position, const int & width, const int & height, const Color & color, const float & rotation_degrees, const math::Vector2 & scale)
{
    SDL_FRect resultantPosition;
    resultantPosition.x = origin_position.x - ((float)width) * scale.x/ 2.0f;
    resultantPosition.y = origin_position.y - ((float)height) * scale.y / 2.0f;
    resultantPosition.w = (float)width;
    resultantPosition.h = (float)height;

    SDL_Texture * target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, ((float)width) * scale.x, ((float)height) * scale.y);
    SDL_SetRenderTarget(renderer, target);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer, NULL);
    SDL_SetRenderTarget(renderer, NULL);

    SDL_RenderCopyExF(renderer, target, NULL, &resultantPosition, rotation_degrees, NULL, SDL_FLIP_NONE);

    SDL_DestroyTexture(target);
    target = nullptr; 
}

void GraphicsManager::drawPoint(const math::Vector2 &position, const Color & color, const float &pointSize)
{
    SDL_RenderSetScale(renderer, pointSize, pointSize);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    //The scaling also affects positioning, so we have to remove the effect of pointSize on the position
    SDL_RenderDrawPointF(renderer, position.x/pointSize, position.y/pointSize);
    SDL_RenderSetScale(renderer, 1.0f, 1.0f);
}

