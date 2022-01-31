#include <anchoredspringfg.h>

AnchoredSpringForceGenerator::AnchoredSpringForceGenerator(const math::Vector2 anchorPosition, const float& restLength, const float& springConstant):ForceGenerator("ANCHOREDSPRINGFG", ForceGenerator::FORCE_MODE::IMPULSE), anchorPosition(anchorPosition), restLength(restLength), springConstant(springConstant)
{

}

void AnchoredSpringForceGenerator::update(fizzyx::core::IPhysicsEntity * body, float dt)
{
    /* A vector implementation of Hooke's law takes place here, since the spring is anchored, it is only applied to the body on the end*/
    math::Vector2 distVec = body->getPosition() - offset - anchorPosition;

    float dist = distVec.getLength();

    float magnitude = (restLength - dist) * springConstant;

    if(forceMode == ForceGenerator::FORCE_MODE::FORCE)
    {
        body->applyForce(magnitude * distVec.getNormalized());
    } else
    {
        body->applyImpulse(magnitude * distVec.getNormalized());
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

void AnchoredSpringForceGenerator::setRestLength(const float & restLength)
{
    this->restLength = restLength;
}
    
const float & AnchoredSpringForceGenerator::getRestLength() const
{
    return this->restLength;
}

void AnchoredSpringForceGenerator::setOffset(const math::Vector2& offset)
{
    this->offset = offset;    
}

const math::Vector2 & AnchoredSpringForceGenerator::getOffset() const
{
    return offset;
}