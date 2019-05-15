#include "Pathfinding.h"

NavigationCell::NavigationCell(FRectangle* r)
{
    this->passable = true;
    this->rect = r;
    
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

ITraversable* NavigationCell::Left()
{
    return this->left;
}

ITraversable* NavigationCell::Up()
{
    return this->up;
}

ITraversable* NavigationCell::Right()
{
    return this->right;
}

ITraversable* NavigationCell::Down()
{
    return this->down;
}

ITraversable* NavigationCell::Up_Left()
{
    return this->up_left;
}

ITraversable* NavigationCell::Up_Right()
{
    return this->up_right;
}

ITraversable* NavigationCell::Down_Right()
{
    return this->down_right;
}

ITraversable* NavigationCell::Down_Left()
{
    return this->down_left;
}
