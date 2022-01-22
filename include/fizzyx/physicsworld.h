#ifndef FIZZYX_WORLD_H
#define FIZZYX_WORLD_H

#include <vector>
#include <core/physicsentity.h>
#include <core/physicssolver.h>
#include <collision/collisiondetector.h>
#include <memory>

namespace fizzyx
{
    class PhysicsWorld
    {
        protected:
        std::vector<std::unique_ptr<core::IPhysicsEntity>> entities;
        core::IPhysicsSolver* solver;
        collision::CollisionDetector* collisionDetector;
        
        public:
        void update(float dt);
        PhysicsWorld();
        ~PhysicsWorld();
        void setSolver(core::IPhysicsSolver *solver);
        void setCollisionDetector(collision::CollisionDetector *detector);
        
        void addEntity(core::IPhysicsEntity *entity);
        void removeEntity(unsigned int id);
        void removeEntity(core::IPhysicsEntity *entity);
        core::IPhysicsEntity * getEntity(unsigned int id);
    };

}



#endif