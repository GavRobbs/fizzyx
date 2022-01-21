#ifndef FIZZYX_WORLD_H
#define FIZZYX_WORLD_H

#include <vector>
#include <core/physicsentity.h>
#include <core/physicssolver.h>
#include <memory>

namespace fizzyx
{
    class PhysicsWorld
    {
        private:
        std::vector<std::unique_ptr<core::IPhysicsEntity>> entities;
        core::IPhysicsSolver* solver;
        public:
        void update(float dt);
        PhysicsWorld();
        ~PhysicsWorld();
        void setSolver(core::IPhysicsSolver *solver);
        void addEntity(core::IPhysicsEntity *entity);
        void removeEntity(unsigned int id);
        void removeEntity(core::IPhysicsEntity *entity);
        core::IPhysicsEntity * getEntity(unsigned int id);
    };

}



#endif