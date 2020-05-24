#include "Game.h"

Game::Game()
{}

Game::~Game()
{}

void Game::Init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(!window)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Window init failed", NULL);
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(!renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Renderer init failed", NULL);
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
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
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::Running()
{
    return isRunning;
}
