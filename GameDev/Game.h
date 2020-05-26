#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <FMOD/fmod.h>
#include <FMOD/fmod_errors.h>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title ,int xpos, int ypos, int width, int height, bool fullscreen, int channels);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    FMOD_SYSTEM *audioSystem;
};

#endif // GAME_H
