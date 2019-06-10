#include "Star.h"

Star::Star(GameEngine* engine) : ARenderable(engine->Renderer)
{
    this->StarImage = engine->CreateSprite();
    this->StarImage->SetTexture("star.png");

    this->AddChild(this->StarImage);

    this->HitArea = new FPolygon();
    vec2 p1 = vec2(250, 0);
    vec2 p2 = vec2(315, 185);
    vec2 p3 = vec2(500, 200);
    vec2 p4 = vec2(350, 310);
    vec2 p5 = vec2(400, 500);
    vec2 p6 = vec2(250, 390);
    vec2 p7 = vec2(100, 500);
    vec2 p8 = vec2(150, 320);
    vec2 p9 = vec2(0, 190);
    vec2 p10 = vec2(185, 185);

    this->HitArea->Set(10, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10);
}

Star::~Star()
{

}

void Star::Update(unsigned int deltaTime)
{
    this->HitArea->Offset = vec2(this->GetPosition().X, this->GetPosition().Y);
}
