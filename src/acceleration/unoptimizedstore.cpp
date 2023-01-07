#include<acceleration/unoptimizedstore.h>
#include<iostream>

using namespace fizzyx::tutorial;
using namespace fizzyx::core;
using namespace fizzyx::acceleration;

void UnoptimizedStore::addEntity(IPhysicsEntity *entity)
{
    entities.push_back(std::unique_ptr<IPhysicsEntity>(entity));
}

void UnoptimizedStore::removeEntity(unsigned int id)
{
    for(auto it = entities.begin(); it != entities.end(); ++it)
    {
        if(it->get()->getID() == id)
        {
            it->get()->Destroy();
            return;
        }
    }
}

void UnoptimizedStore::removeEntity(IPhysicsEntity *entity)
{
    removeEntity(entity->getID());
}

void UnoptimizedStore::emptyWorld()
{
    auto it = entities.begin();
    while(it != entities.end())
    {
        it = entities.erase(it);
    }

}

IPhysicsEntity * UnoptimizedStore::getEntity(unsigned int id)
{
    auto it = entities.begin();
    while(it != entities.end())
    {
        if(it->get()->getID() == id)
        {
            return it->get();
        } 
    }

    return NULL;
}

void UnoptimizedStore::update(const float &dt)
{
    auto it = entities.begin();
    while(it != entities.end())
    {
        if(it->get()->isForDeletion())
        {
        } else{
            it->get()->update(dt);
        }

        ++it;
    }
}

bool UnoptimizedStore::isEmpty()
{
    return entities.size() == 0;
}

IAccelerationStructure * UnoptimizedStore::clone()
{
    //Should really throw an error
    return NULL;
}

//Deletes flagged entities
void UnoptimizedStore::cleanup()
{
    auto it = entities.begin();
    while(it != entities.end())
    {
        if(it->get()->isForDeletion())
        {
            it = entities.erase(it);
        }
        
        ++it;
    }
}

std::vector<std::pair<IPhysicsEntity*, IPhysicsEntity*>> UnoptimizedStore::getPotentialContactPairs()
{
    auto it = entities.begin();

    std::vector<std::pair<IPhysicsEntity*, IPhysicsEntity*>> pairs{};

    while(it != entities.end() - 1)
    {
        if(it->get()->isForDeletion())
        {
            ++it;
        }
        else{
            auto it2 = it + 1;

            while(it2 != entities.end())
            {
                if(it2->get()->isForDeletion())
                {
                    ++it2;
                    continue;
                }
                else{
                    auto newPair = std::pair<IPhysicsEntity*, IPhysicsEntity*>{it->get(), it2->get()};
                    pairs.push_back(newPair);
                    ++it2;
                }
            }
        }

        ++it;
    }

    return pairs;

}