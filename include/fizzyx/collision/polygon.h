#ifndef POLY_COLLISION_SHAPE_H
#define POLY_COLLISION_SHAPE_H

#include <collision/collisionshape.h>
#include <vector>

namespace fizzyx::collision
{
    struct Polygon : public ICollisionShape
    {
        std::vector<math::Vector2> points;

        uint8_t getShapeTypeId() const override;
    };
}

#endif