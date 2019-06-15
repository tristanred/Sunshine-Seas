#include  "IdleNavigator.h"

#include "Navigation/PointListNavigator.h"
#include "Navigation/Map.h"
#include "Navigation/Pathfinding.h"

IdleNavigator::IdleNavigator(GameEngine*  engine)
    : RenderableObject(engine)
{
    this->NPC_Texture  = engine->CreateTexture();
    this->NPC_Texture->SetSolidColor(FSize(50, 50), 0xFFFF00FF);

    this->Avatar =  engine->CreateSprite();
    this->Avatar->SetTexture(this->NPC_Texture);

    this->AddChild(this->Avatar);

    this->CurrentList = new Queue<vec2*>();
    this->OriginalList = new Queue<vec2*>();

    this->OriginalList->Push(new vec2(0, 0));
    this->OriginalList->Push(new vec2(100, 400));
    this->OriginalList->Push(new vec2(600, 200));
    this->OriginalList->Push(new vec2(1000, 150));

    this->navig = NULL;
    this->gameMap = NULL;

    this->currentState = IDLE;
}

IdleNavigator::~IdleNavigator()
{
    this->GetEngine()->ReleaseObject(this->NPC_Texture);
    this->GetEngine()->ReleaseObject(this->Avatar);

    if(this->navig != NULL)
        delete(this->navig);
}

void IdleNavigator::SetupNavigation(Map* map)
{
    this->gameMap = map;

    this->CurrentList->PushRange(this->OriginalList);

    this->currentState = DESTINATION_REACHED;
}

void IdleNavigator::Update(unsigned int deltaTime)
{
    switch(this->currentState)
    {
        case IDLE:
        {
            return;
        }
        case NAVIGATING:
        {
            if(this->navig != NULL)
            {
                this->navig->Update(deltaTime);
            }

            if(this->navig->IsActive == false)
            {
                this->currentState = DESTINATION_REACHED;
            }

            break;
        }
        case DESTINATION_REACHED:
        {
            vec2* next =  this->CurrentList->Pop();

            if(next == NULL)
            {
                this->currentState = NAVIG_ENDED;

                break;
            }

            NavigationCell* currentCell = gameMap->GetCellFromCoordinates(this->GetPosition().AsVec());
            NavigationCell* nextCell = gameMap->GetCellFromCoordinates(*next);

            auto firstSegment = Pathfind(currentCell, nextCell, NULL, NULL);

            if(this->navig != NULL)
            {
                delete(this->navig);
            }

            this->navig = new PointListNavigator(firstSegment);
            this->navig->Object = this;
            this->navig->Start(10000);

            this->currentState = NAVIGATING;

            break;
        }
        case NAVIG_ENDED:
        {
            this->CurrentList->PushRange(this->OriginalList);

            this->currentState = DESTINATION_REACHED;

            break;
        }
    }

    if(this->navig != NULL)
    {
        this->navig->Update(deltaTime);
    }
}
