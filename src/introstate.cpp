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
#include "introstate.h"

IntroState IntroState::m_IntroState;

void IntroState::Init()
{
    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/intro_zelda_ocarina.ogg");
    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background = TextureManager::LoadTextureImg("../images/background_story/002_PlainForest.png");

    background_text = TextureManager::LoadTextureImg("../images/background_story/background_text.png");

    aragorn = TextureManager::LoadTextureImg("../images/characters/Raven/Face.png");

    text1 = TextureManager::LoadTextureFontStory("Il était une fois...\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n\n\n\n\nAppuyer sur <SPACE> pour continuer...", size);
    text2 = TextureManager::LoadTextureFontStory("Pwet!!!!!!!!!!!!!!", size);

    text_selector = 0;

    printf("IntroState Init Successful\n");
}

std::vector<SDL_Texture*> IntroState::ChangeText()
{
    std::vector<SDL_Texture*> vecOfText;
    vecOfText.push_back(text1);
    vecOfText.push_back(text2);
    return vecOfText;
}


void IntroState::Clean()
{
    Mix_HaltMusic();
    Mix_CloseAudio();
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(aragorn);
    SDL_DestroyTexture(background_text);
    SDL_DestroyTexture(text1);
    SDL_DestroyTexture(text2);
    printf("IntroState Clean Successful\n");
}

void IntroState::Pause()
{
    printf("IntroState Paused\n");
}

void IntroState::Resume()
{
    printf("IntroState Resumed\n");
}

void IntroState::HandleEvents(Game* game) //put our exit function back in business we can now quit with cross in corner.
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
                    if (IntroState::text_selector < IntroState::ChangeText().size()-1)
                    {
                        IntroState::text_selector += 1;
                    }
                    break;
//                    case SDLK_UP:
//            //                    std::cout << "up" << std::endl;
//                        if (IntroState::position > 0)
//                        {
//                            IntroState::position -= 1;
//                            IntroState::MoveSelector()[IntroState::position];
//                        }
//            //                    isRunning = false;
//                        break;
//                    case SDLK_DOWN:
//            //                    std::cout << "down" << std::endl;
//                        if (IntroState::position < 2)
//                        {
//                            IntroState::position += 1;
//                            IntroState::MoveSelector()[IntroState::position];
//                        }
//            //                    isRunning = false;
//                        break;
//                    case SDLK_RETURN:
//                        switch (IntroState::position)
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

void IntroState::Update(Game* game)
{
}

void IntroState::Draw(Game* game)
{
    SDL_RenderClear(game->m_pRenderer);

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    int texW = 0;
    int texH = 0;

    background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background, background_src, background_dest, size);

    aragorn_src.x = aragorn_src.y = 0;
    aragorn_dest.w = size.x*2/5;
    aragorn_dest.h = aragorn_dest.w/1.2;
    aragorn_dest.x = background_dest.w*2/3 - aragorn_dest.h/2;
    aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
    TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);

    background_text_dest = TextureManager::DrawBackgroundTextStory(game->m_pRenderer, background_text, background_text_src, background_text_dest, size, background_dest);

    TextureManager::DrawFontStory(game->m_pRenderer, ChangeText()[IntroState::text_selector], text1_dest, background_text_dest);

    SDL_RenderPresent(game->m_pRenderer);
}
