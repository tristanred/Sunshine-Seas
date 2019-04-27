#include <stdio.h>

#include <GameEngine.h>

int main(int argc, char** argv)
{
    GameEngine eng;

    eng.Initialize();

    eng.Play();

    return 0;
}