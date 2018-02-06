#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "game.h"
#include "texturemanager.h"
#include "endstate.h"
#include "menustate.h"

EndState EndState::m_EndState;

void EndState::Init()
{
    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/end_zelda.ogg");
    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background = TextureManager::LoadTextureImg("../images/background_end.jpeg");

    background_text1 = TextureManager::LoadTextureFont("../fonts/Assassin.ttf", 100, 255, 255, 255, "The End");
    background_text2 = TextureManager::LoadTextureFont("../fonts/almendra/Almendra-Regular.ttf", 20, 255, 255, 255, "Appuyer sur <ESPACE> pour revenir au menu ;)");
    printf("EndState Init Successful\n");
}

void EndState::Clean()
{
    Mix_HaltMusic();
    Mix_CloseAudio();
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(background_text1);
    SDL_DestroyTexture(background_text2);
    printf("EndState Clean Successful\n");
}

void EndState::Pause()
{
    printf("EndState Paused\n");
}

void EndState::Resume()
{
    printf("EndState Resumed\n");
}

void EndState::HandleEvents(Game* game) //put our exit function back in business we can now quit with cross in corner.
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                game->Quit();
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        game->Quit();
                        break;

                    case SDLK_SPACE:
                    game->ChangeState(MenuState::Instance());
                    break;
//                    case SDLK_UP:
//            //                    std::cout << "up" << std::endl;
//                        if (EndState::position > 0)
//                        {
//                            EndState::position -= 1;
//                            EndState::MoveSelector()[EndState::position];
//                        }
//            //                    isRunning = false;
//                        break;
//                    case SDLK_DOWN:
//            //                    std::cout << "down" << std::endl;
//                        if (EndState::position < 2)
//                        {
//                            EndState::position += 1;
//                            EndState::MoveSelector()[EndState::position];
//                        }
//            //                    isRunning = false;
//                        break;
//                    case SDLK_RETURN:
//                        switch (EndState::position)
//                        {
//                            case 0:
//                                std::cout << "play" << std::endl;
//                                break;

//                            case 1:
//                                game->PushState(OptionState::Instance());
//                                break;
//                            case 2:
//                                game->Quit();
//                                break;
//                        }
                }
//            case SDL_KEYDOWN:
//                switch(event.key.keysym.sym)
//                {
//                    case SDLK_SPACE:
//                        game->PushState(OptionState::Instance());
//                        break;
//                }
        }
    }
}

void EndState::Update(Game* game)
{
}

void EndState::Draw(Game* game)
{
    SDL_RenderClear(game->m_pRenderer);

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    int texW = 0;
    int texH = 0;

    TextureManager::DrawBackground(game->m_pRenderer, background);

    SDL_QueryTexture(background_text1, NULL, NULL, &texW, &texH);
    background_text_src1.x = background_text_src1.y = 0;
    background_text_dest1.w = texW;//400;
    background_text_dest1.h = texH;//120;
    background_text_dest1.x = size.x*2/3;
    background_text_dest1.y = size.y*1/3;
    TextureManager::Draw(game->m_pRenderer, background_text1, background_text_src1, background_text_dest1);

    SDL_QueryTexture(background_text2, NULL, NULL, &texW, &texH);
    background_text_src2.x = background_text_src2.y = 0;
    background_text_dest2.w = texW;//400;
    background_text_dest2.h = texH;//120;
    background_text_dest2.x = size.x*2/3;
    background_text_dest2.y = size.y*19/20;
    TextureManager::Draw(game->m_pRenderer, background_text2, background_text_src2, background_text_dest2);

    SDL_RenderPresent(game->m_pRenderer);
}
