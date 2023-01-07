#ifndef POINT_MASS_RB_H
#define POINT_MASS_RB_H

#include <bodies/physicsentity.h>
#include <collision_utils/collisionshape.h>
#include <math/vector2.h>

namespace fizzyx::tutorial
{
    /* A point mass physics entity. A point mass is infinitesmally small, but has a mass. This is a good starting point for simulating basic kinematics, without worrying about collision. */
    class PointMassEntity : public fizzyx::core::IPhysicsEntity
    {
        public:

        PointMassEntity();
        virtual ~PointMassEntity();

        PointMassEntity(const PointMassEntity&) = delete;
        PointMassEntity& operator=(const PointMassEntity&) = delete;

        PointMassEntity(PointMassEntity &&other);
        PointMassEntity& operator=(PointMassEntity &&other);

        
        void update(float dt) override;
        fizzyx::collision::ICollisionShape * getBodyShape() override;


        void setPosition(const math::Vector2 &position) override;
        void setVelocity(const math::Vector2 &velocity) override;
        void setAcceleration(const math::Vector2 &acceleration) override;

        math::Vector2 getPosition() override;
        math::Vector2 getVelocity() override;
        math::Vector2 getAcceleration() override;

        math::Vector2 getImpulse() override;
        math::Vector2 getForce() override;

        void applyForce(const math::Vector2 &force) override;
        void setForce(const math::Vector2 &force) override;
        void clearForce();

        void applyImpulse(const math::Vector2 &impulse) override;
        void setImpulse(const math::Vector2 &impulse) override;
        void clearImpulse() override;

        protected:
        math::Vector2 position;
        math::Vector2 velocity;
        math::Vector2 acceleration;
        math::Vector2 impulse;
        math::Vector2 force;
    };
}


#endif