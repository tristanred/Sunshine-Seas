#pragma once

#include <Game/Game.h>
#include <libtech/arraylist.h>
#include "Pathfinding.h"
#include "Navigator.h"

class PointListNavigator : public Navigator
{
public:
    PointListNavigator(ArrayList<NavigationCell*>* points);
    virtual ~PointListNavigator();

    void Start(unsigned int totalTime) override;
    void Update(unsigned int deltaTime) override;

protected:
    ArrayList<NavigationCell*>* NavigationPoints;

    uint32_t CurrentPointTime;
    uint32_t TimePerPoint;

    // Index of the next point we're going to
    int currentPointIndex;
    NavigationCell* CurrentPoint;
    NavigationCell* NextPoint;
};
