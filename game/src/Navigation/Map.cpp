#include "Map.h"

#include "Pathfinding.h"
#include <libtech/stdutils.h>

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

    GridWidth = mapTex->GetSize().Width / GRIDSIZE;
    GridHeight = mapTex->GetSize().Height / GRIDSIZE;

    this->navigationGrid = new ArrayList<NavigationCell*>(GridWidth * GridHeight);
    for(int i = 0; i < GridWidth; i++)
    {
        for(int k = 0; k < GridHeight; k++)
        {
            FRectangle* gridsRect = new FRectangle(i * GRIDSIZE, k * GRIDSIZE, GRIDSIZE, GRIDSIZE);
            mapTex->StrokeRect(*gridsRect, 1, 0xFF0000FF);

            NavigationCell* cell = new NavigationCell(gridsRect);
            this->navigationGrid->Add(cell);
        }
    }

    auto cellsArray = this->navigationGrid->GetListAs2dArray(GridWidth);
    for(int i = 0; i < GridHeight; i++)
    {
        for(int k = 0; k < GridWidth; k++)
        {
            // Assign navigation properties
            // Orthogonal
            NavigationCell* cell = cellsArray[i][k];
            if(i > 0)
            {
                cell->left = cellsArray[i - 1][k];
            }
            if(i < GridWidth - 1)
            {
                cell->right = cellsArray[i + 1][k];
            }
            if(k > 0)
            {
                cell->up = cellsArray[i][k - 1];
            }
            if(k < GridHeight - 1)
            {
                cell->down = cellsArray[i][k + 1];
            }
            // Diagonal
            if(i != 0 && k != 0)
            {
                cell->up_left = cellsArray[i - 1][k - 1];
            }
            if(i != 0 && k != GridWidth - 1)
            {
                cell->up_right = cellsArray[i - 1][k + 1];
            }
            if(i != GridHeight - 1 && k != GridWidth - 1)
            {
                cell->down_right = cellsArray[i + 1][k + 1];
            }
            if(i != GridHeight - 1 && k != 0)
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

    DELETE_XDIM_ARRAY(cellsArray, GridHeight);
}

Map::~Map()
{

}

NavigationCell* Map::GetCurrentCell(FPosition playerPosition)
{
    for(int i = 0; i < navigationGrid->Count(); i++)
    {
        NavigationCell* cell = navigationGrid->Get(i);
        if(cell->inner->PointIsInside(playerPosition))
        {
            return cell;
        }
    }
    
    return NULL;
}

NavigationCell* Map::GetCell(int column, int row)
{
    int index = (column * this->GridWidth) + row;
    return navigationGrid->Get(index);
}
