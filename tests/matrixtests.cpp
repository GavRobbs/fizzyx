#include <gtest/gtest.h>
#include <mat22.h>
#include <mat33.h>

TEST(MatrixTests, MatrixEquality)
{
    math::Matrix22 mat2{1.0f, 0.0f, 0.0f, 1.0f};
    math::Matrix22 sameAsMat2{1.0f, 0.0f, 0.0f, 1.0f};
    math::Matrix22 notTheSameAsMat2{1.00001f, 0.0005f, 0.0005f, 1.00001f};

    ASSERT_TRUE(mat2 != notTheSameAsMat2);
    ASSERT_TRUE(mat2 == sameAsMat2);

    float identity3x3[] = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    float notidentity3x3[] = {1.000000001f, 0.0000000005f, 0.0000000001f, 0.0f, 1.0000000099f, 0.0f, 0.0f, 0.0f, 1.0f};

    math::Matrix33 mat3{identity3x3};
    math::Matrix33 sameAsMat3{identity3x3};
    math::Matrix33 notTheSameAsMat3{notidentity3x3};
    ASSERT_TRUE(mat3 != notTheSameAsMat3);
    ASSERT_TRUE(mat3 == sameAsMat3);
}

TEST(MatrixTest, MatrixAdditionSubtraction)
{
    math::Matrix22 firstMatrix{1.0f, 0.0f, 3.0f, 1.0f};
    math::Matrix22 secondMatrix{1.0f, 5.0f, 2.0f, 1.0f};
    math::Matrix22 mat2Sum = firstMatrix + secondMatrix;
    math::Matrix22 mat2Diff = firstMatrix - secondMatrix;

    ASSERT_TRUE(mat2Sum == (math::Matrix22{2.0f, 5.0f, 5.0f, 2.0f}));
    ASSERT_TRUE(mat2Diff == (math::Matrix22{0.0f, -5.0f, 1.0f, 0.0f}));

    float vals1[] = {1.0f, 2.0f, 3.0f, -1.0f, 6.0f, 3.2f, 1.8f, 7.9f, 2.3f};
    float vals2[] = {1.8f, 3.6f, -2.2f, -11.3f, 4.756f, 11.21f, 3.0f, 6.1f, 1.0f};

    float expectedSumVals[] = {2.8f, 5.6f, 0.8f, -12.3f, 10.756f, 14.41f, 4.8f, 14.0f, 3.3f};

    float expectedDiffVals[] = {-0.8f, -1.6f, 5.2f, 10.3f, 1.244f, -8.01f, -1.2f, 1.8f, 1.3f};

    math::Matrix33 firstMat3{vals1};
    math::Matrix33 secondMat3{vals2};
    math::Matrix33 mat3Sum = firstMat3 + secondMat3;
    math::Matrix33 mat3Diff = firstMat3 - secondMat3;

    ASSERT_TRUE(mat3Sum == (math::Matrix33{expectedSumVals}));
    ASSERT_TRUE(mat3Diff == (math::Matrix33{expectedDiffVals}));
}

TEST(MatrixTest, MatrixMultiplicationScalar)
{
    math::Matrix22 scalarTest2x2{1.2f, 2.1f, 3.3f, 1.5f};
    ASSERT_TRUE((scalarTest2x2 * 2.0f) == (math::Matrix22{2.4f, 4.2f, 6.6f, 3.0f}));

    float scalarTest3Vals[] = {1.0f, 2.0f, 0.3f, 1.1f, 2.3f, 0.0f, 4.6f, 1.01f, 0.0f};
    float scalarTest3ExpectedResults[] = {3.0f, 6.0f, 0.9f, 3.3f, 6.9f, 0.0f, 13.8f, 3.03f, 0.0f};
    math::Matrix33 scalarTest3x3{scalarTest3Vals};
    ASSERT_TRUE((scalarTest3x3 * 3.0f) == (math::Matrix33{scalarTest3ExpectedResults}));
}

TEST(MatrixTest, MatrixMultiplicationVector)
{

}

TEST(MatrixTest, MatrixMultiplicationMatrix)
{
    
}

TEST(MatrixTest, Matrix22Inverse)
{
    
}

TEST(MatrixTest, Matrix33InverseOperations)
{
    
}

TEST(MatrixTest, Matrix22Generators)
{
    
}

TEST(MatrixTest, Matrix33Generators)
{
    
}