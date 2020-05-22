#pragma once

class World;
class Player;

#include <microengine.h>

class WorldBoundsLimiter
{
public:
    WorldBoundsLimiter(World* world);
    virtual ~WorldBoundsLimiter();

    void TargetPlayer(Player* player);
    void Update(unsigned int deltaTime);

private:
    FRectangle bounds;
    Player* target;
};