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

    void Init(const char* title ,int xpos, int ypos, int width, int height, bool fullscreen, int channels);

    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    bool Running();

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    FMOD_SYSTEM *audio_system;
};

#endif // GAME_H
