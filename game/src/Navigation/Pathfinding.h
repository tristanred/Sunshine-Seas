#pragma once

#include <Game/Navigation/ITraversable.h>
#include <libtech/geometry.h>

class NavigationCell : public ITraversable<FRectangle>
{
public:
    NavigationCell(FRectangle* r);
    ~NavigationCell();
    
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
    NavigationCell* Left() override;
    NavigationCell* Up() override;
    NavigationCell* Right() override;
    NavigationCell* Down() override;
    
    NavigationCell* Up_Left() override;
    NavigationCell* Up_Right() override;
    NavigationCell* Down_Right() override;
    NavigationCell* Down_Left() override;
};
