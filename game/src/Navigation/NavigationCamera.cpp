#include "NavigationCamera.h"

#include <math.h>

NavigationCamera::NavigationCamera(GameEngine* engine)
{
    this->eng = engine;

    this->cameraVP = eng->CreateViewport();

    this->Target = NULL;
}

NavigationCamera::~NavigationCamera()
{
}

void NavigationCamera::Activate()
{
    this->eng->SelectViewport(this->cameraVP);
}

void NavigationCamera::TrackObject(RenderableObject* target, FRectangle bounds)
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

    this->cameraVP->CurrentView.X = (float)fmax(this->cameraVP->CurrentView.X, this->trackingBounds.Left());
    this->cameraVP->CurrentView.Y = (float)fmax(this->cameraVP->CurrentView.Y, this->trackingBounds.Top());

    this->cameraVP->CurrentView.X = (float)fmin(this->cameraVP->CurrentView.X, (double)this->trackingBounds.Right() - (double)this->cameraVP->CurrentView.Width);
    this->cameraVP->CurrentView.Y = (float)fmin(this->cameraVP->CurrentView.Y, (double)this->trackingBounds.Bottom() - (double)this->cameraVP->CurrentView.Height);
}
