#include <stdio.h>

#include <GameEngine.h>

#include "NavigationModule.h"

#include "World/Landmass.h"
#include "World/Settlement.h"
#include "World/Grid.h"
#include "World/World.h"

int main(int argc, char** argv)
{
    GameEngine eng;
    eng.Initialize();

    eng.ActivateModule<NavigationModule>();


    eng.Play();

    return 0;
}