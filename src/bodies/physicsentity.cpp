#include <core/physicsentity.h>
#include <math/vector2.h>

using namespace fizzyx::core;

unsigned int IPhysicsEntity::idTracker = 0;

IPhysicsEntity::IPhysicsEntity():id(IPhysicsEntity::idTracker++)
{

}

IPhysicsEntity::~IPhysicsEntity()
{

}

IPhysicsEntity::IPhysicsEntity(IPhysicsEntity&& other):id(other.id), damping(other.damping), mass(other.mass), gravity(other.gravity), forDeletion{forDeletion}
{

}

IPhysicsEntity& IPhysicsEntity::operator=(IPhysicsEntity &&other)
{
    if(this == &other)
    {

    } else{
        this->gravity = other.gravity;
        this->mass = other.mass;
        this->damping = other.damping;
        this->id = other.id;
        this->forDeletion = other.forDeletion;
    }

    return *this;
}

bool IPhysicsEntity::isForDeletion()
{
    return forDeletion;
}


void IPhysicsEntity::IPhysicsEntity::setID(unsigned int id)
{
    this->id = id;
}

unsigned int IPhysicsEntity::getID()
{
    return id;
}

void IPhysicsEntity::Destroy()
{
    forDeletion = true;
}

math::Vector2 IPhysicsEntity::getPosition()
{
    return math::Vector2{};
}

math::Vector2 IPhysicsEntity::getVelocity()
{
    return math::Vector2{};
}

math::Vector2 IPhysicsEntity::getAcceleration()
{
    return math::Vector2{};
}
            
float IPhysicsEntity::getAngularVelocity()
{
    return 0.0f;
}

float IPhysicsEntity::getAngularAcceleration()
{
    return 0.0f;
}
            
math::Vector2 IPhysicsEntity::getImpulse()
{
    return math::Vector2{};    
}

math::Vector2 IPhysicsEntity::getForce()
{
    return math::Vector2{};    
}

float IPhysicsEntity::getImpulsiveTorque()
{
    return 0.0f;    
}

float IPhysicsEntity::getTorque()
{
    return 0.0f;    
}
          
float IPhysicsEntity::getMass()
{
    return mass;
}

float IPhysicsEntity::getInverseMass()
{
    if(mass == 0.0f)
    {
        return 0.0f;
    } else{
        return 1.0f/mass;
    }
}

void IPhysicsEntity::setMass(const float &mass)
{
    this->mass = mass;
}

float IPhysicsEntity::getGravity()
{
    return gravity;
}

void IPhysicsEntity::setGravity(const float &gravity)
{
    this->gravity = gravity;
}

void IPhysicsEntity::setPosition(const math::Vector2 &position)
{

}

void IPhysicsEntity::setVelocity(const math::Vector2 &velocity)
{

}
void IPhysicsEntity::setAcceleration(const math::Vector2 &acceleration)
{

}

void IPhysicsEntity::setAngularVelocity(const float &angVel)
{

}

void IPhysicsEntity::setAngularAcceleration(const float &angAccel)
{

}

void IPhysicsEntity::applyForce(const math::Vector2 &force)
{

}

void IPhysicsEntity::setForce(const math::Vector2 &force)
{

}

void IPhysicsEntity::clearForce()
{

}

void IPhysicsEntity::applyImpulse(const math::Vector2 &impulse)
{

}

void IPhysicsEntity::setImpulse(const math::Vector2 &impulse)
{

}

void IPhysicsEntity::clearImpulse()
{

}

void IPhysicsEntity::applyImpulsiveTorque(const float &itorque)
{

}

void IPhysicsEntity::setImpulsiveTorque(const float &itorque)
{

}

void IPhysicsEntity::clearImpulsiveTorque()
{

}

void IPhysicsEntity::applyTorque(const float &torque)
{

}

void IPhysicsEntity::setTorque(const float &torque)
{

}

void IPhysicsEntity::clearTorque()
{

}

float IPhysicsEntity::getRotation()
{
    return 0.0f;
}

void IPhysicsEntity::setRotation(const float & rot)
{
    return;
}

void IPhysicsEntity::setMaterial(const PhysicsMaterial & mat)
{
    material = mat;
}

const PhysicsMaterial& IPhysicsEntity::getPhysicsMaterial()
{
    return material;
}