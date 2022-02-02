#include <collision/box.h>

using namespace fizzyx::collision;

std::uint8_t AABB::getShapeTypeId()
{
    return 1;
}

std::uint8_t OBB::getShapeTypeId()
{
    return 2;
}