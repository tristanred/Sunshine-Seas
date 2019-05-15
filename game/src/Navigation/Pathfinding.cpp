#include "Pathfinding.h"

NavigationCell::NavigationCell(FRectangle* r)
{
    this->passable = true;
    this->inner = r;
    
    this->left = NULL;
    this->up = NULL;
    this->right = NULL;
    this->down = NULL;
    
    this->up_left = NULL;
    this->up_right = NULL;
    this->down_right = NULL;
    this->down_left = NULL;
}

bool NavigationCell::IsPassable()
{
    return passable;
}

NavigationCell* NavigationCell::Left()
{
    return this->left;
}

NavigationCell* NavigationCell::Up()
{
    return this->up;
}

NavigationCell* NavigationCell::Right()
{
    return this->right;
}

NavigationCell* NavigationCell::Down()
{
    return this->down;
}

NavigationCell* NavigationCell::Up_Left()
{
    return this->up_left;
}

NavigationCell* NavigationCell::Up_Right()
{
    return this->up_right;
}

NavigationCell* NavigationCell::Down_Right()
{
    return this->down_right;
}

NavigationCell* NavigationCell::Down_Left()
{
    return this->down_left;
}
