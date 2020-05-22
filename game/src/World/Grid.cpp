#include "Grid.h"

#include "Landmass.h"

Grid::Grid(GameEngine* engine) : RenderableObject(engine)
{
    this->isLoaded = true;
    this->islands = new std::vector<Landmass*>();
}

Grid::~Grid() {}

Grid* Grid::CreateFromSettings(GameEngine* engine,
                               GridCreationSettings* settings)
{
    Grid* newGrid = new Grid(engine);
    newGrid->SetSize(4096, 4096);

    auto tex = engine->CreateTexture("grid.png");
    newGrid->SetTexture(tex);

    auto begin = settings->islands->begin();
    auto end = settings->islands->end();
    while(begin != end)
    {
        LandmassCreationSettings* ld = *begin;

        Landmass* lm = Landmass::CreateFromSettings(engine, ld);

        newGrid->islands->push_back(lm);
        newGrid->AddChild(lm);

        begin++;
    }

    return newGrid;
}

Grid* Grid::CreateBlank(GameEngine* engine)
{
    Grid* newGrid = new Grid(engine);
    newGrid->SetSize(4096, 4096);

    auto tex = engine->CreateTexture("grid.png");
    newGrid->SetTexture(tex);

    return newGrid;
}
