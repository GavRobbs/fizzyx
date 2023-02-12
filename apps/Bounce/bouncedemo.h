#ifndef BOUNCE_DEMO_H
#define BOUNCE_DEMO_H

#include "demoapp.h"

class BounceDemo : public DemoApp
{
    public:
    BounceDemo();
    virtual ~BounceDemo();
    void setup() override;
    void tearDown() override;

    protected:
    void drawGUI() override;
    
    private:

    const float ball1_default_restitution{0.5f};
    const float ball2_default_restitution{0.5f};

    float ball1_current_restitution{ball1_default_restitution};
    float ball2_current_restitution{ball2_default_restitution};

    float ball1_default_mass{3.0f};
    float ball2_default_mass{3.0f};

    float ball1_current_mass{ball1_default_mass};
    float ball2_current_mass{ball2_default_mass};

    float ball1_default_speed{15.0f};
    float ball2_default_speed{-15.0f};

    float ball1_current_speed{ball1_default_speed};
    float ball2_current_speed{ball2_default_speed};

    Entity * ball1;
    Entity * ball2;

    void reset();
    void recreateDemo();
};

#endif