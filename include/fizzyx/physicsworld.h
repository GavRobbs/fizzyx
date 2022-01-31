#ifndef FIZZYX_WORLD_H
#define FIZZYX_WORLD_H

#include <vector>
#include <core/physicsentity.h>
#include <core/physicssolver.h>
#include <core/forcegenerator.h>
#include <collision/collisiondetector.h>
#include <memory>

namespace fizzyx
{
    class PhysicsWorld
    {
        protected:
        std::vector<std::unique_ptr<core::IPhysicsEntity>> entities;
        core::IPhysicsSolver* solver;
        collision::ICollisionDetector* collisionDetector;

        struct ForceGeneratorPair
        {
            core::IPhysicsEntity * entity;
            core::ForceGenerator * forceGenerator;
        };

        std::vector<ForceGeneratorPair> fg_registry;
        
        public:

        void update(float dt);
        PhysicsWorld();
        ~PhysicsWorld();

        PhysicsWorld(const PhysicsWorld&) = delete;
        PhysicsWorld& operator=(const PhysicsWorld&) = delete;
        PhysicsWorld(PhysicsWorld &&other);
        PhysicsWorld& operator=(PhysicsWorld &&other);

        void setSolver(core::IPhysicsSolver *solver);
        void setCollisionDetector(collision::ICollisionDetector *detector);
        
        void addEntity(core::IPhysicsEntity *entity);
        void removeEntity(unsigned int id);
        void removeEntity(core::IPhysicsEntity *entity);
        void emptyWorld();
        core::IPhysicsEntity * getEntity(unsigned int id);

        void addForceGeneratorPair(core::IPhysicsEntity* entity, core::ForceGenerator * generator);
        void removeAllForceGeneratorsFromEntity(core::IPhysicsEntity * entity);
        void removeForceGenerator(core::IPhysicsEntity * entity, core::ForceGenerator * generator);
    };

}



#endif