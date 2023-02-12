#include "fizzyx/math/vector2.h"
#include "fizzyx/math/mathutils.h"
#include <sstream>
#include <stdexcept>

using namespace math;

#include <cmath>

Vector2::Vector2():x{0.0f}, y{0.0f}
{

}

Vector2::Vector2(float _x, float _y):x{_x}, y{_y}
{

}

Vector2 Vector2::operator+(const Vector2 &other)
{
    return Vector2{x + other.x, y + other.y};
}

Vector2 Vector2::operator-(const Vector2 &other)
{
    return Vector2{x - other.x, y - other.y};
}

Vector2 Vector2::operator*(const float& other)
{
    return Vector2{x * other, y * other};
}

Vector2 Vector2::operator/(const float& other)
{
    return Vector2{x / other, y / other};
}

bool Vector2::operator==(const Vector2 &other)
{
    bool x_diff = compareFloats(x, other.x);
    bool y_diff = compareFloats(y, other.y);

    return x_diff && y_diff;

}
        
bool Vector2::operator!=(const Vector2 &other)
{
    return !(*this == other);
}

float Vector2::getLengthSquared()
{
    return x * x + y * y;
}

float Vector2::getLength()
{
    return std::sqrtf(getLengthSquared());
}

void Vector2::normalize()
{
    float len = getLength();
    x /= len;
    y /= len;
}

Vector2 Vector2::getNormalized()
{
    Vector2 temp = *this;
    temp.normalize();
    return temp;
}

float Vector2::dotProduct(const Vector2 &v1, const Vector2 &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

float Vector2::distanceSquared(const Vector2 &v1, const Vector2 &v2)
{
    float x_dist = v2.x - v1.x;
    float y_dist = v2.y - v1.y;

    return x_dist * x_dist + y_dist * y_dist;
}

float Vector2::distance(const Vector2 &v1, const Vector2 &v2)
{
    return std::sqrtf(distanceSquared(v1, v2));
}

math::Vector2 operator*(const float &val, const math::Vector2 &vec)
{
    return Vector2{vec.x * val, vec.y * val};
}

void Vector2::operator+=(const Vector2 &other)
{
    x += other.x;
    y += other.y;
}

void Vector2::operator-=(const Vector2 &other)
{
    x -= other.x;
    y -= other.y;
}

void Vector2::operator*=(const float &other)
{
    x *= other;
    y *= other;
}

void Vector2::operator/=(const float &other)
{
    x /= other;
    y /= other;
}

float& Vector2::operator[](const int& index)
{
    if(index == 0)
    {
        return x;
    } else if(index == 1)
    {
        return y;
    } else
    {
        std::stringstream errorstream{};
        errorstream << "Vector index " << index << " is out of range";

        throw std::out_of_range{errorstream.str()};
    }

}

const float& Vector2::operator[](const int& index) const
{
    if(index == 0)
    {
        return x;
    } else if(index == 1)
    {
        return y;
    } else
    {
        std::stringstream errorstream{};
        errorstream << "Vector index " << index << " is out of range";

        throw std::out_of_range{errorstream.str()};
    }

}