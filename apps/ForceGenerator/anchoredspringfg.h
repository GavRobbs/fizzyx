#ifndef ANCHORED_SPRING_FORCE_GENERATOR_DEMO_H
#define ANCHORED_SPRING_FORCE_GENERATOR_DEMO_H

#include <math/vector2.h>
#include <core/physicsentity.h>
#include <core/forcegenerator.h>

/* A force generator that simulates a spring with one end fixed at a specific position*/
class AnchoredSpringForceGenerator : public fizzyx::core::ForceGenerator
{
    public:
    AnchoredSpringForceGenerator(const math::Vector2 anchorPosition, const float& restLength, const float& springConstant);
    void update(fizzyx::core::IPhysicsEntity * body, float dt) override;

    void setAnchorPosition(const math::Vector2 & anchorPosition);
    const math::Vector2 & getAnchorPosition() const;

    void setSpringConstant(const float & springConstant);
    const float & getSpringConstant() const;

    private:
    math::Vector2 anchorPosition;
    float springConstant;
    float restLength;
};

#endif
