#ifndef ACCELERATION_UNOPTIMIZED_STORE
#define ACCELERATION_UNOPTIMIZED_STORE

#include<acceleration/accelerationstructure.h>
#include<memory>

namespace fizzyx::tutorial
{

    class UnoptimizedStore : public fizzyx::acceleration::IAccelerationStructure
    {
        public:
        void addEntity(core::IPhysicsEntity *entity);
        void removeEntity(unsigned int id);
        void removeEntity(core::IPhysicsEntity *entity);
        void emptyWorld();
        core::IPhysicsEntity * getEntity(unsigned int id);
        void update(const float &dt);
        bool isEmpty();

        IAccelerationStructure * clone();

        //Deletes flagged entities
        void cleanup();
        std::vector<std::pair<core::IPhysicsEntity*, core::IPhysicsEntity*>> getPotentialContactPairs();

        private:
        std::vector<std::unique_ptr<core::IPhysicsEntity>> entities{};
    };

    
}

#endif