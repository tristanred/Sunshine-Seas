#include "PointListNavigator.h"

PointListNavigator::PointListNavigator(ArrayList<NavigationCell*>* points)
    : Navigator()
{
    this->NavigationPoints = points;

    this->TotalTime = 0;
    this->AccumulatedTime = 0;

    this->CurrentPointTime = 0;
    this->TimePerPoint = 0;
    this->CurrentPoint = NULL;
    this->NextPoint = NULL;
    this->currentPointIndex = NULL;
}

PointListNavigator::~PointListNavigator()
{

}

void PointListNavigator::Start(unsigned int totalTime)
{
    Navigator::Start(totalTime);

    this->IsActive = true;

    if(this->NavigationPoints != NULL &&
       this->NavigationPoints->Count() < 2)
    {
        LogWarning("Cannot navigate with fewer than 2 points.");

        return;
    }

    this->CurrentPointTime = 0;
    this->TimePerPoint = (uint32_t)(totalTime / this->NavigationPoints->Count());

    this->CurrentPoint = this->NavigationPoints->Get(0);
    this->NextPoint = this->NavigationPoints->Get(1);

    this->currentPointIndex = 1;
}

void PointListNavigator::Update(unsigned int deltaTime)
{
    Navigator::Update(deltaTime);

    if(this->IsActive == false)
        return;

    this->CurrentPointTime += deltaTime;
    float currentPointPercentage = (float)CurrentPointTime / (float)TimePerPoint;

    if(currentPointPercentage > 1.0)
    {
        currentPointPercentage = 1.0;
    }

    auto xDiff = NextPoint->inner->X - CurrentPoint->inner->X;
    auto yDiff = NextPoint->inner->Y - CurrentPoint->inner->Y;

    FPosition fPosDiff = FPosition(xDiff * currentPointPercentage, yDiff * currentPointPercentage);

    FPosition newPos = CurrentPoint->inner->GetPosition() + fPosDiff;
    this->Object->SetPosition(newPos);

    if(currentPointPercentage >= 1.0)
    {
        this->CurrentPointTime = 0;
        
        this->currentPointIndex++;
        this->CurrentPoint = this->NextPoint;
        this->NextPoint = this->NavigationPoints->Get(currentPointIndex);

        if(this->NextPoint == NULL)
        {
            // We're at the final destination.
            IsActive = false;
        }
    }
}
