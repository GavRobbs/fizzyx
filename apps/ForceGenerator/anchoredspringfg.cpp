#include <anchoredspringfg.h>
#include <iostream>

AnchoredSpringForceGenerator::AnchoredSpringForceGenerator(const math::Vector2 anchorPosition, const float& restLength, const float& springConstant):ForceGenerator("ANCHOREDSPRINGFG", ForceGenerator::FORCE_MODE::IMPULSE), anchorPosition(anchorPosition), restLength(restLength), springConstant(springConstant)
{

}

void AnchoredSpringForceGenerator::update(fizzyx::core::IPhysicsEntity * body, float dt)
{
    math::Vector2 offset = body->getPosition() - anchorPosition;

    float dist = offset.getLength();

    float magnitude = (restLength - dist) * springConstant;

    std::cout << magnitude << std::endl;

    if(forceMode == ForceGenerator::FORCE_MODE::FORCE)
    {
        body->applyForce(magnitude * offset.getNormalized());
    } else
    {
        body->applyImpulse(magnitude * offset.getNormalized());
    }
}

void AnchoredSpringForceGenerator::setAnchorPosition(const math::Vector2 & anchorPosition)
{
    this->anchorPosition = anchorPosition;
}
    
const math::Vector2 & AnchoredSpringForceGenerator::getAnchorPosition() const
{
    return anchorPosition;
}

void AnchoredSpringForceGenerator::setSpringConstant(const float & springConstant)
{
    this->springConstant = springConstant;
}

const float & AnchoredSpringForceGenerator::getSpringConstant() const
{
    return springConstant;
}