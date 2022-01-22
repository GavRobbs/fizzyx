#ifndef DEMOCORE_ECS_H
#define DEMOCORE_ECS_H

#include <vector>
#include <memory>
#include <physicsworld.h>

#include <vector2.h>
#include <mat33.h>

class Entity;
class Component;

/*
    This interface is for any component that can be drawn on the screen
*/
class IRenderable
{
    public:
    virtual void render(float dt=0.0f) = 0;
};

/* 
    This interface is for any component that is affected by the physics engine. It is responsible for updating the scene data with the data derived from the physics engine.
*/
class IPhysicsable
{
    public:
    
    virtual void physicsUpdate(float dt) = 0;
};

/*
    This interface is for any component that does some processing or thinking, such as input handling or AI
*/
class ILogicable
{
    public:
    virtual void think(float dt) = 0;
};

class SceneManager
{
    private:
    std::vector<std::unique_ptr<Entity>> entities;
    fizzyx::PhysicsWorld physicsWorld;

    public:
    void processPhysics(float dt);
    void render(float dt);
    void processThinking(float dt);

    void update(float dt);
    void addEntity(Entity * entity);
    void removeEntity(Entity * entity);
    void removeEntity(const unsigned int &id);

    fizzyx::PhysicsWorld & getPhysicsWorld();
};

/*
    A component is the building block of what determines how an entity acts. The derived classes all use one of the specific interfaces available to define its action in the scene.
*/
class Component
{
    private:
    Entity * owner;
    unsigned int id;

    static unsigned int idTracker;

    public:
    Component();
    virtual ~Component();

    /* See the description of update in the entity class */
    virtual void update(float dt);
    void setOwner(Entity *owner);
    unsigned int getID();
};

struct Transform
{
    math::Vector2 position;
    float rotation;
    math::Vector2 scale;
};

/* 
    Anything that can be found in the scene. An entity uses composition, and is made of multiple components, which determine behaviour and properties.
*/
class Entity
{
    friend class Component;

    private:
    static unsigned int idTracker;

    unsigned int id;
    std::vector<std::unique_ptr<Component>> components;
    Transform transform;

    SceneManager * scene;

    public:
    Entity();
    virtual ~Entity();
    
    /* This update step is separate from the specific update step for each interface. This is where things that don't directly carry out the function of the component are done, eg. adding the time to move to the next frame of an animation, while IRenderable::render() would actually display it onscreen */
    virtual void update(float dt);
    void addComponent(Component * component);
    void removeComponent(unsigned int id);
    unsigned int getID();

    void setOwner(SceneManager * scene);

    template<class T>
    T * getComponentByType()
    {
        for(auto it = components.begin(); it != components.end(); ++it)
        {
            T * componentByType = dynamic_cast<T*>(it->get());
            if(componentByType != nullptr)
            {
                return componentByType;
            }
        }

        return nullptr;
    };

    template<class T>
    std::vector<T*> getComponentsByType()
    {
        std::vector<T*> componentList;

        for(auto it = components.begin(); it != components.end(); ++it)
        {
            T * componentByType = dynamic_cast<T*>(it->get());
            if(componentByType != nullptr)
            {
                componentList.push_back(componentByType);
            }
        }

        return componentList;

    };

    const Transform & getTransform() const;
    void setTransform(const Transform &transform);
};

#endif