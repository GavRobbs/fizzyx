#ifndef POINTMASS_COLLISION_DETECTOR_H
#define POINTMASS_COLLISION_DETECTOR_H

#include <collision/collisiondetector.h>

namespace fizzyx::tutorial
{
    class PointMassCollisionDetector : public fizzyx::collision::ICollisionDetector
    {
        public:
        fizzyx::collision::ICollisionData * detectCollision(fizzyx::core::IPhysicsEntity * a, fizzyx::core::IPhysicsEntity * b) override;
        ICollisionDetector * clone() override;

        void setCollisionRadius(const float & radius);
        float getCollisionRadius() const;

        private:
        float massRadius{10.0f};
    };

    struct PointMassCollisionData : public fizzyx::collision::ICollisionData
    {
        float getClosingVelocity() override;
    };

}

#endif