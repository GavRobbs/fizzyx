#include <physicsentity.h>
#include <vector2.h>

using namespace fizzyx::core;

IPhysicsEntity::IPhysicsEntity():id(IPhysicsEntity::idTracker++)
{

}

IPhysicsEntity::~IPhysicsEntity()
{

}

void IPhysicsEntity::IPhysicsEntity::setID(unsigned int id)
{
    this->id = id;
}

unsigned int IPhysicsEntity::getID()
{
    return id;
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