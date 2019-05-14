#include "Pathfinding.h"

NavigationCell::NavigationCell(FRectangle* r)
{
    this->passable = true;
    this->rect = r;
    
    this->left = NULL;
    this->up = NULL;
    this->right = NULL;
    this->down = NULL;
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


