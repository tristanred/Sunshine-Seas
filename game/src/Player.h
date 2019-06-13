#pragma once

class GameEngine;

#include <Game/GameObject.h>
#include <Game/Game.h>
#include <libtech/vec.h>

#define MAX_VELOCITY 10

class Player : public GameObject
{
public:
    ASprite* PlayerSprite;

    vec2 velocity;

    Player(GameEngine* engine);
    ~Player();

    void Setup(GameModule* currentModule);
    void Update(unsigned int deltaTime) override;
};
