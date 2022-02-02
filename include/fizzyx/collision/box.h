#ifndef BOX_COLLISION_SHAPE_H
#define BOX_COLLISION_SHAPE_H

#include <collision/collisionshape.h>

namespace fizzyx::collision
{
    struct AABB : public ICollisionShape
    {
        std::uint8_t getShapeTypeId() override;

        float width{1.0f};
        float height{1.0f};
    };

    struct OBB : public ICollisionShape
    {
        std::uint8_t getShapeTypeId() override;

        float width{1.0f};
        float height{1.0f};
    };
}

#endif