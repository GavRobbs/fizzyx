#include <math/mat22.h>
#include <math/mathutils.h>
#include <cmath>
#include <sstream>
#include <stdexcept>

using namespace math;

Matrix22::Matrix22():values{1.0f, 0.0f, 0.0f, 1.0f}
{

}

Matrix22::Matrix22(float * vals):values{vals[0], vals[1], vals[2], vals[3]}
{

}

Matrix22::Matrix22(float v11, float v21, float v12, float v22):values{v11, v21, v12, v22}
{

}

Matrix22 Matrix22::operator+(const Matrix22 &other)
{
    return Matrix22{
        values[0] + other.values[0],
        values[1] + other.values[1],
        values[2] + other.values[2],
        values[3] + other.values[3],
    };
}

Matrix22 Matrix22::operator-(const Matrix22 &other)
{
    return Matrix22{
        values[0] - other.values[0],
        values[1] - other.values[1],
        values[2] - other.values[2],
        values[3] - other.values[3],
    };
}

Matrix22 Matrix22::operator*(const Matrix22 & other)
{
    float v11 = values[0] * other.values[0] + values[1] * other.values[2];
    float v21 = values[0] * other.values[1] + values[1] * other.values[3];
    float v12 = values[2] * other.values[0] + values[3] * other.values[2];
    float v22 = values[2] * other.values[1] + values[3] * other.values[3];

    return Matrix22{v11, v21, v12, v22};
}

Matrix22 Matrix22::operator*(const float& other)
{
    return Matrix22{values[0] * other, values[1] * other, values[2] * other, values[3] * other};
}

Vector2 Matrix22::operator*(const Vector2& other)
{
    return Vector2{values[0] * other.x + values[1] * other.y, values[2] * other.x + values[3] * other.y};
}

Matrix22 Matrix22::operator/(const float& other)
{
    return Matrix22{values[0] / other, values[1] / other, values[2] / other, values[3] / other};
}

bool Matrix22::operator==(const Matrix22 &other)
{
    bool result = true;
    for(size_t i = 0; i < 4; i++)
    {
        result = result && compareFloats(values[i], other.values[i]);
    }

    return result;

}
        
bool Matrix22::operator!=(const Matrix22 &other)
{
    return !(*this == other);
}

void Matrix22::transpose()
{
    float swap = values[1];
    values[1] = values[3];
    values[3] = swap;
}

Matrix22 Matrix22::getTranspose()
{
    Matrix22 temp = *this;
    temp.transpose();

    return temp;
}

float Matrix22::determinant()
{
    return values[0] * values[3] - values[1] * values[2];
}

void Matrix22::invert()
{
    float det = determinant();
    float v11 = values[3] / det;
    float v21 = -values[2] / det;
    float v12 = -values[1] / det;
    float v22 = values[0] / det;
    
    values[0] = v11;
    values[1] = v21;
    values[2] = v12;
    values[3] = v22;
}

Matrix22 Matrix22::getInverse()
{
    Matrix22 temp = *this;
    temp.invert();

    return temp;
}

 Matrix22 Matrix22::generateRotationMatrix(float angle)
 {
     return Matrix22{
         std::cos(angle),
         -std::sin(angle),
         std::sin(angle),
         std::cos(angle)
     };
 }

Matrix22 Matrix22::generateScalingMatrix(float x, float y)
{
    Matrix22 temp{x, 0.0f, 0.0f, y};
    return temp;
}

Matrix22 Matrix22::generateIdentityMatrix()
{
    Matrix22 temp{1.0f, 0.0f, 0.0f, 1.0f};
    return temp;
}

Matrix22 operator*(const float &val, const Matrix22 &mat)
{
    return Matrix22{mat.values[0] * val, mat.values[1] * val, mat.values[2] * val, mat.values[3] * val};
}

/* There are two versions of the element access operator, one that returns a regular reference you can use to change the value you want
and another one that returns a const reference, for use in value retrieval. I chose to do this instead of overloading the arry index-of operator.*/
float& Matrix22::operator()(int row, int col)
{
    if(row > 1 || col > 1)
    {
        std::stringstream ss;
        ss << "Matrix Row " << row << " Column " << col << "is out of range!";
        throw std::out_of_range{ss.str()};
    }
    return values[(row * 2) + col];
}

const float& Matrix22::operator()(int row, int col) const
{
    if(row > 1 || col > 1)
    {
        std::stringstream ss;
        ss << "Matrix Row " << row << " Column " << col << "is out of range!";
        throw std::out_of_range{ss.str()};
    }
    return values[(row * 2) + col];
}
