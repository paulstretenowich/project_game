#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "game.h"
#include "menu.h"
#include "texturemanager.h"

Menu* menu;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL Initialised!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Game Window created!" << std::endl;
        }
        else
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer)
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

        menu = new Menu;

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

//    SDL_Surface* tmpSurface = IMG_Load("../assets/fire_emblem_fates_inventory_screen.png");
//    // std::cout << tmpSurface << std::endl;
//    background_menuTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
//    SDL_FreeSurface(tmpSurface);
//    background_menuTex = TextureManager::LoadTexture("../assets/fire_emblem_fates_inventory_screen.png", renderer);

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
        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button)
            {
                case SDL_BUTTON_LEFT:
//                    SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was pressed!", window);
                    if ((event.motion.x > menu -> quit_buttonPosition().x)
                            && (event.motion.x < (menu -> quit_buttonPosition().x + menu -> quit_buttonPosition().w))
                            && (event.motion.y > menu -> quit_buttonPosition().y)
                            && (event.motion.y < (menu -> quit_buttonPosition().y + menu -> quit_buttonPosition().h)))
                    {
                        isRunning = false;
                        break;
                    }
                    break;
                case SDL_BUTTON_RIGHT:
//                    SDL_ShowSimpleMessageBox(0, "Mouse", "Right button was pressed!", window);
                    break;
                default:
//                    SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", window);
                    break;
            }
            break;
        case SDL_MOUSEMOTION:
        {
            int mouseX = event.motion.x;
            int mouseY = event.motion.y;

            std::stringstream ss;
            ss << "X: " << mouseX << " Y: " << mouseY;

            SDL_SetWindowTitle(window, ss.str().c_str());
            break;
        }
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
            }
            break;
//        default:
//            break;
    }
}

void Game::update()
{

//    manager.update();
//    std::cout << newPlayer.getComponent<PositionComponent>().x() << "," << newPlayer.getComponent<PositionComponent>().y() << std::endl;
//    cnt++;
//    std::cout << cnt << std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
//    this is where we would add stuff to render
//    SDL_RenderCopy(renderer, background_menuTex, NULL, NULL);
    menu -> Draw();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
    std::cout << "...Game Cleaned!" << std::endl;
}
