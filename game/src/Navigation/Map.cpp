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
            mapTex->StrokeRect(*gridsRect, 1, 0xFF0000FF);
            
            NavigationCell* cell = new NavigationCell(gridsRect);
            cells->Add(cell);
        }
    }
    
    auto cellsArray = cells->GetListAs2dArray(gridWidth);
    for(int i = 0; i < gridHeight; i++)
    {
        for(int k = 0; k < gridWidth; k++)
        {
            // Assign navigation properties
            // Orthogonal
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
            // Diagonal
            if(i != 0 && k != 0)
            {
                cell->up_left = cellsArray[i - 1][k - 1];
            }
            if(i != 0 && k != gridWidth - 1)
            {
                cell->up_right = cellsArray[i - 1][k + 1];
            }
            if(i != gridHeight - 1 && k != gridWidth - 1)
            {
                cell->down_right = cellsArray[i + 1][k + 1];
            }
            if(i != gridHeight - 1 && k != 0)
            {
                cell->down_left = cellsArray[i + 1][k - 1];
            }

            // Assign passable/blocked properties
            if (cell->inner->Intersect(islandOne) || cell->inner->Intersect(islandTwo))
            {
                cell->passable = false;
                mapTex->FillRect(*cell->inner, 0xFF000032);
            }
            else
            {
                cell->passable = true;
                mapTex->FillRect(*cell->inner, 0x00FF0032);
            }
            
            // Draw some debug stuff
            //if(cell->Left() != NULL)
            //{
            //    mapTex->DrawLine(cell->inner->GetCenter(), cell->Left()->inner->GetCenter(), 0xFF0000FF, 2);
            //}
            //if(cell->Up() != NULL)
            //{
            //    mapTex->DrawLine(cell->inner->GetCenter(), cell->Up()->inner->GetCenter(), 0xFF0000FF, 2);
            //}
            //if(cell->Right() != NULL)
            //{
            //    mapTex->DrawLine(cell->inner->GetCenter(), cell->Right()->inner->GetCenter(), 0xFF0000FF, 2);
            //}
            //if(cell->Down() != NULL)
            //{
            //    mapTex->DrawLine(cell->inner->GetCenter(), cell->Down()->inner->GetCenter(), 0xFF0000FF, 2);
            //}
            //if(cell->Up_Left() != NULL)
            //{
            //    mapTex->DrawLine(cell->inner->GetCenter(), cell->Up_Left()->inner->GetCenter(), 0xFF0000FF, 2);
            //}
            //if(cell->Up_Right() != NULL)
            //{
            //    mapTex->DrawLine(cell->inner->GetCenter(), cell->Up_Right()->inner->GetCenter(), 0xFF0000FF, 2);
            //}
            //if(cell->Down_Right() != NULL)
            //{
            //    mapTex->DrawLine(cell->inner->GetCenter(), cell->Down_Right()->inner->GetCenter(), 0xFF0000FF, 2);
            //}
            //if(cell->Down_Left() != NULL)
            //{
            //    mapTex->DrawLine(cell->inner->GetCenter(), cell->Down_Left()->inner->GetCenter(), 0xFF0000FF, 2);
            //}
        }
    }

}

Map::~Map()
{

}
