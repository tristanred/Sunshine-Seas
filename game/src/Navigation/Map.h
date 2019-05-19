#pragma once

class NavigationCell;

#include <Game/Game.h>
#include <libtech/arraylist.h>
#include <libtech/geometry.h>

#define GRIDSIZE 128

class Map : public ARenderable
{
public:
    Map(GameEngine* engine);
    ~Map();

    ASprite* MapImage;
    ArrayList<FRectangle*>* islands;

    NavigationCell* GetCurrentCell(FPosition playerPosition);

    NavigationCell* GetCell(int column, int row);

private:
    GameEngine* engine;
    
    int GridWidth;
    int GridHeight;

    ArrayList<NavigationCell*>* navigationGrid;
};
