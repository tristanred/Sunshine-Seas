#pragma once

#include <Game/Navigation/ITraversable.h>
#include <libtech/geometry.h>
#include <libtech/arraylist.h>

class NavigationCell : public ITraversable<FRectangle>
{
public:
    NavigationCell(FRectangle* r);
    ~NavigationCell();

    int weight;

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

    ArrayList<NavigationCell*>* GetAdjacents();
};

ArrayList<NavigationCell*>* Pathfind(NavigationCell* from, NavigationCell* to, ArrayList<NavigationCell*>* openList, ArrayList<NavigationCell*>* closedList);

int cell_distance(NavigationCell* one, NavigationCell* two);