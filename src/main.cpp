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
