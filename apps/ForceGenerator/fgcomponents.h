#ifndef FORCE_GENERATOR_DEMO_COMPONENTS_H
#define FORCE_GENERATOR_DEMO_COMPONENTS_H

#include <ecs.h>
#include <graphicsmanager.h>
#include <physicsworld.h>
#include <tutorial/pointmass.h>

/* A class to represent our spring as a line*/
class SpringRendererComponent : public IRenderable, public Component
{
    public:
    void render(float dt=0.0f) override;

    void setEnd(const math::Vector2& end);
    void setAnchor(const math::Vector2& anchor);

    const math::Vector2& getAnchor();
    const math::Vector2& getEnd();
    
    SpringRendererComponent(const GraphicsManager& _graphics, Entity *massOnEnd, const GraphicsManager::Color& _linecolor, const GraphicsManager::Color& _boxcolor);

    ~SpringRendererComponent();

    private:
    const GraphicsManager& graphicsManager;
    const GraphicsManager::Color line_color;
    const GraphicsManager::Color box_color;

    Entity * boxMassEntity{nullptr};
};

#endif