#include "WorldBoundsLimiter.h"

#include "../Player.h"
#include "../World/World.h"

WorldBoundsLimiter::WorldBoundsLimiter(World* world)
{
    this->bounds = world->GetBounds();
}

WorldBoundsLimiter::~WorldBoundsLimiter() {}

void WorldBoundsLimiter::TargetPlayer(Player* player)
{
    this->target = player;
}

void WorldBoundsLimiter::Update(unsigned int deltaTime)
{
    FRectangle playerRect = this->target->GetRectangle();

    playerRect.PushInside(&this->bounds);

    this->target->SetPosition(playerRect.GetPosition());
}
