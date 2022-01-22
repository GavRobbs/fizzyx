#include <ecs.h>
#include <memory>
#include <math/mat33.h>

void SceneManager::processPhysics(float dt)
{
    for(auto it = entities.begin(); it != entities.end(); ++it)
    {
        std::vector<IPhysicsable*> physicables = it->get()->getComponentsByType<IPhysicsable>();
        for(auto physicable : physicables)
        {
            physicable->physicsUpdate(dt);       
        }
    }
}

void SceneManager::render(float dt)
{
    for(auto it = entities.begin(); it != entities.end(); ++it)
    {
        std::vector<IRenderable*> renderables = it->get()->getComponentsByType<IRenderable>();
        for(auto renderable : renderables)
        {
            renderable->render(dt);            
        }
    }

}
    
void SceneManager::processThinking(float dt)
{
    for(auto it = entities.begin(); it != entities.end(); ++it)
    {
        std::vector<ILogicable*> logicables = it->get()->getComponentsByType<ILogicable>();
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
}

void SceneManager::addEntity(Entity * entity)
{
    entity->setOwner(this);
    std::unique_ptr<Entity> entity_ptr(entity);
    entities.push_back(std::move(entity_ptr));
}
    
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

void Component::setOwner(Entity *owner)
{
    this->owner = owner;
}

unsigned int Component::getID()
{
    return id;
}

Entity::Entity():id(Entity::idTracker++)
{

}

Entity::~Entity()
{

}

void Entity::update(float dt)
{
    for(auto it = components.begin(); it != components.end(); ++it)
    {
        (*it)->update(dt);
    }
}

void Entity::setOwner(SceneManager * scene)
{
    this->scene = scene;
}


void Entity::addComponent(Component * component)
{
    component->setOwner(this);
    std::unique_ptr<Component> comp_ptr(component);
    components.push_back(std::move(comp_ptr));
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