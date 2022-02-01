#include <collision/box.h>

using namespace fizzyx::collision;

std::uint8_t AABB::getShapeTypeId() const
{
    return 1;
}

std::uint8_t OBB::getShapeTypeId() const
{
    return 2;
}