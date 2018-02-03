#include <iostream>
#include <cstdlib>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "game.h"
#include "menustate.h"
#include "texturemanager.h"

Game *game = nullptr;

int main(int argc, char* argv[])
{
    game = new Game();

    game->Init("StateManager", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, false);

    game->ChangeState(MenuState::Instance());

    while(game->Running())
    {

        game->HandleEvents();
        game->Update();
        game->Draw();
    }

    // cleanup the engine
    game->Clean();

    return 0;
}



//#include <iostream>
//#include <cstdlib>
//#include <vector>

//#include <SDL2/SDL.h>
//#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_mixer.h>

//#include "game.h"
//#include "menu.h"
//#include "texturemanager.h"

//Game *game = nullptr;
////Menu *menu = nullptr;

//int main(int argc, const char *argv[])
//{
//    const int FPS = 60;
//    const int frameDelay = 1000 / FPS;

//    Uint32 frameStart;
//    int frameTime;

//    game = new Game();
//    game -> init("BirchEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, false);

////    menu = new Menu();
////    menu -> init("../images/menu/menu_background_new_002.png");

//    while (game -> Running())
//    {
//        frameStart = SDL_GetTicks();

//        game -> HandleEvents();
//        game -> Update();
////        game -> render();

//        frameTime = SDL_GetTicks() - frameStart;

//        if (frameDelay > frameTime)
//        {
//            SDL_Delay(frameDelay - frameTime);
////            std::cout << frameDelay - frameTime << std::endl;
//        }
//    }

//    game -> Clean();
////    Mix_FreeMusic(background_menu_music);

////    SDL_Init(SDL_INIT_EVERYTHING);
////    SDL_Window *window = SDL_CreateWindow("ttle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
////    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

////    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

////    SDL_RenderClear(renderer);

////    SDL_RenderPresent(renderer);

////    SDL_Delay(3000);

//    return 0;
//}
