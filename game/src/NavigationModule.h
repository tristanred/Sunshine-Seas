#pragma once

#include <Game/Game.h>

#include "Player.h"
#include "Navigation/Map.h"
#include "Navigation/Navigator.h"
#include "Navigation/PointListNavigator.h"
#include "Navigation/NavigationCamera.h"
#include "Star.h"
#include "IdleNavigator.h"

class TestSprite : public ASprite
{
public:
    TestSprite(GameEngine* engine);
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
    Star* starObject;

    AFont* collisionFont;
    AText* collisionText;

    ATexture* polygonTexture;

    PointListNavigator* navig;

    IdleNavigator* NPC_Boat;

    void Update(unsigned int deltaTime) override;
    void Draw(ARenderer* renderer) override;
};
