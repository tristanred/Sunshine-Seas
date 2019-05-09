#include "NavigationModule.h"

#include <ResourceManager.h>
#include <Input/AKeyboard.h>


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
        this->GetRenderer()->SaveToFile(this->WorldMap, "out.png");
    }

    //this->WorldMap->Update(deltaTime);
    this->GamePlayer->Update(deltaTime);
}

void NavigationModule::Draw(ARenderer* renderer)
{
    GameModule::Draw(renderer);

    this->GamePlayer->Draw();
}
