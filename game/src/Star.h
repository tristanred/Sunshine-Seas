#pragma once

#include <Game/Game.h>


class Star : public RenderableObject
{
public:
    Star(GameEngine* engine);
    ~Star();

    ASprite* StarImage;
    FPolygon* HitArea;

    void Update(unsigned int deltaTime);

};
