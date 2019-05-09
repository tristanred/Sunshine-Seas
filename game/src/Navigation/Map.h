#pragma once

#include <Game/Game.h>
#include <libtech/arraylist.h>
#include <libtech/geometry.h>

class Map : public ARenderable
{
public:
    Map(GameEngine* engine);
    ~Map();

    ASprite* MapImage;
    ArrayList<FRectangle*>* islands;

private:
    GameEngine* engine;
};