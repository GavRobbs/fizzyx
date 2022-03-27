#include <collision/box.h>

using namespace fizzyx::collision;

std::uint8_t OBB::getShapeTypeId()
{
    return 2;
}

AABB::AABB():width{1.0f}, height{1.0f}
{

}

AABB::AABB(const float &w, const float& h):width(w), height(h)
{

}

AABB::AABB(const math::Vector2 &top_left, const math::Vector2 &bottomRight)
{
    width = bottomRight.x - top_left.x;
    height = bottomRight.y - top_left.y;
}

std::uint8_t AABB::getShapeTypeId()
{
    return 1;
}