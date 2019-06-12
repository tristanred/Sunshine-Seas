#pragma once

#include <Game/GameObject.h>
#include <Game/Game.h>
#include <libtech/vec.h>

#define MAX_VELOCITY 10

class Player : public GameObject
{
public:
    ASprite* PlayerSprite;

    vec2 velocity;

    Player();
    ~Player();

    void Setup(GameModule* currentModule) override;
    void Update(unsigned int deltaTime) override;
};
