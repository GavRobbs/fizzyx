#include <demoapp.h>
#include <SDL.h>

class FireworksApp : public DemoApp
{
    public:
    FireworksApp():DemoApp("Fireworks", 800, 600)
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

    }

    void updateLogic() override
    {

    }

    void drawGUI() override
    {
        bool show = true;
        ImGui::ShowDemoWindow(&show);
    }
};

int main(int argc, char **argv)
{
    FireworksApp fireworks{};
    fireworks.setup();
    fireworks.mainLoop();
    fireworks.tearDown();

    return 0;
}