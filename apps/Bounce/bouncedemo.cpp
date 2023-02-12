#include "bouncedemo.h"
#include "basiccomponents.h"
#include "fizzyx/solvers/simplelinearsolver.h"
#include "fizzyx/narrowphasedetectors/pointmasscollisiondetector.h"
#include "fizzyx/acceleration/unoptimizedstore.h"
#include "fizzyx/bodies/pointmass.h"

BounceDemo::BounceDemo():DemoApp("Bounce Demo", 1024, 768)
{

}

BounceDemo::~BounceDemo()
{

}

void BounceDemo::setup()
{
    auto & world = sceneManager.getPhysicsWorld();
    world.setSolver(new fizzyx::tutorial::SimpleLinearSolver{});
    world.setAccelerationStructure(new fizzyx::tutorial::UnoptimizedStore{});

    fizzyx::tutorial::PointMassCollisionDetector * pmcd = new fizzyx::tutorial::PointMassCollisionDetector{};
    pmcd->setCollisionRadius(30.0f);
    world.setCollisionDetector(pmcd);

    recreateDemo();
}

void BounceDemo::recreateDemo()
{
    fizzyx::PhysicsWorld & pWorld = sceneManager.getPhysicsWorld();

    fizzyx::core::PhysicsMaterial material1{ball1_current_restitution, 0.0f, 0.0f};
    fizzyx::core::PhysicsMaterial material2{ball2_current_restitution, 0.0f, 0.0f};

    ball1 = new Entity{};
    Transform t = ball1->getTransform();
    t.position = math::Vector2{324.0f, 400.0f};
    ball1->setTransform(t);
    auto ball1body = new fizzyx::tutorial::PointMassEntity{};
    ball1body->setVelocity(math::Vector2{ball1_current_speed, 0.0f});
    ball1body->setMass(ball1_current_mass);
    ball1body->setGravity(0.0f);
    ball1body->setPosition(t.position);
    ball1body->setMaterial(material1);
    pWorld.addEntity(ball1body);
    auto * sdrb1 = new SimpleDynamicRigidbodyComponent{};
    sdrb1->setEntity(ball1body);
    ball1->addComponent(sdrb1);
    ball1->addComponent(new CircleRendererComponent{graphicsManager, GraphicsManager::Color{255, 0, 0, 255}, 30.0f});
    sceneManager.addEntity(ball1);

    ball2 = new Entity{};
    Transform t2 = ball2->getTransform();
    t2.position = math::Vector2{700.0f, 400.0f};
    ball2->setTransform(t2);
    auto ball2body = new fizzyx::tutorial::PointMassEntity{};
    ball2body->setVelocity(math::Vector2{ball2_current_speed, 0.0f});
    ball2body->setMass(ball2_current_mass);
    ball2body->setGravity(0.0f);
    ball2body->setPosition(t2.position);
    ball2body->setMaterial(material2);
    pWorld.addEntity(ball2body);
    auto * sdrb2 = new SimpleDynamicRigidbodyComponent{};
    sdrb2->setEntity(ball2body);
    ball2->addComponent(sdrb2);
    ball2->addComponent(new CircleRendererComponent{graphicsManager, GraphicsManager::Color{0, 0, 255, 255}, 30.0f});
    sceneManager.addEntity(ball2);

}

void BounceDemo::reset()
{
    ball1_current_mass = ball1_default_mass;
    ball2_current_mass = ball2_default_mass;

    ball1_current_restitution = ball1_default_restitution;
    ball2_current_restitution = ball2_default_restitution;

    ball1_current_speed = ball1_default_speed;
    ball2_current_speed = ball2_default_speed;
}

void BounceDemo::drawGUI()
{
    ImGui::Begin("Simple Collision", NULL, ImGuiWindowFlags_AlwaysAutoResize);

    ImGui::InputFloat("Red Ball Mass", &ball1_current_mass, 0.5f, 1.0f, "%.1f");
    ImGui::InputFloat("Red Ball Restitution", &ball1_current_restitution, 0.01f, 0.1f, "%.2f");
    ImGui::InputFloat("Red Ball Speed", &ball1_current_speed, 0.1f, 1.0f, "%.2f");

    ImGui::InputFloat("Blue Ball Mass", &ball2_current_mass, 0.5f, 1.0f, "%.1f");
    ImGui::InputFloat("Blue Ball Restitution", &ball2_current_restitution, 0.01f, 0.1f, "%.2f");
    ImGui::InputFloat("Blue Ball Speed", &ball2_current_speed, 0.1f, 1.0f, "%.2f");


    if(ImGui::Button("Restart"))
    {
        tearDown();
        sceneManager.resetScene();
        recreateDemo();
    }

    if(ImGui::Button("Reset"))
    {
        reset();
        tearDown();
        sceneManager.resetScene();
        recreateDemo();
    }

    
    ImGui::End();
}

void BounceDemo::tearDown()
{

}

int main(int argc, char **argv)
{
    BounceDemo bounceDemo{};
    bounceDemo.setup();
    bounceDemo.mainLoop();
    bounceDemo.tearDown();
    return 0;
}