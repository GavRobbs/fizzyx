#include <tutorial/pointmass.h>
#include <cmath>
#include <iostream>

using namespace fizzyx::tutorial;

PointMassEntity::PointMassEntity():core::IPhysicsEntity()
{
    mass = 1.0f;
    gravity = 10.f;
}
        
PointMassEntity::~PointMassEntity()
{

}

PointMassEntity::PointMassEntity(PointMassEntity &&other):position(other.position), velocity(other.velocity), acceleration(other.acceleration), impulse(other.impulse), force(other.force)
{
    mass = other.mass;
    id = other.id;
    gravity = other.gravity;
    damping = other.damping;
    forDeletion = other.forDeletion;
}

PointMassEntity& PointMassEntity::operator=(PointMassEntity &&other)
{
    if(this == &other)
    {

    } else{
        position = other.position;
        velocity = other.velocity;
        acceleration = other.acceleration;
        impulse = other.impulse;
        force = other.force;
        mass = other.mass;
        id = other.id;
        gravity = other.gravity;
        damping = other.damping;
        forDeletion = other.forDeletion;
    }

    return *this;
}

void PointMassEntity::update(float dt)
{
    math::Vector2 delta_acceleration = force / mass;
    force = math::Vector2{0.0f, 0.0f};
    acceleration += delta_acceleration;

    math::Vector2 delta_velocity = impulse / mass;
    impulse = math::Vector2{0.0f, 0.0f};
    velocity += delta_velocity;

    position += velocity * dt;
    
    math::Vector2 damped_velocity = velocity * std::powf(damping, dt);

    math::Vector2 finalAccel{acceleration.x, acceleration.y + gravity};
    velocity = damped_velocity + (finalAccel * dt);
}

fizzyx::collision::ICollisionShape * PointMassEntity::getBodyShape()
{
    return nullptr;
}

void PointMassEntity::setPosition(const math::Vector2 &position)
{
    this->position = position;
}

void PointMassEntity::setVelocity(const math::Vector2 &velocity)
{
    this->velocity = velocity;
}

void PointMassEntity::setAcceleration(const math::Vector2 &acceleration)
{
    this->acceleration = acceleration;
}

math::Vector2 PointMassEntity::getPosition()
{
    return position;
}

math::Vector2 PointMassEntity::getVelocity()
{
    return velocity;
}

math::Vector2 PointMassEntity::getAcceleration()
{
    return acceleration;
}

math::Vector2 PointMassEntity::getImpulse()
{
    return impulse;
}

math::Vector2 PointMassEntity::getForce()
{
    return force;
}

void PointMassEntity::applyForce(const math::Vector2 &force)
{
    this->force = this->force + force;
}

void PointMassEntity::setForce(const math::Vector2 &force)
{
    this->force = force;
}

void PointMassEntity::clearForce()
{
    this->force = math::Vector2{0.0f, 0.0f};
}

void PointMassEntity::applyImpulse(const math::Vector2 &impulse)
{
    this->impulse = this->impulse + impulse;
}
void PointMassEntity::setImpulse(const math::Vector2 &impulse)
{
    this->impulse = impulse;
}

void PointMassEntity::clearImpulse()
{
    this->impulse = math::Vector2{0.0f, 0.0f};
}