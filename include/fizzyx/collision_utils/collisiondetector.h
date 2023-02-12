#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include "fizzyx/bodies/physicsentity.h"
#include "fizzyx/math/vector2.h"
#include <cstdint>
#include <vector>
#include <functional>
#include "fizzyx/collision_utils/collisionshape.h"



namespace fizzyx::collision
{
    
    struct ICollisionData
    {
        fizzyx::core::IPhysicsEntity * a;
        fizzyx::core::IPhysicsEntity * b;
        math::Vector2 collisionNormal;
        float penetrationDepth;

        virtual void invert();
        virtual float getClosingVelocity();
        virtual std::vector<math::Vector2> getContactPoints();
    };

     /*Quite possibly the worst bit of C++ I've written to date*/
    typedef std::function<ICollisionData*(ICollisionShape*, const math::Vector2&, const float&, ICollisionShape*, const math::Vector2&, const float&)> CollisionDetectorFunction;  

    class ICollisionDetector
    {
        public:
        virtual ICollisionData * detectCollision(fizzyx::core::IPhysicsEntity * a, fizzyx::core::IPhysicsEntity * b) = 0;
        virtual ICollisionDetector * clone() = 0;

        void addDetectorEntry(uint8_t shape1, uint8_t shape2, CollisionDetectorFunction func);

        protected:
        struct CollisionDetectorEntry
        {
            uint8_t shape1{0}, shape2{0};
            int isCompatible(std::uint8_t s1, std::uint8_t s2);
            CollisionDetectorFunction evaluator;
        };

        std::vector<CollisionDetectorEntry> entries;
    };

}


#endif