#pragma once

class Grid;
class NavigationModule;

#include <microengine.h>

class World
{
public:
    World(NavigationModule* module);
    virtual ~World();

    void PopulateWithTestData();

    void Update(unsigned int deltaTime);
    void Draw(ARenderer* renderer);

    FRectangle GetBounds();

private:
    GameEngine* engine;
    NavigationModule* module;

    std::vector<Grid*>* grids;
};