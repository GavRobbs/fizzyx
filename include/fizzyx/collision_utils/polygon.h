#ifndef POLY_COLLISION_SHAPE_H
#define POLY_COLLISION_SHAPE_H

#include "fizzyx/collision_utils/collisionshape.h"
#include "fizzyx/collision_utils/box.h"
#include "fizzyx/collision_utils/circle.h"
#include <vector>

namespace fizzyx::collision
{
    struct Polygon : public ICollisionShape
    {
        std::vector<math::Vector2> points;
        math::Vector2 centroid;

        math::Vector2 getSupportPoint(const math::Vector2 & normal);
        std::vector<math::Vector2> getTransformedPoints(const math::Vector2 &origin, const float &rotation);
        void addPoint(const math::Vector2 &point);

        uint8_t getShapeTypeId() override;

        AABB getBoundingBox(const math::Vector2 &position, const float &rotation);
        Circle getBoundingCircle(const math::Vector2 &position, const float &rotation);
    };
}

#endif