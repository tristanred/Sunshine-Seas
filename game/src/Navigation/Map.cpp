#include "Map.h"

#include "Pathfinding.h"

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

    ArrayList<NavigationCell*>* cells = new ArrayList<NavigationCell*>(gridWidth * gridHeight);
    for(int i = 0; i < gridWidth; i++)
    {
        for(int k = 0; k < gridHeight; k++)
        {
            FRectangle* gridsRect = new FRectangle(i * 64, k * 64, 64, 64);
            mapTex->StrokeRect(*gridsRect, 2, 0xFF0000FF);
            
            NavigationCell* cell = new NavigationCell(gridsRect);
            cells->Add(cell);
        }
    }
    
    auto cellsArray = cells->GetListAs2dArray(gridWidth);
    for(int i = 0; i < gridWidth; i++)
    {
        for(int k = 0; k < gridHeight; k++)
        {
            // Assign navigation properties
            NavigationCell* cell = cellsArray[i][k];
            if(i > 0)
            {
                cell->left = cellsArray[i - 1][k];
            }
            if(i < gridWidth - 1)
            {
                cell->right = cellsArray[i + 1][k];
            }
            if(k > 0)
            {
                cell->up = cellsArray[i][k - 1];
            }
            if(k < gridHeight - 1)
            {
                cell->down = cellsArray[i][k + 1];
            }

            // Assign passable/blocked properties
            if (cell->rect->Intersect(islandOne) || cell->rect->Intersect(islandTwo))
            {
                cell->passable = false;
            }
            else
            {
                cell->passable = true;
            }
        }
    }

}

Map::~Map()
{

}
