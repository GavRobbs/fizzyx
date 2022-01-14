#ifndef VECTOR_2_H
#define VECTOR_2_H

namespace math
{
    struct Vector2
    {
        float x{0.0f};
        float y{0.0f};

        Vector2();
        Vector2(float _x, float _y);

        Vector2 operator+(const Vector2 &other);
        Vector2 operator-(const Vector2 &other);
        Vector2 operator*(const float& other);

        /* Not exactly the strictest in terms of mathematical notation, but for convenience */
        Vector2 operator/(const float& other);

        bool operator==(const Vector2 &other);
        bool operator!=(const Vector2 &other);

        float getLength();
        float getLengthSquared();
        void normalize();
        Vector2 getNormalized();

        static float dotProduct(const Vector2 &v1, const Vector2 &v2);
        static float distanceSquared(const Vector2 &v1, const Vector2 &v2);
        static float distance(const Vector2 &v1, const Vector2 &v2);

    };

}

math::Vector2 operator*(const float &val, const math::Vector2 &vec);




#endif