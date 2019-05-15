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
    
    NavigationCell* up_left;
    NavigationCell* up_right;
    NavigationCell* down_right;
    NavigationCell* down_left;
    
    bool IsPassable() override;
    ITraversable* Left() override;
    ITraversable* Up() override;
    ITraversable* Right() override;
    ITraversable* Down() override;
    
    ITraversable* Up_Left() override;
    ITraversable* Up_Right() override;
    ITraversable* Down_Right() override;
    ITraversable* Down_Left() override;
};
