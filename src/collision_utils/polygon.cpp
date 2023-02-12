#include "fizzyx/collision_utils/polygon.h"
#include <algorithm>

using namespace fizzyx::collision;

std::uint8_t Polygon::getShapeTypeId() 
{
    return 3;
}

math::Vector2 Polygon::getSupportPoint(const math::Vector2 & normal)
{
    auto result = std::max_element(points.begin(), points.end(), [&](const math::Vector2 &p1, const math::Vector2 &p2) {
        return math::Vector2::dotProduct(p1, normal) > math::Vector2::dotProduct(p2, normal);
        });

    return *result;
}

std::vector<math::Vector2> Polygon::getTransformedPoints(const math::Vector2 &position, const float &rotation)
{
    std::vector<math::Vector2> temp_relative_centroid;
    for(auto it = points.begin(); it != points.end(); ++it)
    {
        temp_relative_centroid.push_back(*it - centroid);
    }

    for(std::size_t i = 0; i < temp_relative_centroid.size(); ++i)
    {
        math::Vector2 current = temp_relative_centroid[i];
        math::Vector2 temp{
            current.x * std::cosf(rotation) - current.y * std::sinf(rotation),
            current.x * std::sinf(rotation) + current.y * std::cosf(rotation)};
        temp_relative_centroid[i] = temp + position;
    }

    return temp_relative_centroid;
}

void Polygon::addPoint(const math::Vector2 &point)
{
    float numPoints = (float)points.size();
    math::Vector2 unavgCentroid = centroid * numPoints;
    points.push_back(point);
    centroid = (unavgCentroid + point) / (numPoints + 1.0f);
}

AABB Polygon::getBoundingBox(const math::Vector2 &position, const float &rotation)
{
    float minX = FLT_MAX, minY = FLT_MAX;
    float maxX = -FLT_MAX, maxY = -FLT_MAX;

    auto transformed = getTransformedPoints(position, rotation);

    for(auto it = transformed.begin(); it != transformed.end(); ++it)
    {
        if(it->x < minX)
        {
            minX = it->x;
        }

        if(it->y < minY)
        {
            minY = it->y;
        }

        if(it->x > maxX)
        {
            maxX = it->x;
        }

        if(it->y > maxY)
        {
            maxY = it->y;
        }
    }

    return AABB{math::Vector2{minX, minY}, math::Vector2{maxX, maxY}};
}

Circle Polygon::getBoundingCircle(const math::Vector2 &position, const float &rotation)
{
    auto transformed = getTransformedPoints(position, rotation);

    float minX, minY = FLT_MAX;
    float maxX, maxY = -FLT_MAX;

    for(auto it = transformed.begin(); it != transformed.end(); ++it)
    {
        if(it->x < minX)
        {
            minX = it->x;
        }

        if(it->y < minY)
        {
            minY = it->y;
        }

        if(it->x > maxX)
        {
            maxX = it->x;
        }

        if(it->y > maxY)
        {
            maxY = it->y;
        }
    }

    return Circle{math::Vector2::distance(math::Vector2{minX, minY}, math::Vector2{maxX, maxY}) * 0.5f};
}