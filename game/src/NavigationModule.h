#pragma once

#include <Game/Game.h>

#include "Player.h"
#include "Navigation/Map.h"
#include "Navigation/Navigator.h"
#include "Navigation/PointListNavigator.h"
#include "Navigation/NavigationCamera.h"

class TestSprite : public ASprite
{
public:
    TestSprite(ARenderer* renderer);
    ~TestSprite();
};

class NavigationModule : public GameModule
{
public:
    NavigationModule(GameEngine* engine);
    ~NavigationModule();

    NavigationCamera* camera;
    Player* GamePlayer;
    Map* WorldMap;

    PointListNavigator* navig;

    void Update(unsigned int deltaTime) override;
    void Draw(ARenderer* renderer) override;
};
