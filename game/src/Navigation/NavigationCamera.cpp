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

void NavigationCamera::TrackObject(ARenderable* target, FRectangle bounds)
{
    this->Target = target;
    this->trackingBounds = bounds;
}

void NavigationCamera::Update(unsigned int deltaTime)
{
    this->cameraVP->Update();

    FPosition playerPos = this->Target->GetPosition();

    this->cameraVP->CurrentView.X = playerPos.X - (this->cameraVP->CurrentView.Width / 2);
    this->cameraVP->CurrentView.Y = playerPos.Y - (this->cameraVP->CurrentView.Height / 2);

    this->cameraVP->CurrentView.X = fmax(this->cameraVP->CurrentView.X, this->trackingBounds.Left());
    this->cameraVP->CurrentView.Y = fmax(this->cameraVP->CurrentView.Y, this->trackingBounds.Top());

    this->cameraVP->CurrentView.X = fmin(this->cameraVP->CurrentView.X, this->trackingBounds.Right() - this->cameraVP->CurrentView.Width);
    this->cameraVP->CurrentView.Y = fmin(this->cameraVP->CurrentView.Y, this->trackingBounds.Bottom() - this->cameraVP->CurrentView.Height);
}
