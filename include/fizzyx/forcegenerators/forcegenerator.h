#ifndef FORCE_GENERATOR_H
#define FORCE_GENERATOR_H

#include "fizzyx/bodies/physicsentity.h"
#include <string>

namespace fizzyx::core
{
    class ForceGenerator
    {
        public:
        enum FORCE_MODE : int { IMPULSE = 0, FORCE = 1};
        
        ForceGenerator(std::string _name, FORCE_MODE fmode);
        virtual void update(IPhysicsEntity * body, float dt) = 0;

        protected:
        std::string name;
        FORCE_MODE forceMode = FORCE_MODE::IMPULSE;

    };

}

#endif