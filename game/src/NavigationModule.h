#pragma once

#include <Game/Game.h>

#include "Player.h"
#include "Navigation/Map.h"


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

    Player* GamePlayer;

    Map* WorldMap;

    void Update(unsigned int deltaTime) override;
    void Draw(ARenderer* renderer) override;
};
