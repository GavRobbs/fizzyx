#include <forcegeneratordemo.h>
#include <fgcomponents.h>
#include <basiccomponents.h>

ForceGeneratorDemoApp::ForceGeneratorDemoApp():DemoApp{"Force Generator Demo", 1024, 768}
{

}

ForceGeneratorDemoApp::~ForceGeneratorDemoApp()
{

}
    
void ForceGeneratorDemoApp::setup()
{
    pointMass = new fizzyx::tutorial::PointMassEntity{};
    pointMass->setMass(1.0f);
    sceneManager.getPhysicsWorld().addEntity(pointMass);

    box = new Entity{};
    Transform t = box->getTransform();
    t.position = math::Vector2(500.0f, 350.0f);
    pointMass->setPosition(t.position);
    box->setTransform(t);
    SimpleDynamicRigidbodyComponent * sdrb = new SimpleDynamicRigidbodyComponent{};
    sdrb->setEntity(pointMass);
    box->addComponent(sdrb);
    box->addComponent(new BoxRendererComponent{graphicsManager, GraphicsManager::Color{255, 0, 0, 255}, math::Vector2{10.0f, 10.0f}});
    sceneManager.addEntity(box);

    Entity * spring = new Entity{};
    Transform t2 = spring->getTransform();
    t2.position = math::Vector2(500.0f, 50.0f);
    spring->setTransform(t2);
    spring->addComponent(new SpringRendererComponent{graphicsManager, box, GraphicsManager::Color{255, 255, 255, 255}, GraphicsManager::Color{255, 0, 0, 255}});
    sceneManager.addEntity(spring);

    asfg = new AnchoredSpringForceGenerator{t2.position, 100.0f, 40.0f};
    sceneManager.getPhysicsWorld().addForceGeneratorPair(pointMass, asfg);
}
    
void ForceGeneratorDemoApp::tearDown()
{
    sceneManager.getPhysicsWorld().removeForceGenerator(pointMass, asfg);

    if(asfg != nullptr)
    {
        delete asfg;
    }
}

int main(int argc, char **argv)
{
    ForceGeneratorDemoApp fgdemo{};
    fgdemo.setup();
    fgdemo.mainLoop();
    fgdemo.tearDown();
    return 0;
}