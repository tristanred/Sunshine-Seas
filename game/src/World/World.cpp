#include "World.h"

#include "Grid.h"
#include "Landmass.h"
#include "Settlement.h"
#include "../NavigationModule.h"

World::World(NavigationModule* module)
{
    this->module = module;
    this->engine = module->GetEngine();
    this->grids = new std::vector<Grid*>();
}

World::~World() {}

void World::PopulateWithTestData()
{
    SettlementCreationSettings town_g0;
    strcpy(town_g0.settlementName, "Town 0");
    strcpy(town_g0.textureName, "town.png");
    town_g0.islandPosition = FPosition(250, 500);
    town_g0.populationCount = 100;
    town_g0.settlementType = 0;

    LandmassCreationSettings island_g0_settings;
    strcpy(island_g0_settings.islandName, "Island G0");
    strcpy(island_g0_settings.textureName, "island.png");
    island_g0_settings.size = 100;
    island_g0_settings.settlements =
        new std::vector<SettlementCreationSettings*>();
    island_g0_settings.settlements->push_back(&town_g0);
    island_g0_settings.coordinates = FPosition(1738, 1651);

    GridCreationSettings g0_settings;
    g0_settings.islands = new std::vector<LandmassCreationSettings*>();
    g0_settings.islands->push_back(&island_g0_settings);

    Grid* g0 = Grid::CreateFromSettings(this->engine, &g0_settings);
    Grid* g1 = Grid::CreateBlank(this->engine);
    Grid* g2 = Grid::CreateBlank(this->engine);

    Grid* g3 = Grid::CreateBlank(this->engine);
    Grid* g4 = Grid::CreateBlank(this->engine);
    Grid* g5 = Grid::CreateBlank(this->engine);

    SettlementCreationSettings town_g6;
    strcpy(town_g6.settlementName, "Town 6");
    strcpy(town_g6.textureName, "town.png");
    town_g6.islandPosition = FPosition(250, 500);
    town_g6.populationCount = 100;
    town_g6.settlementType = 0;

    LandmassCreationSettings island_g6_settings;
    strcpy(island_g6_settings.islandName, "Island G6");
    strcpy(island_g6_settings.textureName, "island.png");
    island_g6_settings.size = 100;
    island_g6_settings.settlements =
        new std::vector<SettlementCreationSettings*>();
    island_g6_settings.settlements->push_back(&town_g6);
    island_g6_settings.coordinates = FPosition(1738, 1651);

    GridCreationSettings g6_settings;
    g6_settings.islands = new std::vector<LandmassCreationSettings*>();
    g6_settings.islands->push_back(&island_g6_settings);

    Grid* g6 = Grid::CreateFromSettings(this->engine, &g6_settings);
    Grid* g7 = Grid::CreateBlank(this->engine);

    SettlementCreationSettings town_g8;
    strcpy(town_g8.settlementName, "Town 8");
    strcpy(town_g8.textureName, "town.png");
    town_g8.islandPosition = FPosition(250, 500);
    town_g8.populationCount = 100;
    town_g8.settlementType = 0;

    LandmassCreationSettings island_g8_settings;
    strcpy(island_g8_settings.islandName, "Island G8");
    strcpy(island_g8_settings.textureName, "island.png");
    island_g8_settings.size = 100;
    island_g8_settings.settlements =
        new std::vector<SettlementCreationSettings*>();
    island_g8_settings.settlements->push_back(&town_g8);
    island_g8_settings.coordinates = FPosition(1738, 1651);

    GridCreationSettings g8_settings;
    g8_settings.islands = new std::vector<LandmassCreationSettings*>();
    g8_settings.islands->push_back(&island_g8_settings);

    Grid* g8 = Grid::CreateFromSettings(this->engine, &g0_settings);

    this->grids->push_back(g0);
    this->grids->push_back(g1);
    this->grids->push_back(g2);
    this->grids->push_back(g3);
    this->grids->push_back(g4);
    this->grids->push_back(g5);
    this->grids->push_back(g6);
    this->grids->push_back(g7);
    this->grids->push_back(g8);

    g0->SetPosition(0, 0);
    g1->SetPosition(4096, 0);
    g2->SetPosition(8192, 0);
    g3->SetPosition(0, 4096);
    g4->SetPosition(4096, 4096);
    g5->SetPosition(8192, 4096);
    g6->SetPosition(0, 8192);
    g7->SetPosition(4096, 8192);
    g8->SetPosition(8192, 8192);

}

void World::Update(unsigned int deltaTime)
{
    auto begin = this->grids->begin();
    auto end = this->grids->end();

    while(begin != end)
    {
        Grid* grid = *begin;

        if(grid->isLoaded)
        {
            grid->Update(deltaTime);
        }

        begin++;
    }
}

void World::Draw(ARenderer* renderer)
{
    auto begin = this->grids->begin();
    auto end = this->grids->end();

    while(begin != end)
    {
        Grid* grid = *begin;

        if(grid->isLoaded)
        {
            renderer->Draw(grid);
        }

        begin++;
    }
}
