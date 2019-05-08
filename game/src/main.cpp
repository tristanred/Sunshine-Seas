#include <stdio.h>

#include <GameEngine.h>

#include "NavigationModule.h" 

int main(int argc, char** argv)
{
    GameEngine eng;
    eng.Initialize();

    eng.CreateModule<NavigationModule>();


    eng.Play();

    return 0;
}