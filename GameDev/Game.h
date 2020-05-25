#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();

    void Init(const char* title ,int xpos, int ypos, int width, int height, bool fullscreen);

    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    bool Running();

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif // GAME_H
