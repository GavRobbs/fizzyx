#include <tutorial/pointmasscollisiondetector.h>
#include <collision/collisiondetector.h>

using namespace fizzyx::tutorial;


fizzyx::collision::ICollisionData * PointMassCollisionDetector::detectCollision(fizzyx::core::IPhysicsEntity * a, fizzyx::core::IPhysicsEntity * b)
{
    /* Two circles are colliding if the distance between them is less than the sum of their radii*/
    float dist = math::Vector2::distance(a->getPosition(), b->getPosition());
    if(dist < (2.0f * massRadius))
    {
        PointMassCollisionData * result = new PointMassCollisionData;
        result->a = a;
        result->b = b;
        result->collisionNormal = (a->getPosition() - b->getPosition()).getNormalized();
        result->penetrationDepth = (2.0f * massRadius) - dist;
        return result;
    } else
    {
        return nullptr;
    }

}

fizzyx::collision::ICollisionDetector * PointMassCollisionDetector::clone()
{
    PointMassCollisionDetector * detector = new PointMassCollisionDetector;
    detector->setCollisionRadius(massRadius);
    return detector;
}

void PointMassCollisionDetector::setCollisionRadius(const float & radius)
{
    massRadius = radius;
}

float PointMassCollisionDetector::getCollisionRadius() const
{
    return massRadius;
}

float PointMassCollisionData::getClosingVelocity()
{
    math::Vector2 velDif = -1.0f * (a->getVelocity() - b->getVelocity());
    math::Vector2 velDir = (a->getPosition() - b->getPosition()).getNormalized();

    return math::Vector2::dotProduct(velDif, velDir);    
}