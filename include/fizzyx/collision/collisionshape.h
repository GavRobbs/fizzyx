#ifndef COLLISION_SHAPE_H
#define COLLISION_SHAPE_H

#include <collision/collisiondetector.h>
#include <cstdint>

namespace fizzyx::collision
{
    
    struct ICollisionShape
    {
        virtual std::uint8_t getShapeTypeId() = 0;
    };

}

#endif