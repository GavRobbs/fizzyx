#ifndef MATH_UTILITIES_H
#define MATH_UTILITIES_H

#include <float.h>
#include <cmath>
#include <algorithm>

namespace math
{
    //https://stackoverflow.com/questions/17333/what-is-the-most-effective-way-for-float-and-double-comparison
    static bool compareFloats(float A, float B, float epsilon=0.000001f, float VERYSMALL=1.0E-20)
    {
        if(A == B)
        {
            return true;
        }

        float absDiff = std::fabs(A - B);
        if(absDiff < VERYSMALL)
        {
            return true;
        }

        float maxAbs = std::max(fabs(A), fabs(B));
        return (absDiff/maxAbs) < epsilon;
    }

}


#endif