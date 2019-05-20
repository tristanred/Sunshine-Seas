#pragma once

#include <Game/Game.h>
#include <Viewport.h>

class NavigationCamera
{
public:
    NavigationCamera(GameEngine* engine);
    ~NavigationCamera();

    void Activate();

    void TrackObject(ARenderable* target, FRectangle bounds);

    void Update(unsigned int deltaTime);

private:
    GameEngine* eng;

    ARenderable* Target;
    FRectangle trackingBounds;

    Viewport* cameraVP;
};
