#include "Settlement.h"

Settlement::Settlement(GameEngine* engine) : RenderableObject(engine) {}

Settlement::~Settlement() {}

Settlement* Settlement::CreateFromSettings(GameEngine* engine,
                                      SettlementCreationSettings* settings)
{
    Settlement* set = new Settlement(engine);

    auto tex = engine->CreateTexture(settings->textureName);
    set->SetTexture(tex);
    set->SetPosition(settings->islandPosition);

    return set;
}
