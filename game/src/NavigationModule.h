#pragma once

#include <Game/Game.h>

#include "IdleNavigator.h"
#include "Navigation/NavigationCamera.h"
#include "Player.h"
#include "World/Grid.h"
#include "World/Landmass.h"
#include "World/Settlement.h"
#include "World/World.h"
#include "Navigation/WorldBoundsLimiter.h"

class NavigationModule : public GameModule
{
public:
    NavigationModule(GameEngine* engine);
    ~NavigationModule();

    NavigationCamera* camera;
    WorldBoundsLimiter* playerAreaLimiter;
    Player* GamePlayer;

    World* world;

    void Update(unsigned int deltaTime) override;
    void Draw(ARenderer* renderer) override;
};
