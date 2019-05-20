#include "NavigationCamera.h"

#include <math.h>

NavigationCamera::NavigationCamera(GameEngine* engine)
{
    this->eng = engine;

    this->cameraVP = eng->CreateViewport();
}

NavigationCamera::~NavigationCamera()
{
}

void NavigationCamera::Activate()
{
    this->eng->SelectViewport(this->cameraVP);
}

void NavigationCamera::TrackObject(ARenderable* target)
{
    this->Target = target;
}

void NavigationCamera::Update(unsigned int deltaTime)
{
    this->cameraVP->Update();

    FPosition playerPos = this->Target->GetPosition();

    this->cameraVP->CurrentView.X = playerPos.X - (this->cameraVP->CurrentView.Width / 2);
    this->cameraVP->CurrentView.Y = playerPos.Y - (this->cameraVP->CurrentView.Height / 2);
    
    this->cameraVP->CurrentView.X = fmax(this->cameraVP->CurrentView.X, 0);
    this->cameraVP->CurrentView.Y = fmax(this->cameraVP->CurrentView.Y, 0);
}
