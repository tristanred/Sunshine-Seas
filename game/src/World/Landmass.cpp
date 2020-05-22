#include "Landmass.h"
#include "Settlement.h"

Landmass::Landmass(GameEngine* engine) : RenderableObject(engine)
{
    this->settlements = new std::vector<Settlement*>();
}
Landmass::~Landmass() {}

Landmass* Landmass::CreateFromSettings(GameEngine* engine,
                                       LandmassCreationSettings* settings)
{
    Landmass* lm = new Landmass(engine);

    auto tex = engine->CreateTexture(settings->textureName);
    lm->SetTexture(tex);
    lm->SetPosition(settings->coordinates);

    auto begin = settings->settlements->begin();
    auto end = settings->settlements->end();

    while(begin != end)
    {
        SettlementCreationSettings* setting = *begin;

        Settlement* newSettle = Settlement::CreateFromSettings(engine, setting);

        lm->settlements->push_back(newSettle);
        lm->AddChild(newSettle);

        begin++;
    }
    
    return lm;
}
