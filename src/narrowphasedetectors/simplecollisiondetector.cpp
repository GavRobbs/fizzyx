#include "fizzyx/narrowphasedetectors/simplecollisiondetector.h"

using namespace fizzyx::tutorial;

fizzyx::collision::ICollisionData * SimpleCollisionDetector::detectCollision(fizzyx::core::IPhysicsEntity * a, fizzyx::core::IPhysicsEntity * b)
{
    for(auto it = entries.begin(); it != entries.end(); ++it)
    {
        int compat = it->isCompatible(a->getBodyShape()->getShapeTypeId(),
                        b->getBodyShape()->getShapeTypeId());

        switch (compat)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                return it->evaluator(a->getBodyShape(), a->getPosition(), a->getRotation(), b->getBodyShape(), b->getPosition(), b->getRotation());
            }
            case -1:
            {
                fizzyx::collision::ICollisionData * result = it->evaluator(a->getBodyShape(), a->getPosition(), a->getRotation(), b->getBodyShape(), b->getPosition(), b->getRotation());
                result->invert();
                return result;
            }   
            default:
                break;
        }
    }
    return nullptr;
}

fizzyx::collision::ICollisionDetector * SimpleCollisionDetector::clone()
{
    SimpleCollisionDetector * detector = new SimpleCollisionDetector;
    return detector;
}