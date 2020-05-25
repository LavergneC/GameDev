#include "Game.h"

Game::Game()
{}

Game::~Game()
{}

void Game::Init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flag = 0;
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
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Window init failed", NULL);
            isRunning = false;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        if(!renderer)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Renderer init failed", NULL);
            isRunning = false;
        }
        if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", IMG_GetError(), NULL);
            isRunning = false;
        }
    }
    else
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "SDL init failed", NULL);
    }
}

void Game::HandleEvents()
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

void Game::Update()
{}

void Game::Render()
{
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::Running()
{
    return isRunning;
}
