#include "NavigationModule.h"

#include <ResourceManager.h>
#include <Input/AKeyboard.h>

#include "Navigation/Pathfinding.h"

TestSprite::TestSprite(ARenderer* renderer)
    : ASprite(renderer)
{
}

TestSprite::~TestSprite()
{
}

NavigationModule::NavigationModule(GameEngine* engine)
    : GameModule(engine)
{
    engine->ResManager->AddAssetRoot("assets");

    this->WorldMap = new Map(this->GetEngine());
    this->AttachRenderable(this->WorldMap);

    this->GamePlayer = new Player();
    this->GamePlayer->Setup(this);
}

NavigationModule::~NavigationModule()
{
}

void NavigationModule::Update(unsigned int deltaTime)
{
    GameModule::Update(deltaTime);
    
    if(this->GetEngine()->Keyboard->IsKeyClicked(Key::Space))
    {
        this->GetRenderer()->SaveToFile(this->WorldMap, "before.png");
        
        NavigationCell* from = this->WorldMap->GetCell(0, 3);
        NavigationCell* to = this->WorldMap->GetCell(15, 1);
        //NavigationCell* to = this->WorldMap->GetCell(2, 2);
        
        auto path = Pathfind(from, to, NULL, NULL);
        
        NavigationCell* previous = path->Get(0);
        for(int i = 1; i < path->Count(); i++)
        {
            NavigationCell* current = path->Get(i);
            
            this->WorldMap->MapImage->GetTexture()->DrawLine(previous->inner->GetCenter(), current->inner->GetCenter(), 0x0000FFFF, 2);
            
            previous = current;
        }
        
        this->GetRenderer()->SaveToFile(this->WorldMap, "after.png");
    }

    //this->WorldMap->Update(deltaTime);
    this->GamePlayer->Update(deltaTime);
}

void NavigationModule::Draw(ARenderer* renderer)
{
    GameModule::Draw(renderer);

    this->GamePlayer->Draw();
}
