#include "Map.h"

Map::Map(GameEngine* engine)
    : ARenderable(engine->Renderer)
{
    this->engine = engine;

    this->MapImage = engine->CreateSprite();
    this->MapImage->SetTexture("world01.png");

    ATexture* mapTex = this->MapImage->GetTexture();
    //FRectangle r = FRectangle(0, 25, 70, 70);
    //mapTex->StrokeRect(r, 4, 0xFF44CCFF);

    FRectangle* islandOne = new FRectangle(287, 148, 219, 192);
    FRectangle* islandTwo = new FRectangle(781, 76, 151, 130);
    this->islands = new ArrayList<FRectangle*>();
    this->islands->Add(islandOne);
    this->islands->Add(islandTwo);

    this->AddChild(this->MapImage);

    int gridWidth = mapTex->GetSize().Width / 64;
    int gridHeight = mapTex->GetSize().Height / 64;

    for(int i = 0; i < gridWidth; i++)
    {
        for(int k = 0; k < gridHeight; k++)
        {
            FRectangle gridsRect = FRectangle(i * 64, k * 64, 64, 64);
            mapTex->StrokeRect(gridsRect, 2, 0xFF0000FF);
        }
    }
}

Map::~Map()
{

}
