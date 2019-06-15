#pragma once

class NavigationCell;

#include <Game/Game.h>
#include <libtech/arraylist.h>
#include <libtech/geometry.h>

#define GRIDSIZE 64

class Map : public RenderableObject
{
public:
    Map(GameEngine* engine);
    ~Map();

    ASprite* MapImage;
    ASprite* GraphicLayer;
    ArrayList<FRectangle*>* islands;

    NavigationCell* GetCurrentCell(FPosition playerPosition);

    NavigationCell* GetCell(int column, int row);

    NavigationCell* GetCellFromCoordinates(int x, int y);
    NavigationCell* GetCellFromCoordinates(vec2 coords);


private:
    GameEngine* engine;

    int GridWidth;
    int GridHeight;

    ArrayList<NavigationCell*>* navigationGrid;
};
