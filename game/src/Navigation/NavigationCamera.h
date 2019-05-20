#pragma once

#include <Game/Game.h>
#include <Viewport.h>

class NavigationCamera
{
public:
    NavigationCamera(GameEngine* engine);
    ~NavigationCamera();
    
    void Activate();

    void TrackObject(ARenderable* target);

    void Update(unsigned int deltaTime);

private:
    GameEngine* eng;

    ARenderable* Target;

    Viewport* cameraVP;
};
