#include "fgcomponents.h"
#include "anchoredspringfg.h"
#include "basiccomponents.h"

void SpringRendererComponent::render(float dt)
{
    /* Draws the line that we have used to represent the spring */
    math::Vector2 anchor = getOwner()->getTransform().position;
    graphicsManager.drawRectFilled(anchor - math::Vector2{0, 12.5f}, 400, 25, GraphicsManager::Color{0, 0, 255, 255});

    math::Vector2 endPos = boxMassEntity->getTransform().position;
    endPos -= offset;
    graphicsManager.drawLine(anchor, endPos, line_color);
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

SpringRendererComponent::SpringRendererComponent(const GraphicsManager& _graphics, Entity * massOnEnd, const GraphicsManager::Color& _linecolor):Component(), graphicsManager(_graphics), line_color(_linecolor), boxMassEntity(massOnEnd)
{
}

SpringRendererComponent::~SpringRendererComponent()
{
}

void SpringRendererComponent::setOffset(const math::Vector2& offset)
{
    this->offset = offset;    
}

const math::Vector2 & SpringRendererComponent::getOffset() const
{
    return offset;
}