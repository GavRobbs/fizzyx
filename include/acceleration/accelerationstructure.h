#include <utility>
#include <vector>

namespace fizzyx
{
    namespace acceleration
    {
        class AccelerationStructure
        {
            public:
            virtual void addEntity(core::IPhysicsEntity *entity);
            virtual void removeEntity(unsigned int id);
            virtual void removeEntity(core::IPhysicsEntity *entity);
            virtual void emptyWorld();
            virtual core::IPhysicsEntity * getEntity(unsigned int id);
            virtual void update(const float &dt);
            virtual bool isEmpty();

            //Deletes flagged entities
            virtual void cleanup();
            std::vector<std::pair<core::IPhysicsEntity*, core::IPhysicsEntity*>> getPotentialContactPairs();
        };

    }
    
}