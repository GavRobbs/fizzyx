#ifndef MATRIX_33_H
#define MATRIX_33_H

#include <math/vector2.h>
#include <math/vector3.h>
#include <math/mat22.h>

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

        Vector3 operator*(const Vector3& other);

        Vector2 multiplyAsDirectionVector(const Vector2 &other);
        Vector2 multiplyAsPositionVector(const Vector2 &other);
        
        Matrix33 operator/(const float& other);

        float& operator()(int row, int col);
        const float& operator()(int row, int col) const;

        bool operator==(const Matrix33 &other);
        bool operator!=(const Matrix33 &other);

        void transpose();
        Matrix33 getTranspose();

        float determinant();

        void invert();
        Matrix33 getInverse();

        Matrix33 getAdjoint();
        Matrix33 getCofactor();

        static Matrix33 generateScalingMatrix(float x, float y, float z);
        static Matrix33 generateTranslationMatrix(float x, float y);
        static Matrix33 generateIdentityMatrix();

        static Matrix33 generateRotationMatrix(float angle);

        private:
        Matrix22 getMinor(int row, int col);
    };

}

math::Matrix33 operator*(const float &val, const math::Matrix33 &mat);


#endif