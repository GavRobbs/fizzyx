#ifndef MATRIX_22_H
#define MATRIX_22_H

#include <math/vector2.h>

namespace math
{
    struct Matrix22
    {
        /* An empty matrix is initialized to identity */
        float values[4];

        Matrix22();
        Matrix22(float * vals);
        Matrix22(float v11, float v21, float v12, float v22);

        Matrix22 operator+(const Matrix22 &other);
        Matrix22 operator-(const Matrix22 &other);

        Matrix22 operator*(const Matrix22 & other);
        Matrix22 operator*(const float& other);
        Vector2 operator*(const Vector2& other);
        
        Matrix22 operator/(const float& other);

        bool operator==(const Matrix22 &other);
        bool operator!=(const Matrix22 &other);

        float& operator()(int row, int col);
        const float& operator()(int row, int col) const;

        void transpose();
        Matrix22 getTranspose();

        float determinant();

        void invert();
        Matrix22 getInverse();

        static Matrix22 generateRotationMatrix(float angle);
        static Matrix22 generateScalingMatrix(float x, float y);
        static Matrix22 generateIdentityMatrix();
    };

}

math::Matrix22 operator*(const float &val, const math::Matrix22 &mat);


#endif