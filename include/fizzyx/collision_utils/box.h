#ifndef BOX_COLLISION_SHAPE_H
#define BOX_COLLISION_SHAPE_H

#include "fizzyx/collision_utils/collisionshape.h"

namespace fizzyx::collision
{
    struct AABB : public ICollisionShape
    {
        std::uint8_t getShapeTypeId() override;

        float width{1.0f};
        float height{1.0f};

        AABB();
        AABB(const float &w, const float& h);
        AABB(const math::Vector2 &top_left, const math::Vector2 &bottomRight);

    };

    struct OBB : public ICollisionShape
    {
        std::uint8_t getShapeTypeId() override;

        float width{1.0f};
        float height{1.0f};
    };
}

#endif