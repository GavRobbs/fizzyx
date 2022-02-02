#ifndef CIRCLE_COLLISION_SHAPE_H
#define CIRCLE_COLLISION_SHAPE_H

#include <collision/collisionshape.h>

namespace fizzyx::collision
{
    struct Circle : public ICollisionShape
    {
        std::uint8_t getShapeTypeId() override;

        float radius{1.0f};
    };

}

#endif