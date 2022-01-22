#include <tutorial/pointmass.h>
#include <cmath>

using namespace fizzyx::tutorial;

PointMassEntity::PointMassEntity():core::IPhysicsEntity()
{
    mass = 1.0f;
}
        
PointMassEntity::~PointMassEntity()
{

}

void PointMassEntity::update(float dt)
{
    position += velocity * dt;
    math::Vector2 damped_velocity = velocity * std::powf(damping, dt);

    math::Vector2 finalAccel{acceleration.x, acceleration.y + gravity};
    velocity = damped_velocity + (finalAccel * dt);
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