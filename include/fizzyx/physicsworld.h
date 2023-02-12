#ifndef FIZZYX_WORLD_H
#define FIZZYX_WORLD_H

#include <vector>
#include <bodies/physicsentity.h>
#include <solvers/physicssolver.h>
#include <forcegenerators/forcegenerator.h>
#include <collision_utils/collisiondetector.h>
#include <acceleration/accelerationstructure.h>
#include <memory>

namespace fizzyx
{
    class PhysicsWorld
    {
        protected:
        core::IPhysicsSolver* solver;
        collision::ICollisionDetector* collisionDetector;
        acceleration::IAccelerationStructure* entityStorage;

        struct ForceGeneratorPair
        {
            core::IPhysicsEntity * entity;
            core::ForceGenerator * forceGenerator;
        };

        std::vector<ForceGeneratorPair> fg_registry;

        void resolveCollisionPairs(const float & dt = 0.0f);
        void processForceGenerators(const float & dt = 0.0f);
        void updateAllEntities(const float & dt = 0.0f);
        void deleteFlaggedEntities();

        
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
        void setAccelerationStructure(acceleration::IAccelerationStructure *accelerator);
        
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