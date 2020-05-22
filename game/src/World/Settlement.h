#pragma once

#include <microengine.h>
#include <vector>

struct SettlementCreationSettings
{
    char textureName[256];

    char settlementName[256];

    uint8_t settlementType;  // Village, City, port, etc

    uint32_t populationCount;

    // Where the texture of the settlement should be placed within the
    // parent island.
    FPosition islandPosition;
};

class Settlement : public RenderableObject
{
public:
    Settlement(GameEngine* engine);
    virtual ~Settlement();

    static Settlement* CreateFromSettings(GameEngine* engine,
                                          SettlementCreationSettings* settings);
};
