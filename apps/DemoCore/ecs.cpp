#include <ecs.h>
#include <memory>
#include <math/mat33.h>

unsigned int Entity::idTracker = 0;
unsigned int Component::idTracker = 0;

SceneManager::SceneManager()
{
}

void SceneManager::processPhysics(float dt)
{
    if(entities.empty())
    {
        return;
    }

    for(size_t i = 0; i < entities.size(); ++i)
    {   
        std::vector<IPhysicsable*> physicables = entities[i].get()->getComponentsByType<IPhysicsable>();
        
        for(auto physicable : physicables)
        {
            physicable->physicsUpdate(dt);       
        }
    }
}

void SceneManager::render(float dt)
{
    if(entities.empty())
    {
        return;
    }

    for(size_t i = 0; i < entities.size(); ++i)
    {
        std::vector<IRenderable*> renderables = entities[i].get()->getComponentsByType<IRenderable>();

        for(auto renderable : renderables)
        {
            renderable->render(dt);            
        }
    }

}

void SceneManager::resetScene()
{
    physicsWorld.emptyWorld();
    entities.clear();
}

    
void SceneManager::processThinking(float dt)
{
    if(entities.empty())
    {
        return;
    }

    for(size_t i = 0; i < entities.size(); ++i)
    {
        std::vector<ILogicable*> logicables = entities[i].get()->getComponentsByType<ILogicable>();
        for(auto logicable : logicables)
        {
            logicable->think(dt);            
        }
    }
}

void SceneManager::update(float dt)
{
    physicsWorld.update(dt);
    processPhysics(dt);
    processThinking(dt);
    render(dt);

    //This last loop flags all the entities that were marked for deletion and gets rid of them

    auto it = entities.begin();
    while(it != entities.end())
    {
        if(it->get()->forDeletion)
        {
            it = entities.erase(it);
        } else{
            it->get()->update(dt);
            ++it;
        }
    }
    
}

void SceneManager::addEntity(Entity * entity)
{
    entity->setOwner(this);
    entities.push_back(std::unique_ptr<Entity>(entity));
}

//This deletes an entity instantly, you should prefer Destroy() instead   
void SceneManager::removeEntity(Entity * entity)
{
    removeEntity(entity->getID());   
}

void SceneManager::removeEntity(const unsigned int &id)
{
    for(auto it = entities.begin(); it != entities.end(); ++it)
    {
        if(it->get()->getID() == id)
        {
            entities.erase(it);
            return;
        }
    }
}

std::size_t SceneManager::getEntityCount()
{
    return entities.size();
}


fizzyx::PhysicsWorld& SceneManager::getPhysicsWorld()
{
    return physicsWorld;
}

Component::Component():id(Component::idTracker++)
{
}

Component::~Component()
{

}

void Component::update(float dt)
{

}

void Component::setOwner(Entity *owner)
{
    this->owner = owner;
}

Entity * Component::getOwner()
{
    return owner;
}

unsigned int Component::getID()
{
    return id;
}

void Component::Destroy()
{
    forDeletion = true;
}

Entity::Entity():id(Entity::idTracker++)
{

}

Entity::~Entity()
{
    components.clear();
}

void Entity::update(float dt)
{
    auto it = components.begin();
    while(it != components.end())
    {
        if(it->get()->forDeletion)
        {
            it = components.erase(it);
        } else{
            it->get()->update(dt);
            ++it;
        }
    }
}

void Entity::setOwner(SceneManager * scene)
{
    this->scene = scene;
}


void Entity::addComponent(Component * component)
{
    component->setOwner(this);
    components.push_back(std::unique_ptr<Component>(component));
}

void Entity::removeComponent(unsigned int id)
{
    for(auto it = components.begin(); it != components.end(); ++it)
    {
        if(it->get()->getID() == id)
        {
            components.erase(it);
            return;
        }
    }
}

unsigned int Entity::getID()
{
    return id;
}

const Transform& Entity::getTransform() const
{
    return transform;
}

void Entity::setTransform(const Transform &transform)
{
    this->transform = transform;
}

//Does not delete an entity instantly, instead marks it for deletion at the end of the current frame
void Entity::Destroy()
{
    forDeletion = true;
}

Entity::Entity(Entity &&other):id(other.id), transform(other.transform), forDeletion(other.forDeletion)
{
    scene = other.scene;

    for(int i = 0; i < other.components.size(); ++i)
    {
        components.push_back(std::move(other.components[i]));
    }

}

Entity& Entity::operator=(Entity&& other)
{
    if(this == &other)
    {

    } else
    {
        for(int i = 0; i < other.components.size(); ++i)
        {
            components.push_back(std::move(other.components[i]));
        }

        id = other.id;
        transform = other.transform;
        forDeletion = other.forDeletion;
    }

    return *this;
}