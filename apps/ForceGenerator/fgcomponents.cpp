#include <fgcomponents.h>
#include <anchoredspringfg.h>
#include <basiccomponents.h>

void SpringRendererComponent::render(float dt)
{
    math::Vector2 anchor = getOwner()->getTransform().position;
    graphicsManager.drawLine(anchor - math::Vector2{-50.0f, 0.0f}, anchor + math::Vector2{-50.0f, 0.0f}, line_color);
    graphicsManager.drawLine(anchor, boxMassEntity->getTransform().position, line_color);
}

void SpringRendererComponent::setEnd(const math::Vector2& end)
{
    Transform t = this->boxMassEntity->getTransform();
    t.position = end;

    this->boxMassEntity->setTransform(t);
}

void SpringRendererComponent::setAnchor(const math::Vector2& anchor)
{
    Transform t = this->getOwner()->getTransform();
    t.position = anchor;

    this->getOwner()->setTransform(t);
}

const math::Vector2& SpringRendererComponent::getAnchor()
{
    return this->getOwner()->getTransform().position;
}

const math::Vector2& SpringRendererComponent::getEnd()
{
    return this->boxMassEntity->getTransform().position;
}

SpringRendererComponent::SpringRendererComponent(const GraphicsManager& _graphics, Entity * massOnEnd, const GraphicsManager::Color& _linecolor, const GraphicsManager::Color& _boxcolor):Component(), graphicsManager(_graphics), line_color(_linecolor), boxMassEntity(massOnEnd)
{
}

SpringRendererComponent::~SpringRendererComponent()
{
}
