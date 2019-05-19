#include "Pathfinding.h"

#include <math.h>

NavigationCell::NavigationCell(FRectangle* r)
{
    this->weight = 0;

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

ArrayList<NavigationCell*>* NavigationCell::GetAdjacents()
{
    auto al = new ArrayList<NavigationCell*>();

    if(this->left != NULL) al->Add(this->left);
    if(this->up != NULL) al->Add(this->up);
    if(this->right != NULL) al->Add(this->right);
    if(this->down != NULL) al->Add(this->down);

    if(this->up_left != NULL) al->Add(this->up_left);
    if(this->up_right != NULL) al->Add(this->up_right);
    if(this->down_right != NULL) al->Add(this->down_right);
    if(this->down_left != NULL) al->Add(this->down_left);

    return al;
}

ArrayList<NavigationCell*>* Pathfind(NavigationCell* from, NavigationCell* to, ArrayList<NavigationCell*>* pOpenList, ArrayList<NavigationCell*>* pClosedList)
{
    ArrayList<NavigationCell*>* openList = NULL;
    ArrayList<NavigationCell*>* closedList = NULL;

    if(pOpenList == NULL || pClosedList == NULL)
    {
        openList = new ArrayList<NavigationCell*>();
        closedList = new ArrayList<NavigationCell*>();
    }
    else
    {
        openList = pOpenList;
        closedList = pClosedList;
    }

    // Add starting location to the closed list
    closedList->Add(from);
    openList->RemoveObject(from);

    // Add neighbors to the open list
    auto neighbors = from->GetAdjacents(); // TODO : delete()

    // Check each to see if they are passable
    for(int i = 0; i < neighbors->Count(); i++)
    {
        NavigationCell* cell = neighbors->Get(i);

        if(cell == to)
        {
            // We found the last node
            // TODO : Keep a link of parents and generate the final list
            // from that, instead of trusting the closedList.

            // Cleanup before we return.
            delete(neighbors);
            delete(openList);
            
            closedList->Add(cell);

            return closedList;
        }

        if(cell->IsPassable())
        {
            // Calculate heuristic distance
            cell->weight = cell_distance(cell, to);
            
            // Add neighbors to the open list, if they are not already in it
            bool check = openList->ContainsItem(cell);
            
            if(check == false)
            {
                openList->Insert(cell, 0);
            }
        }
    }
    delete(neighbors);

    // Get the cell in the open list with the lowest weigth
    NavigationCell* cell = NULL;
    for(int i = 0; i < openList->Count(); i++)
    {
        if(cell == NULL)
        {
            cell = openList->Get(i);
        }
        else
        {
            NavigationCell* current = openList->Get(i);
            if(current->weight <= cell->weight) // Get last with lowest weigth
            {
                cell = current;
            }
        }
    }

    if(cell == NULL)
    {
        // No cells found, openList must be fully enumerated
        return NULL;
    }

    return Pathfind(cell, to, openList, closedList);
}

int cell_distance(NavigationCell* one, NavigationCell* two)
{
    FPosition onePos = one->inner->GetCenter();
    FPosition twoPos = two->inner->GetCenter();

    auto distance = sqrt(pow(onePos.X - twoPos.X, 2) + pow(onePos.Y - twoPos.Y, 2));

    return int(distance);
}
