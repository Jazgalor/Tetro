#include "Game.h"

int main()
{

    Game tetro;

    while (tetro.running())
    {
        tetro.update();
        tetro.render();
    }

    return 0;
}