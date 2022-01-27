#ifndef FORCE_GENERATOR_DEMO_H
#define FORCE_GENERATOR_DEMO_H

#include <demoapp.h>
#include <ecs.h>
#include <SDL.h>
#include <cmath>
#include <algorithm>
#include <tutorial/pointmass.h>
#include <tutorial/nullsolver.h>
#include <tutorial/nulldetector.h>
#include <math/mathutils.h>


class ForceGeneratorDemoApp : public DemoApp
{
    public:
    ForceGeneratorDemoApp();
    virtual ~ForceGeneratorDemoApp();
    void setup() override;
    void tearDown() override;

    protected:
    void processEvent(const SDL_Event &event) override;
    void drawGUI() override;
    void drawScene() override;
    void updateLogic() override;
};

/* A class to draw the box on the end of our spring*/
class BoxRendererComponent : public IRenderable
{
    public:
    void render(float dt) override;
};

/* A class to represent our spring as a line*/
class SpringLineRendererComponent : public IRenderable
{
    public:
    void render(float dt) override;
    void setEnd(const math::Vector2& end);
    void setAnchor(const math::Vector2& anchor);

    private:
    math::Vector2 anchor;
    math::Vector2 end;
};


#endif