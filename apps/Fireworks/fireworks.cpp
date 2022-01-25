#include <demoapp.h>
#include <ecs.h>
#include <SDL.h>
#include <cmath>
#include <algorithm>
#include <tutorial/pointmass.h>
#include <tutorial/nullsolver.h>
#include <tutorial/nulldetector.h>
#include <math/mathutils.h>
#include <particlespawner.h>
#include <sstream>

/* This application demonstrates the movement of particles under the influence of velocity and acceleration - controlled by the physics engine. */
class FireworksApp : public DemoApp
{
    public:
    FireworksApp():DemoApp("Fireworks", 1024, 768), spawner{sceneManager, graphicsManager}
    {

    }

    virtual ~FireworksApp()
    {

    }

    void setup() override
    {
        fizzyx::PhysicsWorld &world = sceneManager.getPhysicsWorld();
        world.setSolver(new fizzyx::tutorial::NullSolver{});
        world.setCollisionDetector(new fizzyx::tutorial::NullCollisionDetector{});
    }

    void tearDown() override
    {

    }

    protected:
    void drawScene() override
    {
    }

    void drawGUI() override
    {
        ImGui::Begin("Particle Mode", NULL, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoBackground);

        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255,255,255,255));

        ImGui::RadioButton("Single", &spawn_mode, 0);
        ImGui::RadioButton("Spherical", &spawn_mode, 1);

        std::stringstream particlecount;
        particlecount << sceneManager.getEntityCount() << " particles";
        ImGui::Text(particlecount.str().c_str());

        ImGui::PopStyleColor();
        ImGui::End();
    }

    void processEvent(const SDL_Event &event)
    {
        if(event.type == SDL_MOUSEBUTTONUP)
        {
            int x{0}, y{0};
            SDL_GetMouseState(&x, &y);

            switch(spawn_mode)
            {
                case 1:
                {
                    int radius = 40;
                    int numSlices = 12;
                    float twopi = 6.28318f; //a circle is 360 degrees, so 2 * pi radians
                    float rad_per_slice = twopi / (float)numSlices;
                    
                    for(int j = radius; j != 0; j -= 8)
                    {
                        for(int i = 0; i < numSlices; ++i)
                        {
                            float angle = (float)i * rad_per_slice;
                            spawner.spawnParticles(math::Vector2{(float)x + (float)j * std::cosf(angle), (float)y + (float)j * std::sinf(angle)}, 1);
                        }
                    }

                    break;
                }
                case 0:
                default:
                {
                    spawner.spawnParticles(math::Vector2{(float)x, (float)y});
                    break;
                }
            } 
        }

    }

    private:
    ParticleSpawner spawner;
    int spawn_mode{0};

};

int main(int argc, char **argv)
{
    FireworksApp fireworks{};
    fireworks.setup();
    fireworks.mainLoop();
    fireworks.tearDown();

    return 0;
}