#include "NavigationModule.h"

#include <ResourceManager.h>



NavigationModule::NavigationModule(GameEngine* engine)
    : GameModule(engine)
{
    engine->ResManager->AddAssetRoot("assets");

    this->WorldMap = this->CreateSprite();
    this->WorldMap->SetTexture("TestIsland.png");

    this->GamePlayer = new Player();
    this->GamePlayer->Setup(this);
}

NavigationModule::~NavigationModule()
{
}

void NavigationModule::Update(unsigned int deltaTime)
{
    GameModule::Update(deltaTime);

    this->WorldMap->Update(deltaTime);
    this->GamePlayer->Update(deltaTime);
}

void NavigationModule::Draw(ARenderer* renderer)
{
    GameModule::Draw(renderer);

    this->GamePlayer->Draw();
}