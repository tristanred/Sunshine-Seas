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
    
    this->camera = new NavigationCamera(this->GetEngine());
    this->camera->TrackObject(this->GamePlayer->PlayerSprite);
    this->camera->Activate();

    this->navig = NULL;
}

NavigationModule::~NavigationModule()
{
}

void NavigationModule::Update(unsigned int deltaTime)
{
    GameModule::Update(deltaTime);
    
    this->camera->Update(deltaTime);

    if(this->GetEngine()->Keyboard->IsKeyClicked(Key::Space))
    {
        this->WorldMap->GraphicLayer->GetTexture()->FillColor(0x00000000);
        this->GetRenderer()->SaveToFile(this->WorldMap, "before.png");

        FPosition playerPos = this->GamePlayer->PlayerSprite->GetRectangle().GetCenter();
        
        auto playerCell = this->WorldMap->GetCurrentCell(playerPos);
        NavigationCell* to = this->WorldMap->GetCell(15, 1);

        auto path = Pathfind(playerCell, to, NULL, NULL);

        if(path == NULL)
        {
            LogWarning("NO PATH FOUND.");
        }
        else
        {
            NavigationCell* previous = path->Get(0);
            for(int i = 1; i < path->Count(); i++)
            {
                NavigationCell* current = path->Get(i);

                this->WorldMap->GraphicLayer->GetTexture()->DrawLine(previous->inner->GetCenter(), current->inner->GetCenter(), 0x0000FFFF, 2);

                previous = current;
            }
            
            if(this->navig != NULL)
            {
                delete(this->navig);
            }

            this->navig = new PointListNavigator(path);
            this->navig->Object = this->GamePlayer->PlayerSprite;
            this->navig->Start(10000);
        }

        this->GetRenderer()->SaveToFile(this->WorldMap, "after.png");
    }

    //this->WorldMap->Update(deltaTime);
    this->GamePlayer->Update(deltaTime);

    if(this->navig != NULL)
    {
        deltaTime = 22;
        this->navig->Update(deltaTime);
    }
}

void NavigationModule::Draw(ARenderer* renderer)
{
    GameModule::Draw(renderer);

    this->GamePlayer->Draw();
}
