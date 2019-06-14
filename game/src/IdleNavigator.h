#pragma once

class PointListNavigator;
class Map;

#include <Game/Game.h>

class IdleNavigator : public RenderableObject
{
public:
    vec2 points[4];
    PointListNavigator* navig;

    ATexture* NPC_Texture;
    ASprite* Avatar;

    IdleNavigator(GameEngine* engine);
    ~IdleNavigator();

    void SetupNavigation(Map* map);

    virtual void Update(unsigned int deltaTime) override;

};