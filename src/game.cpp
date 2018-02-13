#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "game.h"
#include "gamestate.h"
//#define nullptr NULL

SDL_Renderer* Game::m_pRenderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::Init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL Initialised!" << std::endl;

        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_pWindow)
        {
            std::cout << "Game Window created!" << std::endl;
        }
        else
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
//        SDL_SetWindowResizable(m_pWindow, SDL_TRUE);

        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
        if (m_pRenderer)
        {
//            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        if(TTF_Init()==-1)
        {
            printf("TTF_Init: %s\n", TTF_GetError());
//            exit(2);
        }

        if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) < 0)
        {
            printf("Error initializing SDL_mixer: %s\n", Mix_GetError());
//            exit(1);
        }

        m_bFullscreen = fullscreen;

        m_bRunning = true;

//        menu = new Menu;
//        isRunning = true;
    }
    else
    {
        m_bRunning = false;
//        isRunning = false;
    }
}

void Game::ChangeState(GameState* state)
{
    // cleanup the current state
    if ( !states.empty() )
    {
        states.back()->Clean();
        states.pop_back();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init();
}

void Game::PushState(GameState* state)
{
    // pause current state
    if ( !states.empty() )
    {
        states.back()->Pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init();
}

void Game::PopState()
{
    // cleanup the current state
    if ( !states.empty() )
    {
        states.back()->Clean();
        states.pop_back();
    }

    // resume previous state
    if ( !states.empty() )
    {
        states.back()->Resume();
    }
}

void Game::HandleEvents()
{

    // let the state handle events
    states.back()->HandleEvents(this);
//    std::cout << "pwet" << std::endl;
}


void Game::Update()
{

    // let the state update the game
    states.back()->Update(this);
}

void Game::Draw()
{
    // let the state draw the screen
    states.back()->Draw(this);
    //SDL_Flip(m_pScreen);
}

void Game::Clean()
{
    while ( !states.empty() )
    {
        states.back()->Clean();
        states.pop_back();
    }

    // shutdown SDL
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}
