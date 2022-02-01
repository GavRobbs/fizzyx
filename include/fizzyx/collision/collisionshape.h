#ifndef COLLISION_SHAPE_H
#define COLLISION_SHAPE_H

#include <collision/collisiondetector.h>

namespace fizzyx::collision
{
    
    struct ICollisionShape
    {
        virtual bool canProcess(const std::uint8_t & otherShapeTypeID) = 0;
        virtual ICollisionData * processCollision(const math::Vector2& thisPosition, const float& thisRotation, const ICollisionShape * other, const math::Vector2& otherPosition, const float& otherRotation) = 0;
        virtual uint8_t getShapeTypeId() const = 0;
    };

}

#endif