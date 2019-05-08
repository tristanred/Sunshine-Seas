#pragma once

#include <Game/Game.h>

#include "Player.h"

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

    ASprite* WorldMap;

    void Update(unsigned int deltaTime) override;
    void Draw(ARenderer* renderer) override;
};