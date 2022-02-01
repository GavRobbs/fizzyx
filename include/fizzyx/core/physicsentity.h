#ifndef FIZZYX_ENTITY_H
#define FIZZYX_ENTITY_H

#include <math/vector2.h>
#include <collision/collisionshape.h>

namespace fizzyx
{
    namespace core
    {
        struct PhysicsMaterial
        {
            float restitution;
            float static_friction;
            float dynamic_friction;
        };

        class IPhysicsEntity
        {
            public:
            virtual void update(float dt) = 0;
            virtual fizzyx::collision::ICollisionShape * getBodyShape() = 0;

            IPhysicsEntity(const IPhysicsEntity&) = delete;
            IPhysicsEntity& operator =(const IPhysicsEntity&) = delete;
            IPhysicsEntity(IPhysicsEntity&& other);
            IPhysicsEntity& operator=(IPhysicsEntity &&other);

            bool operator==(const IPhysicsEntity &other);
            bool operator!=(const IPhysicsEntity &other);

            IPhysicsEntity();
            virtual ~IPhysicsEntity();

            void setID(unsigned int id);
            unsigned int getID();

            virtual math::Vector2 getPosition();
            virtual math::Vector2 getVelocity();
            virtual math::Vector2 getAcceleration();
            virtual float getAngularVelocity();
            virtual float getAngularAcceleration();
            
            virtual math::Vector2 getImpulse();
            virtual math::Vector2 getForce();
            virtual float getImpulsiveTorque();
            virtual float getTorque();
          
            float getMass();
            float getInverseMass();
            void setMass(const float &mass);


            float getGravity();
            void setGravity(const float &gravity);

            virtual void setPosition(const math::Vector2 &position);
            virtual void setVelocity(const math::Vector2 &velocity);
            virtual void setAcceleration(const math::Vector2 &acceleration);
            virtual void setAngularVelocity(const float &angVel);
            virtual void setAngularAcceleration(const float &angAccel);

            virtual void applyForce(const math::Vector2 &force);
            virtual void setForce(const math::Vector2 &force);
            virtual void clearForce();

            virtual void applyImpulse(const math::Vector2 &impulse);
            virtual void setImpulse(const math::Vector2 &impulse);
            virtual void clearImpulse();

            virtual void applyImpulsiveTorque(const float &itorque);
            virtual void setImpulsiveTorque(const float &itorque);
            virtual void clearImpulsiveTorque();

            virtual void applyTorque(const float &torque);
            virtual void setTorque(const float &torque);
            virtual void clearTorque();

            virtual void setMaterial(const PhysicsMaterial & mat);
            const PhysicsMaterial& getPhysicsMaterial();

            static unsigned int idTracker;

            void Destroy();
            bool isForDeletion();

            protected:

            unsigned int id;
            float mass{1.0f};
            float gravity;
            float damping{0.999f};
            bool forDeletion{false};

            PhysicsMaterial material;
        };
    }
    
}


#endif