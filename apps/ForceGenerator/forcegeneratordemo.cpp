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
    recreateDemo();    
}
    
void ForceGeneratorDemoApp::tearDown()
{
    /* Unlinks and deletes our spring force generator */
    sceneManager.getPhysicsWorld().removeForceGenerator(pointMass, asfg);

    if(asfg != nullptr)
    {
        delete asfg;
    }
}

void ForceGeneratorDemoApp::drawGUI()
{
    ImGui::Begin("Spring Parameters", NULL, ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::InputFloat("Spring Constant", &currentSpringConstant, 0.00001f, 0.0f, "%.5f");
    ImGui::InputFloat("Rest Length", &currentRestLength, 0.01f, 0.1f, "%.2f");

    if(ImGui::Button("Update"))
    {
        tearDown();
        sceneManager.resetScene();
        recreateDemo();       
    }

    if(ImGui::Button("Reset"))
    {
        tearDown();
        reset();
        sceneManager.resetScene();
        recreateDemo();        
    }
    ImGui::End();
}

void ForceGeneratorDemoApp::reset()
{
    /* Resets the current values to their defaults */
    currentRestLength = defaultRestLength;
    currentSpringConstant = defaultSpringConstant;
}

void ForceGeneratorDemoApp::recreateDemo()
{
    /* This recreates the demo state with the current values of the spring constant and rest length. It creates a point mass physics entity, then creates a scene entity to hold it, and then a rigid body to link the two so physics changes are automatically translated to scene changes. It then creates an entity to render the spring, and adds that to the scene. It then links the spring force generator to the point mass created earlier and adds it to the physics world*/
    pointMass = new fizzyx::tutorial::PointMassEntity{};
    pointMass->setMass(1.0f);
    sceneManager.getPhysicsWorld().addEntity(pointMass);

    box = new Entity{};
    Transform t = box->getTransform();
    t.position = math::Vector2(500.0f, 400.0f);
    pointMass->setPosition(t.position);
    box->setTransform(t);
    SimpleDynamicRigidbodyComponent * sdrb = new SimpleDynamicRigidbodyComponent{};
    sdrb->setEntity(pointMass);
    box->addComponent(sdrb);
    BoxRendererComponent * brc = new BoxRendererComponent{graphicsManager, GraphicsManager::Color{255, 0, 0, 255}, math::Vector2{40.0f, 40.0f}};
    box->addComponent(brc);
    sceneManager.addEntity(box);

    Entity * spring = new Entity{};
    Transform t2 = spring->getTransform();
    t2.position = math::Vector2(500.0f, 150.0f);
    spring->setTransform(t2);
    SpringRendererComponent * src = new SpringRendererComponent{graphicsManager, box, GraphicsManager::Color{255, 255, 255, 255}};
    src->setOffset(math::Vector2{0, 20.0f});
    spring->addComponent(src);
    sceneManager.addEntity(spring);

    asfg = new AnchoredSpringForceGenerator{t2.position, currentRestLength, currentSpringConstant};
    sceneManager.getPhysicsWorld().addForceGeneratorPair(pointMass, asfg);
}

int main(int argc, char **argv)
{
    ForceGeneratorDemoApp fgdemo{};
    fgdemo.setup();
    fgdemo.mainLoop();
    fgdemo.tearDown();
    return 0;
}