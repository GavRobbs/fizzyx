#include <demoapp.h>

DemoApp::DemoApp(std::string windowName, int width, int height)
{
    graphicsManager.init(windowName, width, height);
}
    
DemoApp::~DemoApp()
{
    graphicsManager.terminate();
}
    
void DemoApp::mainLoop()
{

}

bool DemoApp::isRunning()
{
    return running;
}