#include <demoapp.h>
#include <ecs.h>
#include <SDL.h>
#include <cmath>
#include <algorithm>
#include <tutorial/pointmass.h>

class ParticleSpawner
{
    public:
    void spawnParticles(const math::Vector2 &position, const unsigned int &numParticles, const float &minLifetime = 3.0f, const float &maxLifeTime = 6.0f)
    {
        unsigned int numToBeSpawned = std::min<unsigned int>(
            std::max<unsigned int>(
                maxParticleCount - currentParticleCount - numParticles, 
                0), 
                numParticles);

        if(numToBeSpawned == 0)
        {
            return;
        }

        fizzyx::PhysicsWorld &world = sceneManager.getPhysicsWorld();

        for(unsigned int i = 0; i < numToBeSpawned; ++i)
        {
            PointRendererComponent * prc = new PointRendererComponent{graphicsManager, getRandomColor()};
            PointSpawnerKillerComponent * pskc = new PointSpawnerKillerComponent{minLifetime, *this};

            fizzyx::tutorial::PointMassEntity * physicsBody = new fizzyx::tutorial::PointMassEntity{};
            physicsBody->setGravity(4.0f);
            physicsBody->setAcceleration(getRandomAcceleration());
            world.addEntity(physicsBody);

            PointPhysicsBodyComponent * ppbc = new PointPhysicsBodyComponent{physicsBody};

            Entity * particleEntity = new Entity{};
            particleEntity->addComponent(prc);
            particleEntity->addComponent(pskc);
            particleEntity->addComponent(ppbc);

            sceneManager.addEntity(particleEntity);
        }
    }

    ParticleSpawner(SceneManager &_sceneManager, GraphicsManager &_graphicsManager, unsigned int maxParticles):maxParticleCount(maxParticles), sceneManager(_sceneManager), graphicsManager(_graphicsManager)
    {

    }

    ~ParticleSpawner()
    {

    }

    void registerDestruction()
    {
        maxParticleCount--;
    }

    private:
    unsigned int currentParticleCount{0};
    unsigned int maxParticleCount;
    SceneManager &sceneManager;
    GraphicsManager &graphicsManager;

    GraphicsManager::Color getRandomColor()
    {
        return GraphicsManager::Color{};
    }

    math::Vector2 getRandomAcceleration()
    {
        return math::Vector2{};
    }

};

class PointRendererComponent : public Component, public IRenderable
{
    public:
    PointRendererComponent(GraphicsManager &gm, const GraphicsManager::Color &_color):Component(), graphicsManager(gm), color(_color)
    {
    }

    void render(float dt=0.0f) override
    {
        graphicsManager.drawPoint(owner->getTransform().position, color);
    }

    private:
    GraphicsManager &graphicsManager;
    GraphicsManager::Color color;
};

class PointSpawnerKillerComponent : public Component, public ILogicable
{
    public:
    PointSpawnerKillerComponent(const float &_lifespan, ParticleSpawner &_spawner):Component(), lifespan(_lifespan), spawner(_spawner)
    {

    }

    void think(float dt) override
    {
        lifespan -= dt;
        getOwner()->Destroy();
        spawner.spawnParticles(owner->getTransform().position, 5);
        spawner.registerDestruction();
    }

    private:
    float lifespan;
    ParticleSpawner &spawner;
};

class PointPhysicsBodyComponent : public Component, IPhysicsable
{
    public:
    PointPhysicsBodyComponent(fizzyx::tutorial::PointMassEntity * _physicsBody):Component(), physicsBody(_physicsBody)
    {

    }

    void physicsUpdate(float dt)
    {
        Transform transform = owner->getTransform();
        transform.position = physicsBody->getPosition();
        owner->setTransform(transform);
    }

    private:
    fizzyx::tutorial::PointMassEntity *physicsBody;
};




class FireworksApp : public DemoApp
{
    public:
    FireworksApp():DemoApp("Fireworks", 1024, 768)
    {

    }

    virtual ~FireworksApp()
    {

    }

    void setup() override
    {

    }

    void tearDown() override
    {

    }

    protected:
    void drawScene() override
    {
        graphicsManager.drawRectOutline(math::Vector2{160.0f, 250.0f}, 60, 90, GraphicsManager::Color{}, rotation);
        graphicsManager.drawPoint(math::Vector2{180.0f, 400.0f}, GraphicsManager::Color{0, 255, 0, 255}, 2.0f);

    }

    void updateLogic() override
    {
        rotation = std::fmodf(rotation + 2.0f, 360.0f);
    }

    void drawGUI() override
    {
    }

    private:
    float rotation{0.0f};
};

int main(int argc, char **argv)
{
    FireworksApp fireworks{};
    fireworks.setup();
    fireworks.mainLoop();
    fireworks.tearDown();

    return 0;
}