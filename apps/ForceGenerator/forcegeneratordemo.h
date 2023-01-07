#ifndef FORCE_GENERATOR_DEMO_H
#define FORCE_GENERATOR_DEMO_H

#include <demoapp.h>
#include <ecs.h>
#include <SDL.h>
#include <cmath>
#include <algorithm>
#include <bodies/pointmass.h>
#include <solvers/nullsolver.h>
#include <narrowphasedetectors/nulldetector.h>
#include <math/mathutils.h>
#include <anchoredspringfg.h>


class ForceGeneratorDemoApp : public DemoApp
{
    public:
    ForceGeneratorDemoApp();
    virtual ~ForceGeneratorDemoApp();
    void setup() override;
    void tearDown() override;

    protected:
    void drawGUI() override;
    
    private:
    AnchoredSpringForceGenerator * asfg;
    Entity * box{nullptr};
    fizzyx::tutorial::PointMassEntity * pointMass{nullptr};

    /* These are the default parameters, used when the application has just started or is reset*/
    const float defaultSpringConstant{0.0025f};
    const float defaultRestLength{100.0f};

    float currentSpringConstant{defaultSpringConstant};
    float currentRestLength{defaultRestLength};

    void reset();
    void recreateDemo();
};


#endif