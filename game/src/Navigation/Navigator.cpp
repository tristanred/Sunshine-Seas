#include "Navigator.h"

Navigator::Navigator()
{
}

Navigator::~Navigator()
{
}

void Navigator::Start(unsigned int totalTime)
{
    this->TotalTime = totalTime;
    this->AccumulatedTime = 0;
}

void Navigator::Update(unsigned int deltaTime)
{
    this->AccumulatedTime += deltaTime;
}