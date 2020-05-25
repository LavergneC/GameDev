#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

#ifdef __MINGW32__
#undef main
#endif

Game *game = nullptr;

int main(int argc, char** argv)
{
    game = new Game();

    game->init("Jeu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false, 32);

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
}
