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
//#include "menu.h"
//#include "texturemanager.h"

//Menu* menu;

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

//    SDL_Surface* tmpSurface = IMG_Load("../assets/fire_emblem_fates_inventory_screen.png");
//    // std::cout << tmpSurface << std::endl;
//    background_menuTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
//    SDL_FreeSurface(tmpSurface);
//    background_menuTex = TextureManager::LoadTexture("../assets/fire_emblem_fates_inventory_screen.png", renderer);

}

/*
Our new functions, ChangeState() takes a pointer to a GameState as a parameter and then pushes that state onto the vector of pointers to GameStates, before that it uses the clean function to remove the old state from the stack.
*/
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

/*
Whereas ChangeState() pushes a state onto the stack and removes the previous state, PushState() pauses the previous state before pushing a new state onto the stack, this state can then be removed and the previous state resumed. Extrememly useful for pausing.
*/
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

/*
Remove and resume previous state.
*/
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

/*
These functions have now been changed so that they simply allow the current state to handle things, states.back() refers to the last element on the stack (the current state)
*/
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
//    Mix_CloseAudio();
//    TTF_Quit();
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}



//void Game::HandleEvents()  // take pointer out and remove function body
//{
//}

//void Game::Update() // remove any previous code from old tutorials
//{
//}

//void Game::Draw() // remove any previous code from old tutorials
//{
//    SDL_RenderPresent(m_pRenderer);
//}

//void Game::Clean() // remove any previous code from old tutorials
//{
//}



//void Game::Clean()
//{
//}

//                    switch (menu -> position)
//                    {
//                        case 1:
//                            std::cout << menu -> position << std::endl;
//                            void Game::handleEvents()
//                            {
//                                SDL_Event event;
//                                SDL_PollEvent(&event);
//                                switch (event.type)
//                                {
//                                    case SDL_QUIT:
//                                        isRunning = false;
//                                        break;
//                                    case SDL_MOUSEBUTTONDOWN:
//                                        switch (event.button.button)
//                                        {
//                                            case SDL_BUTTON_LEFT:
//                            //                    SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was pressed!", window);
//                                                if ((event.motion.x > menu -> quit_buttonPosition().x)
//                                                        && (event.motion.x < (menu -> quit_buttonPosition().x + menu -> quit_buttonPosition().w))
//                                                        && (event.motion.y > menu -> quit_buttonPosition().y)
//                                                        && (event.motion.y < (menu -> quit_buttonPosition().y + menu -> quit_buttonPosition().h)))
//                                                {
//                                                    isRunning = false;
//                                                    break;
//                                                }
//                            //                    break;
//                                            case SDL_BUTTON_RIGHT:
//                            //                    SDL_ShowSimpleMessageBox(0, "Mouse", "Right button was pressed!", window);
//                                                break;
//                                            default:
//                            //                    SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", window);
//                                                break;
//                                        }
//                                        break;
//                                    case SDL_MOUSEMOTION:
//                                    {
//                                        int mouseX = event.motion.x;
//                                        int mouseY = event.motion.y;

//                                        std::stringstream ss;
//                                        ss << "X: " << mouseX << " Y: " << mouseY;

//                                        SDL_SetWindowTitle(window, ss.str().c_str());
//                                        break;
//                                    }
//                                    case SDL_KEYUP:
//                                        switch (event.key.keysym.sym)
//                                        {
//                                            case SDLK_ESCAPE:
//                                                isRunning = false;
//                                                break;
//                                            case SDLK_UP:
//                            //                    std::cout << "up" << std::endl;
//                                                if (menu -> position > 0)
//                                                {
//                                                    menu -> position -= 1;
//                                                    menu -> Move()[menu -> position];
//                                                }
//                            //                    isRunning = false;
//                                                break;
//                                            case SDLK_DOWN:
//                            //                    std::cout << "down" << std::endl;
//                                                if (menu -> position < 2)
//                                                {
//                                                    menu -> position += 1;
//                                                    menu -> Move()[menu -> position];
//                                                }
//                            //                    isRunning = false;
//                                                break;
//                                            case SDLK_RETURN:
//                            menu -> DrawSubMenu();
//                            break;
//                        case 2:
//                            std::cout << menu -> position << std::endl;
//                            isRunning = false;
//                    }
//            }
//            break;
////        default:
////            break;
//    }
//}

//void Game::update()
//{

////    manager.update();
////    std::cout << newPlayer.getComponent<PositionComponent>().x() << "," << newPlayer.getComponent<PositionComponent>().y() << std::endl;
////    cnt++;
////    std::cout << cnt << std::endl;
//}

//void Game::render()
//{
//    SDL_RenderClear(renderer);
////    this is where we would add stuff to render
////    SDL_RenderCopy(renderer, background_menuTex, NULL, NULL);
//    menu -> DrawMenu();
////    menu -> DrawSubMenu();
//    SDL_RenderPresent(renderer);
//}

//void Game::clean()
//{
//    SDL_DestroyWindow(window);
//    SDL_DestroyRenderer(renderer);
//    Mix_CloseAudio();
//    TTF_Quit();
//    SDL_Quit();
//    std::cout << "...Game Cleaned!" << std::endl;
//}
