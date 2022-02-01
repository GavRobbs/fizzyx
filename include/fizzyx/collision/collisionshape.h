#ifndef COLLISION_SHAPE_H
#define COLLISION_SHAPE_H

#include <collision/collisiondetector.h>

namespace fizzyx::collision
{
    
    struct ICollisionShape
    {
        virtual uint8_t getShapeTypeId() const = 0;
    };

}

#endif