#ifndef ACCELERATION_STRUCTURE_H
#define ACCELERATION_STRUCTURE_H

#include <utility>
#include <vector>
#include "fizzyx/bodies/physicsentity.h"

namespace fizzyx
{
    namespace acceleration
    {
        class IAccelerationStructure
        {
            public:
            virtual void addEntity(core::IPhysicsEntity *entity);
            virtual void removeEntity(unsigned int id);
            virtual void removeEntity(core::IPhysicsEntity *entity);
            virtual void emptyWorld();
            virtual core::IPhysicsEntity * getEntity(unsigned int id);
            virtual void update(const float &dt);
            virtual bool isEmpty();

            virtual IAccelerationStructure * clone() = 0;

            //Deletes flagged entities
            virtual void cleanup();
            virtual std::vector<std::pair<core::IPhysicsEntity*, core::IPhysicsEntity*>> getPotentialContactPairs();
        };

    }
    
}

#endif