#pragma once

class Settlement;
struct SettlementCreationSettings;

#include <microengine.h>
#include <vector>

struct LandmassCreationSettings
{
    // Texturing information
    char textureName[256];

    // Geographical information
    char islandName[256];
    uint32_t size;          // Size in km^2
    FPosition coordinates;  // Relative position within grid.

    // Settlements
    std::vector<SettlementCreationSettings*>* settlements;
};

class Landmass : public RenderableObject
{
public:
    Landmass(GameEngine* engine);
    virtual ~Landmass();

    std::vector<Settlement*>* settlements;

    static Landmass* CreateFromSettings(GameEngine* engine,
                                        LandmassCreationSettings* settings);
};
