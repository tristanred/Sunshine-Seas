#include "NavigationModule.h"

#include <Input/AKeyboard.h>
#include <ResourceManager.h>
#include <libtech/geometry.h>
#include "DrawShapeHelper.h"
#include "Navigation/Pathfinding.h"

NavigationModule::NavigationModule(GameEngine* engine) : GameModule(engine)
{
    // engine->Renderer->SetWindowSize(NULL, true);

    engine->ResManager->AddAssetRoot("assets");

    this->GamePlayer = new Player(this->GetEngine());
    this->GamePlayer->Setup(this);

    this->camera = new NavigationCamera(this->GetEngine());
    this->camera->TrackObject(this->GamePlayer->PlayerSprite,
                              FRectangle(0, 0, GRID_SIZE * 3, GRID_SIZE * 3));
    this->camera->Activate();

    this->world = new World(this);
    this->world->PopulateWithTestData();

    playerAreaLimiter = new WorldBoundsLimiter(this->world);
    playerAreaLimiter->TargetPlayer(this->GamePlayer);
}

NavigationModule::~NavigationModule() {}

void NavigationModule::Update(unsigned int deltaTime)
{
    GameModule::Update(deltaTime);

    this->world->Update(deltaTime);
    this->GamePlayer->Update(deltaTime);

    this->camera->Update(deltaTime);

    playerAreaLimiter->Update(deltaTime);
}

void NavigationModule::Draw(ARenderer* renderer)
{
    this->world->Draw(renderer);

    GameModule::Draw(renderer);
}
