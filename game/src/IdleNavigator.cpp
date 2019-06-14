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

    //this->navig = new PointListNavigator()
}

IdleNavigator::~IdleNavigator()
{

}

void IdleNavigator::SetupNavigation(Map* map)
{
    NavigationCell* x = map->GetCell(0, 0);
    NavigationCell* x2 = map->GetCell(20, 2);

    auto firstSegment = Pathfind(x, x2, NULL, NULL);

    this->navig = new PointListNavigator(firstSegment);
    this->navig->Object = this;
    this->navig->Start(10000);
}

void IdleNavigator::Update(unsigned int deltaTime)
{
    if(this->navig != NULL)
    {
        this->navig->Update(deltaTime);
    }
}
