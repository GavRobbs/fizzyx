#include <vector3.h>
#include <mathutils.h>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace math;

#include <cmath>

Vector3::Vector3():x{0.0f}, y{0.0f}, z{0.0f}
{

}

Vector3::Vector3(float _x, float _y, float _z):x{_x}, y{_y}, z{_z}
{

}

Vector3 Vector3::operator+(const Vector3 &other)
{
    return Vector3{x + other.x, y + other.y, z + other.z};
}

Vector3 Vector3::operator-(const Vector3 &other)
{
    return Vector3{x - other.x, y - other.y, z - other.z};
}

Vector3 Vector3::operator*(const float& other)
{
    return Vector3{x * other, y * other, z * other};
}

Vector3 Vector3::operator/(const float& other)
{
    return Vector3{x / other, y / other, z / other};
}

bool Vector3::operator==(const Vector3 &other)
{
    bool x_diff = compareFloats(x, other.x);
    bool y_diff = compareFloats(y, other.y);
    bool z_diff = compareFloats(z, other.z);

    return x_diff && y_diff && z_diff;
}
        
bool Vector3::operator!=(const Vector3 &other)
{
    return !(*this == other);
}

float Vector3::getLengthSquared()
{
    return x * x + y * y + z * z;
}

float Vector3::getLength()
{
    return std::sqrtf(getLengthSquared());
}

void Vector3::normalize()
{
    float len = getLength();
    x /= len;
    y /= len;
    z /= len;
}

Vector3 Vector3::getNormalized()
{
    Vector3 temp = *this;
    temp.normalize();
    return temp;
}

Vector3 Vector3::crossProduct(const Vector3 &v1, const Vector3 &v2)
{
    float x = v1.y * v2.z - v1.z * v2.y;
    float y = v1.z * v2.x - v1.x * v2.z;
    float z = v1.x * v2.y - v1.y * v2.x;
    return Vector3{x, y, z};
}

float Vector3::dotProduct(const Vector3 &v1, const Vector3 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float Vector3::distanceSquared(const Vector3 &v1, const Vector3 &v2)
{
    float x_dist = v2.x - v1.x;
    float y_dist = v2.y - v1.y;
    float z_dist = v2.z - v1.z;

    return x_dist * x_dist + y_dist * y_dist + z_dist * z_dist;
}

float Vector3::distance(const Vector3 &v1, const Vector3 &v2)
{
    return std::sqrtf(distanceSquared(v1, v2));
}

Vector3 operator*(const float &val, const math::Vector3 &vec)
{
    return Vector3{vec.x * val, vec.y * val, vec.z * val};
}

float& Vector3::operator[](const int& index)
{
    if(index == 0)
    {
        return x;
    } else if(index == 1)
    {
        return y;
    } else if(index == 2)
    {
        return z;
    } else
    {
        std::stringstream errorstream{};
        errorstream << "Vector index " << index << " is out of range";

        throw std::out_of_range{errorstream.str()};
    }
}

const float& Vector3::operator[](const int& index) const
{
    if(index == 0)
    {
        return x;
    } else if(index == 1)
    {
        return y;
    } else if(index == 2)
    {
        return z;
    } else
    {
        std::stringstream errorstream{};
        errorstream << "Vector index " << index << " is out of range";

        throw std::out_of_range{errorstream.str()};
    }

    
}