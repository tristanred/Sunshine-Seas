#pragma once

#include <Game/Navigation/ITraversable.h>
#include <libtech/geometry.h>

class NavigationCell : public ITraversable
{
public:
    NavigationCell(FRectangle* r);
    ~NavigationCell();
    
    FRectangle* rect;
    bool passable;
    NavigationCell* left;
    NavigationCell* up;
    NavigationCell* right;
    NavigationCell* down;
    
    bool IsPassable() override;
    ITraversable* Left() override;
    ITraversable* Up() override;
    ITraversable* Right() override;
    ITraversable* Down() override;
};
