#include <bouncedemo.h>
#include <basiccomponents.h>
#include <tutorial/simplelinearsolver.h>
#include <tutorial/pointmasscollisiondetector.h>
#include <tutorial/pointmass.h>

BounceDemo::BounceDemo():DemoApp("Bounce Demo", 1024, 768)
{

}

BounceDemo::~BounceDemo()
{

}

void BounceDemo::setup()
{
    fizzyx::PhysicsWorld & world = sceneManager.getPhysicsWorld();

    fizzyx::tutorial::SimpleLinearSolver * sls = new fizzyx::tutorial::SimpleLinearSolver{};
    world.setSolver(sls);

    fizzyx::tutorial::PointMassCollisionDetector * pmcd = new fizzyx::tutorial::PointMassCollisionDetector{};
    pmcd->setCollisionRadius(30.0f);
    world.setCollisionDetector(pmcd);

    recreateDemo();
}

void BounceDemo::recreateDemo()
{
    fizzyx::PhysicsWorld & pWorld = sceneManager.getPhysicsWorld();

    fizzyx::core::PhysicsMaterial material{0.5f, 0.0f, 0.0f};

    ball1 = new Entity{};
    Transform t = ball1->getTransform();
    t.position = math::Vector2{224.0f, 400.0f};
    ball1->setTransform(t);
    auto ball1body = new fizzyx::tutorial::PointMassEntity{};
    ball1body->setVelocity(math::Vector2{16.0f, 0.0f});
    ball1body->setMass(ball1_current_mass);
    ball1body->setGravity(0.0f);
    ball1body->setPosition(t.position);
    ball1body->setMaterial(material);
    pWorld.addEntity(ball1body);
    auto * sdrb1 = new SimpleDynamicRigidbodyComponent{};
    sdrb1->setEntity(ball1body);
    ball1->addComponent(sdrb1);
    ball1->addComponent(new CircleRendererComponent{graphicsManager, GraphicsManager::Color{255, 0, 0, 255}, 30.0f});
    sceneManager.addEntity(ball1);

    ball2 = new Entity{};
    Transform t2 = ball2->getTransform();
    t2.position = math::Vector2{800.0f, 400.0f};
    ball2->setTransform(t2);
    auto ball2body = new fizzyx::tutorial::PointMassEntity{};
    ball2body->setVelocity(math::Vector2{-16.0f, 0.0f});
    ball2body->setMass(ball2_current_mass);
    ball2body->setGravity(0.0f);
    ball2body->setPosition(t2.position);
    ball2body->setMaterial(material);
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
}

void BounceDemo::drawGUI()
{

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