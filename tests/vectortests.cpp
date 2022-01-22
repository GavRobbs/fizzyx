#include <gtest/gtest.h>
#include <math/vector2.h>
#include <math/vector3.h>

TEST(VectorTests, VectorEquality)
{
    math::Vector2 vec1{1.0f, 3.0f};
    math::Vector2 sameAsVec1{1.0f, 3.0f};
    math::Vector2 notTheSameAsVec1{4.0f, 3.0f};
    ASSERT_TRUE(vec1 == sameAsVec1);
    ASSERT_TRUE(vec1 != notTheSameAsVec1);

    math::Vector3 vec2{53.6f, 3425.2f, 8942.535f};
    math::Vector3 sameAsVec2{53.6f, 3425.2f, 8942.535f};
    math::Vector3 notTheSameAsVec2{11.0f, 343.0f, 945.1231f};
    ASSERT_TRUE(vec2 == sameAsVec2);
    ASSERT_TRUE(vec2 != notTheSameAsVec2);
}

TEST(VectorTests, Vector2BasicOperations)
{
    math::Vector2 firstVec2{1.0f, 3.3f};
    math::Vector2 secondVec2{2.0f, 4.0f};

    math::Vector2 vec2Sum = firstVec2 + secondVec2;
    ASSERT_TRUE(vec2Sum == (math::Vector2{3.0f, 7.3f}));

    math::Vector2 vec2Diff = firstVec2 - secondVec2;
    ASSERT_TRUE(vec2Diff == (math::Vector2{-1.0f, -0.7f}));

    math::Vector2 firstVec2Scaled = firstVec2 * 3.0f;
    ASSERT_TRUE(firstVec2Scaled == (math::Vector2{3.0f, 9.9f}));

    math::Vector2 secondVec2Divided = secondVec2 / 1.5f;
    ASSERT_TRUE(secondVec2Divided == (math::Vector2{1.33333333f, 2.666666666f}));
}

TEST(VectorTests, Vector2AdvancedOperations)
{
    math::Vector2 vec1{2.5f, 1.2f};
    math::Vector2 vec2{5.0f, 6.0f};
    ASSERT_FLOAT_EQ(math::Vector2::dotProduct(vec1, vec2), 19.7f);

    math::Vector2 lengthTestVec{3.0f, 4.0f};
    math::Vector2 normalizedTest = lengthTestVec.getNormalized();
    ASSERT_FLOAT_EQ(lengthTestVec.getLengthSquared(), 25.0f);
    ASSERT_FLOAT_EQ(lengthTestVec.getLength(), 5.0f);

    ASSERT_FLOAT_EQ(math::Vector2::distanceSquared(vec1, vec2), 29.29f);
    ASSERT_FLOAT_EQ(math::Vector2::distance(vec1, vec2), 5.412024f);
}

TEST(VectorTests, Vector3BasicOperations)
{
    math::Vector3 vec1{1.02f, 2.54f, 3.35f};
    math::Vector3 vec2{4.18f, 0.76f, 1.88f};

    math::Vector3 vecSum = vec1 + vec2;
    ASSERT_TRUE(vecSum == (math::Vector3{5.20f, 3.30f, 5.23f}));

    math::Vector3 vecDiff = vec1 - vec2;

    ASSERT_TRUE(vecDiff == (math::Vector3{-3.16f, 1.78f, 1.47f}));

    math::Vector3 vecScaled = 4.0f * vec1;
    ASSERT_TRUE(vecScaled == (math::Vector3{4.08f, 10.16f, 13.4f}));

    math::Vector3 vecDivided = vec1 / 2.0f;
    ASSERT_TRUE(vecDivided == (math::Vector3{0.51f, 1.27f, 1.675f}));
}

TEST(VectorTests, Vector3AdvancedOperations)
{
    math::Vector3 vec1{1.0f, 0.0f, 1.0f};
    math::Vector3 vec2{0.0f, 1.0f, 1.0f};

    ASSERT_FLOAT_EQ(math::Vector3::dotProduct(vec1, vec2), 1.0f);
    ASSERT_TRUE(math::Vector3::crossProduct(vec1, vec2) == (math::Vector3{-1.0f, -1.0f, 1.0f}));

    math::Vector3 lengthTestVec{3.0f, 4.0f, 5.0f};
    math::Vector3 normalizedTest = lengthTestVec.getNormalized();
    ASSERT_FLOAT_EQ(lengthTestVec.getLengthSquared(), 50.0f);
    ASSERT_FLOAT_EQ(lengthTestVec.getLength(), 7.0710678f);

    ASSERT_FLOAT_EQ(math::Vector3::distanceSquared(vec1, vec2), 2.0f);
    ASSERT_FLOAT_EQ(math::Vector3::distance(vec1, vec2), 1.414214f);
}

