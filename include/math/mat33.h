#ifndef MATRIX_33_H
#define MATRIX_33_H

#include <vector2.h>
#include <vector3.h>

namespace math
{
    struct Matrix33
    {
        /* An empty matrix is initialized to identity */
        float values[9];

        Matrix33();
        Matrix33(float * vals);

        Matrix33 operator+(const Matrix33 &other);
        Matrix33 operator-(const Matrix33 &other);

        Matrix33 operator*(const Matrix33 & other);
        Matrix33 operator*(const float& other);

        Vector2 operator*(const Vector2& other);
        Vector3 operator*(const Vector3& other);
        
        Matrix33 operator/(const float& other);

        bool operator==(const Matrix33 &other);
        bool operator!=(const Matrix33 &other);

        void transpose();
        Matrix33 getTranspose();

        float determinant();

        void invert();
        Matrix33 getInverse();

        Matrix33 getAdjoint();

        static Matrix33 generateScalingMatrix(float x, float y, float z);
        static Matrix33 generateTranslationMatrix(float x, float y);
        static Matrix33 generateIdentityMatrix();

        static Matrix33 generateXRotationMatrix(float angle);
        static Matrix33 generateYRotationMatrix(float angle);
        static Matrix33 generateZRotationMatrix(float angle);
    };

}

math::Matrix33 operator*(const float &val, const math::Matrix33 &mat);


#endif