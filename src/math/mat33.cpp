#include <mat33.h>
#include <mathutils.h>

using namespace math;

Matrix33::Matrix33():values{1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f}
{

}

Matrix33::Matrix33(float * vals):values{vals[0], vals[1], vals[2], vals[3], vals[4], vals[5], vals[6], vals[7], vals[8]}
{

}

Matrix33 Matrix33::operator+(const Matrix33 &other)
{
    Matrix33 temp{};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            temp(i, j) = (*this)(i, j) + other(i, j);
        }
    }

    return temp;
}

Matrix33 Matrix33::operator-(const Matrix33 &other)
{
    Matrix33 temp{};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            temp(i, j) = (*this)(i, j) - other(i, j);
        }
    }

    return temp;
}

Matrix33 Matrix33::operator*(const Matrix33 & other)
{
    Matrix33 result{};

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                result(i, j) += (*this)(i, k) * other(k, j);
            }

        }
    }

    return result;
}

Matrix33 Matrix33::operator*(const float& other)
{
    Matrix33 temp{};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            temp(i, j) = (*this)(i, j) * other;
        }
    }

    return temp;
}

Vector3 Matrix33::operator*(const Vector3& other)
{
    Vector3 result{};

    for(int i = 0; i < 3; i++)
    {
        result[i] = (*this)(i, 0) * other[0] + (*this)(i, 1) * other[1] + (*this)(i, 2) * other[2];
    }

    return result;
}

Matrix33 Matrix33::operator/(const float& other)
{
    Matrix33 temp{};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            temp(i, j) = (*this)(i, j) / other;
        }
    }

    return temp;
}

bool Matrix33::operator==(const Matrix33 &other)
{
    bool result = true;
    for(size_t i = 0; i < 9; i++)
    {
        result = result && compareFloats(values[i], other.values[i]);
    }

    return result;
}

bool Matrix33::operator!=(const Matrix33 &other)
{
    return !(*this == other);
}

void Matrix33::transpose()
{
    float temp = 0.0f;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == j)
            {
                continue;
            }

            temp = (*this)(i, j);
            (*this)(i, j) = (*this)(j, i);
            (*this)(j, i) = temp;
        }
    }

}

Matrix33 Matrix33::getTranspose()
{
    Matrix33 temp = *this;
    temp.transpose();
    return temp;
}

float Matrix33::determinant()
{
    float firstComponent = (*this)(0, 0) * getMinor(0, 0).determinant();

    float secondComponent = (*this)(0, 1) * getMinor(0, 1).determinant();

    float thirdComponent = (*this)(0, 2) * getMinor(0, 2).determinant();

    return firstComponent + thirdComponent - secondComponent;
}

void Matrix33::invert()
{
    float det = determinant();
    Matrix33 inv = getAdjoint() / det;

    (*this) = inv;
}

Matrix33 Matrix33::getCofactor()
{
    Matrix33 result{};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            result(i, j) = getMinor(i, j).determinant();

            if(((i + j) % 2) == 1)
            {
                result(i, j) *= -1.0f;
            }
        }
    }

    return result;

}

Matrix33 Matrix33::getInverse()
{
    float det = determinant();
    Matrix33 inv = getAdjoint() / det;
    return inv;
}

Matrix33 Matrix33::getAdjoint()
{
    return getCofactor().getTranspose();
}

Matrix33 Matrix33::generateScalingMatrix(float x, float y, float z)
{
    Matrix33 temp = Matrix33::generateIdentityMatrix();
    temp(0,0) = x;
    temp(1,1) = y;
    temp(2,2) = z;

    return temp;
}

Matrix33 Matrix33::generateTranslationMatrix(float x, float y)
{
    Matrix33 temp = Matrix33::generateIdentityMatrix();
    temp(0,2) = x;
    temp(1,2) = y;
    
    return temp;
}

Matrix33 Matrix33::generateIdentityMatrix()
{
    return Matrix33{};
}

Matrix33 Matrix33::generateRotationMatrix(float angle)
{
    Matrix33 temp{};
    temp(0, 0) = cosf(angle);
    temp(0, 1) = -sinf(angle);
    temp(1, 0) = sinf(angle);
    temp(1, 1) = cosf(angle);
    return temp;
}

Matrix33 operator*(const float &val, const math::Matrix33 &mat)
{
    Matrix33 temp{};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            temp(i, j) = mat(i, j) * val;
        }
    }

    return temp;
}

float& Matrix33::operator()(int row, int col)
{
    return values[(row * 3) + col];
}

const float& Matrix33::operator()(int row, int col) const
{
    return values[(row * 3) + col];
}

/* Most vectors fall under two types - position and direction. Direction vectors cannot be translated, but position vectors can. 
This is equivalent to a direction vector having an imaginary third component of 0, and a position vector having one of 1. 
There was no semantic meaning to multiply a 3x3 matrix by a 2d vector, because you can mean either one, so I split it into two separate
functions instead of overloading the operator.*/

Vector2 Matrix33::multiplyAsDirectionVector(const Vector2 &other)
{
    Vector3 temp{other.x, other.y, 0.0f};
    Vector3 tempResult = (*this) * temp;
    return Vector2{tempResult.x, tempResult.y};

}

Vector2 Matrix33::multiplyAsPositionVector(const Vector2 &other)
{
    Vector3 temp{other.x, other.y, 1.0f};
    Vector3 tempResult = (*this) * temp;
    return Vector2{tempResult.x, tempResult.y};

}

Matrix22 Matrix33::getMinor(int row, int col)
{
    float values[] = {0.0f, 0.0f, 0.0f, 0.0f};
    int k = 0;

    for(int i = 0; i < 3; i++)
    {
        if(i == row)
        {
            continue;
        }

        for(int j = 0; j < 3; j++)
        {
            if(j == col)
            {
                continue;
            }

            values[k] = (*this)(i, j);
            k++;
        }
    }

    return Matrix22{values};
}
