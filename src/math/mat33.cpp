#include <mat33.h>

using namespace math;

Matrix33::Matrix33():values{1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f}
{

}

Matrix33::Matrix33(float * vals):values{vals[0], vals[1], vals[2], vals[3], vals[4], vals[5], vals[6], vals[7], vals[8]}
{

}

Matrix33 Matrix33::operator+(const Matrix33 &other)
{
    return Matrix33{};
    
}

Matrix33 Matrix33::operator-(const Matrix33 &other)
{
    return Matrix33{};

}

Matrix33 Matrix33::operator*(const Matrix33 & other)
{
    return Matrix33{};


}

Matrix33 Matrix33::operator*(const float& other)
{
    return Matrix33{};
}

Vector2 Matrix33::operator*(const Vector2& other)
{
    return Vector2{};
}

Vector3 Matrix33::operator*(const Vector3& other)
{
    return Vector3{};
}

Matrix33 Matrix33::operator/(const float& other)
{
    return Matrix33{};
}

bool Matrix33::operator==(const Matrix33 &other)
{
    return false;
}

bool Matrix33::operator!=(const Matrix33 &other)
{
    return false;
}

void Matrix33::transpose()
{

}

Matrix33 Matrix33::getTranspose()
{
    return Matrix33{};
}

float Matrix33::determinant()
{
    return 0.0f;
}

void Matrix33::invert()
{

}

Matrix33 Matrix33::getInverse()
{
    return Matrix33{};
}

Matrix33 Matrix33::getAdjoint()
{
    return Matrix33{};
}

Matrix33 Matrix33::generateScalingMatrix(float x, float y, float z)
{
    return Matrix33{};
}

Matrix33 Matrix33::generateTranslationMatrix(float x, float y)
{
    return Matrix33{};
}

Matrix33 Matrix33::generateIdentityMatrix()
{
    return Matrix33{};
}

Matrix33 Matrix33::generateXRotationMatrix(float angle)
{
    return Matrix33{};
}

Matrix33 Matrix33::generateYRotationMatrix(float angle)
{
    return Matrix33{};
}

Matrix33 Matrix33::generateZRotationMatrix(float angle)
{
    return Matrix33{};
}

Matrix33 operator*(const float &val, const math::Matrix33 &mat)
{
    return Matrix33{};
}