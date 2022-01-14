#ifndef VECTOR_3_H
#define VECTOR_3_H

namespace math
{
    struct Vector3
    {
        float x{0.0f};
        float y{0.0f};
        float z{0.0f};

        Vector3();
        Vector3(float _x, float _y, float _z);

        Vector3 operator+(const Vector3 &other);
        Vector3 operator-(const Vector3 &other);
        Vector3 operator*(const float& other);

        /* Not exactly the strictest in terms of mathematical notation, but for convenience */
        Vector3 operator/(const float& other);

        bool operator==(const Vector3 &other);
        bool operator!=(const Vector3 &other);

        float getLength();
        float getLengthSquared();
        void normalize();
        Vector3 getNormalized();

        static float dotProduct(const Vector3 &v1, const Vector3 &v2);
        static Vector3 crossProduct(const Vector3 &v1, const Vector3 &v2);
        static float distanceSquared(const Vector3 &v1, const Vector3 &v2);
        static float distance(const Vector3 &v1, const Vector3 &v2);
    };
}

math::Vector3 operator*(const float &val, const math::Vector3 &vec);

#endif