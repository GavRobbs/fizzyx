#include <collision_utils/circle.h>

using namespace fizzyx::collision;

Circle::Circle():radius(1.0f)
{

}

Circle::Circle(const float &radius):radius(radius)
{
    
}

std::uint8_t Circle::getShapeTypeId()
{
    return 0;
}
