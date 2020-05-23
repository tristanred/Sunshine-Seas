#pragma once

class World;
class Player;

#include <microengine.h>

/**
 * Game Component used to restrict the Player inside a specific rectangle.
 */
class WorldBoundsLimiter
{
public:
    WorldBoundsLimiter(World* world);
    virtual ~WorldBoundsLimiter();

    /**
     * Select the player that will be constrained.
     */
    void TargetPlayer(Player* player);

    /**
     * Component update method.
     */
    void Update(unsigned int deltaTime);

private:
    FRectangle bounds;
    Player* target;
};