#include <anchoredspringfg.h>

AnchoredSpringForceGenerator::AnchoredSpringForceGenerator(const math::Vector2 anchorPosition, float springConstant):ForceGenerator("ANCHOREDSPRINGFG", ForceGenerator::FORCE_MODE::IMPULSE), anchorPosition(anchorPosition), springConstant(springConstant)
{

}

void AnchoredSpringForceGenerator::update(fizzyx::core::IPhysicsEntity * body, float dt)
{

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