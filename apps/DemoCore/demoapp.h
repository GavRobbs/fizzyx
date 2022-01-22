#ifndef DEMOAPP_H
#define DEMOAPP_H

#include <graphicsmanager.h>
#include <string>

class DemoApp
{
    public:
    DemoApp(std::string windowName, int width, int height);
    virtual ~DemoApp();
    virtual void mainLoop();
    bool isRunning();

    protected:
    bool running{true};
    GraphicsManager graphicsManager;
};

#endif