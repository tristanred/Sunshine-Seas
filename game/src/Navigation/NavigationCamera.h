#pragma once

#include <Game/Game.h>
#include <Viewport.h>

class NavigationCamera
{
public:
    NavigationCamera(GameEngine* engine);
    ~NavigationCamera();

    void Activate();

    void TrackObject(RenderableObject* target, FRectangle bounds);

    void Update(unsigned int deltaTime);

private:
    GameEngine* eng;

    RenderableObject* Target;
    FRectangle trackingBounds;

    Viewport* cameraVP;
};
