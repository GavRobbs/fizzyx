#ifndef FORCE_GENERATOR_DEMO_H
#define FORCE_GENERATOR_DEMO_H

#include <demoapp.h>
#include <ecs.h>
#include <SDL.h>
#include <cmath>
#include <algorithm>
#include <tutorial/pointmass.h>
#include <tutorial/nullsolver.h>
#include <tutorial/nulldetector.h>
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
    //void processEvent(const SDL_Event &event) override;
    //void drawGUI() override;
    //void drawScene() override;
    //void updateLogic() override;

    private:
    AnchoredSpringForceGenerator * asfg;
    Entity * box{nullptr};
    fizzyx::tutorial::PointMassEntity * pointMass{nullptr};
};


#endif