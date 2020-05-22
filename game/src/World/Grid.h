#pragma once

#define GRID_SIZE 4096

class Landmass;
struct LandmassCreationSettings;

#include <microengine.h>
#include <vector>

struct GridCreationSettings
{
    std::vector<LandmassCreationSettings*>* islands;
};

class Grid : public RenderableObject
{
public:
    Grid(GameEngine* engine);
    virtual ~Grid();

    static Grid* CreateFromSettings(GameEngine* engine,
                                    GridCreationSettings* settings);

    static Grid* CreateBlank(GameEngine* engine);

    bool isLoaded;
    void Load();
    void Unload();

    std::vector<Landmass*>* islands;
};
