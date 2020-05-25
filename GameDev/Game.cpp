#include "Game.h"

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen, int channels)
{
    int flag = 0;
    FMOD_RESULT result;
    if(fullscreen)
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS|SDL_INIT_TIMER) == 0)
    {
        isRunning = true;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        if(!window)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
            isRunning = false;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        if(!renderer)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
            isRunning = false;
        }
        if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", IMG_GetError(), NULL);
            isRunning = false;
        }
        if(TTF_Init() == -1)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", TTF_GetError(), NULL);
            isRunning = false;
        }
    }
    else
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "SDL init failed", NULL);
    }

    result = FMOD_System_Create(&audioSystem);
    if(result != FMOD_OK)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", FMOD_ErrorString(result), NULL);
        isRunning = false;
    }

    result = FMOD_System_Init(audioSystem, channels, FMOD_INIT_NORMAL, NULL);
    if(result != FMOD_OK)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", FMOD_ErrorString(result), NULL);
        isRunning = false;
    }
}

void Game::handleEvents()
{
    SDL_Event event;

    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{}

void Game::render()
{
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    FMOD_System_Close(audioSystem);
    FMOD_System_Release(audioSystem);
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::running()
{
    return isRunning;
}
