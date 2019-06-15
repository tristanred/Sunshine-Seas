#pragma once

class PointListNavigator;
class Map;

#include <Game/Game.h>
#include <libtech/arraylist.h>
#include <libtech/queue.h>

enum IDLENAV_STATES
{
    IDLE,
    NAVIGATING,
    DESTINATION_REACHED,
    NAVIG_ENDED
};

class IdleNavigator : public RenderableObject
{
public:
    Queue<vec2*>* CurrentList;
    Queue<vec2*>* OriginalList;

    Map* gameMap;
    PointListNavigator* navig;

    IDLENAV_STATES currentState;

    ATexture* NPC_Texture;
    ASprite* Avatar;

    IdleNavigator(GameEngine* engine);
    ~IdleNavigator();

    void SetupNavigation(Map* map);

    virtual void Update(unsigned int deltaTime) override;

};