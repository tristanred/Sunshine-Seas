#include "NavigationModule.h"

#include <ResourceManager.h>
#include <Input/AKeyboard.h>

#include "Navigation/Pathfinding.h"
#include <libtech/geometry.h>
#include "DrawShapeHelper.h"

TestSprite::TestSprite(GameEngine* engine)
    : ASprite(engine)
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
    this->camera->TrackObject(this->GamePlayer->PlayerSprite, this->WorldMap->GetRectangle());
    this->camera->Activate();

    this->navig = NULL;

    FPolygon pol;
    vec2 p1 = vec2(250, 0);
    vec2 p2 = vec2(500, 200);
    vec2 p3 = vec2(350, 500);
    vec2 p4 = vec2(150, 500);
    vec2 p5 = vec2(0, 200);
    pol.Set(5, &p1, &p2, &p3, &p4, &p5);
    this->polygonTexture = DrawObjectStroke(this->GetRenderer(), &pol);
    
    this->starObject = new Star(this->GetEngine());
    this->starObject->SetPosition(200, 200);
    this->AttachRenderable(this->starObject);
    
    this->collisionFont = this->CreateTextFont();
    this->collisionFont->LoadFontFile("assets/engine/arial.ttf");
    
    this->collisionText = this->CreateText(this->collisionFont);
    this->collisionText->SetColor(0x000000FF);
    this->collisionText->SetCharacterSize(72);
    this->collisionText->SetPositionSystem(POSITION_SYSTEM::VIEWPORT_STATIC);
    this->collisionText->SetPosition(500, 500);
    this->collisionText->SetText("COLLISION");
}

NavigationModule::~NavigationModule()
{
}

void NavigationModule::Update(unsigned int deltaTime)
{
    GameModule::Update(deltaTime);

    this->camera->Update(deltaTime);
    
    this->starObject->Update(deltaTime);
    
    FPolygon playerPol = this->GamePlayer->PlayerSprite->GetPolygon();
    FPolygon islandOnePol = this->WorldMap->islands->Get(0)->AsPolygon();
    
    if(playerPol.IsCollision(this->starObject->HitArea))
    {
        this->collisionText->Show(true);
        //printf("Oh dang");
    }
    else
    {
        this->collisionText->Show(false);
    }

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
}
