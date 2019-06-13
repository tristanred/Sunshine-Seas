#pragma once

#include <Game/Game.h>

class Navigator
{
public:
    Navigator();
    virtual ~Navigator();

    RenderableObject* Object;

    bool IsActive;

    virtual void Start(unsigned int totalTime);
    virtual void Update(unsigned int deltaTime);

protected:
    unsigned int TotalTime;
    unsigned int AccumulatedTime;
};
