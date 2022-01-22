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

    void mainLoop()
    {
        SDL_Event e;

        while(isRunning())
        {
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    running = false;
                }
            }
            SDL_Delay(1);
        }
    }
};

int main(int argc, char **argv)
{
    FireworksApp fireworks{};
    fireworks.mainLoop();

    return 0;
}