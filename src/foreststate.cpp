#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <sstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "game.h"
#include "texturemanager.h"
#include "foreststate.h"
#include "deadstate.h"
#include "introstate.h"
#include "global.h"

ForestState ForestState::m_ForestState;

void ForestState::Init()
{
//    int life = IntroState::life;

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/forest_zelda.ogg");
    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background = TextureManager::LoadTextureImg("../images/background_story/002_PlainForest.png");

    background_text = TextureManager::LoadTextureImg("../images/background_story/background_text.png");

    aragorn = TextureManager::LoadTextureImg("../images/characters/aragorn/Face.png");
    aragorn_fight_injury = TextureManager::LoadTextureImg("../images/characters/aragorn/BtlFace_D.png");
    aragorn_fight = TextureManager::LoadTextureImg("../images/characters/aragorn/BtlFace_flip.png");

    guard = TextureManager::LoadTextureImg("../images/characters/guard/BtlFace.png");

    next = TextureManager::LoadTextureFontStoryNextPage();
    choice = TextureManager::LoadTextureFontStoryChoice();

    text1 = TextureManager::LoadTextureFontStory("En vous enfonçant dans la forêt vous tombez nez à nez avec l'un de vos ennemis, un garde du comte Geralt Lannister.\n"
                                                 "Que faites vous ?\n"
                                                 "1. Vous Fuyez.\n"
                                                 "2. Vous l'attaquez.\n"
                                                 "3. Vous vous mettez en position de combat.",
                                                 size);
    text2 = TextureManager::LoadTextureFontStory("Le garde alerte le reste de la patrouille. Ils vous rattrapent et vous torture à mort.",
                                                 size);
    text3 = TextureManager::LoadTextureFontStory("Vous arrivez à le maîtriser assez rapidement mais il vous blesse légèrement pendant le combat.\n"
                                                 "Vous vous dirigez avec hâte vers la mer pour éviter d'alerter le reste de la garde.",
                                                 size);
    text4 = TextureManager::LoadTextureFontStory("Il vous attaque mais ayant anticipé l'affrontement, vous êtes capable de le maîtriser sans subir de représaille.\n"
                                                 "Vous vous dirigez dans la direction opposée du château du comte, vers la mer.",
                                                 size);
    text5 = TextureManager::LoadTextureFontStory("Malheureusement vous mourrez de vos blessures accumulées durant votre aventure.", size);
    text_selector = 0;

//    std::cout << Global::CheckLife() << std::endl;

    printf("ForestState Init Successful\n");
}

std::vector<SDL_Texture*> ForestState::ChangeText()
{
    std::vector<SDL_Texture*> vecOfText;
    vecOfText.push_back(text1);
    vecOfText.push_back(text2);
    vecOfText.push_back(text3);
    vecOfText.push_back(text4);
    vecOfText.push_back(text5);
    return vecOfText;
}


void ForestState::Clean()
{
    Mix_HaltMusic();
    Mix_CloseAudio();
    SDL_DestroyTexture(next);
    SDL_DestroyTexture(choice);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(aragorn);
    SDL_DestroyTexture(aragorn_fight);
    SDL_DestroyTexture(aragorn_fight_injury);
    SDL_DestroyTexture(guard);
    SDL_DestroyTexture(background_text);
    SDL_DestroyTexture(text1);
    SDL_DestroyTexture(text2);
    SDL_DestroyTexture(text3);
    SDL_DestroyTexture(text4);
    SDL_DestroyTexture(text5);
    printf("ForestState Clean Successful\n");
}

void ForestState::Pause()
{
    printf("ForestState Paused\n");
}

void ForestState::Resume()
{
    printf("ForestState Resumed\n");
}

void ForestState::HandleEvents(Game* game) //put our exit function back in business we can now quit with cross in corner.
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
                        switch (ForestState::text_selector)
                        {
                            case 1:
                                game->ChangeState(DeadState::Instance());
                                break;

                            case 2:
                                Global::ModifyLife(-(rand() % (3 - 1 + 1) + 1));
                                if (Global::CheckLife() <= 0)
                                {
                                    ForestState::text_selector = 4;
                                }
                                else
                                {
                                    std::cout << "sea state" << std::endl;
                                }
                                break;

                            case 3:
                                std::cout << "sea state" << std::endl;
                                break;

                            case 4:
                                game->ChangeState(DeadState::Instance());
                                break;
                        }
                        break;

                    case SDLK_1:
                        switch (ForestState::text_selector)
                        {
                            case 0:
                                ForestState::text_selector = 1;
                                break;
                        }
                        break;

                    case SDLK_2:
                        switch (ForestState::text_selector)
                        {
                            case 0:
                                ForestState::text_selector = 2;
                                break;
                        }
                        break;

                    case SDLK_3:
                        switch (ForestState::text_selector)
                        {
                            case 0:
                                ForestState::text_selector = 3;
                            break;
                        }
                        break;
                }
        }
    }
}

void ForestState::Update(Game* game)
{
}

void ForestState::Draw(Game* game)
{
    SDL_RenderClear(game->m_pRenderer);

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background, background_src, background_dest, size);

    if (ForestState::text_selector == 1 || ForestState::text_selector == 2)
    {
        guard_src.x = guard_src.y = 0;
        guard_dest.w = int(size.x*2/5 + 0.5);
        guard_dest.h = int(guard_dest.w/1.2 + 0.5);
        guard_dest.x = background_dest.w*4/10 - guard_dest.h/2;
        guard_dest.y = background_dest.h*2/3 - guard_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, guard, guard_src, guard_dest);
        aragorn_fight_injury_src.x = aragorn_fight_injury_src.y = 0;
        aragorn_fight_injury_dest.w = int(size.x*2/5 + 0.5);
        aragorn_fight_injury_dest.h = int(aragorn_fight_injury_dest.w/1.2 + 0.5);
        aragorn_fight_injury_dest.x = background_dest.w*8/10 - aragorn_fight_injury_dest.h/2;
        aragorn_fight_injury_dest.y = background_dest.h*2/3 - aragorn_fight_injury_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn_fight_injury, aragorn_fight_injury_src, aragorn_fight_injury_dest);
    }
    else if (ForestState::text_selector == 3)
    {
        guard_src.x = guard_src.y = 0;
        guard_dest.w = int(size.x*2/5 + 0.5);
        guard_dest.h = int(guard_dest.w/1.2 + 0.5);
        guard_dest.x = background_dest.w*3/10 - guard_dest.h/2;
        guard_dest.y = background_dest.h*2/3 - guard_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, guard, guard_src, guard_dest);
        aragorn_fight_src.x = aragorn_fight_src.y = 0;
        aragorn_fight_dest.w = int(size.x*2/5 + 0.5);
        aragorn_fight_dest.h = int(aragorn_fight_dest.w/1.2 + 0.5);
        aragorn_fight_dest.x = background_dest.w*7/10 - aragorn_fight_dest.h/2;
        aragorn_fight_dest.y = background_dest.h*2/3 - aragorn_fight_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn_fight, aragorn_fight_src, aragorn_fight_dest);
    }
    else
    {
        guard_src.x = guard_src.y = 0;
        guard_dest.w = int(size.x*2/5 + 0.5);
        guard_dest.h = int(guard_dest.w/1.2 + 0.5);
        guard_dest.x = background_dest.w*4/10 - guard_dest.h/2;
        guard_dest.y = background_dest.h*2/3 - guard_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, guard, guard_src, guard_dest);
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*8/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
    }

    background_text_dest = TextureManager::DrawBackgroundTextStory(game->m_pRenderer, background_text, background_text_src, background_text_dest, size, background_dest);

    TextureManager::DrawFontStory(game->m_pRenderer, ChangeText()[ForestState::text_selector], text_dest, background_text_dest);

    if (ForestState::text_selector == 0 || ForestState::text_selector == 4 || ForestState::text_selector == 5)
    {
        TextureManager::DrawFontStoryChoice(game->m_pRenderer, choice, next_dest, background_text_dest);
    }
    else
    {
        TextureManager::DrawFontStoryNextPage(game->m_pRenderer, next, next_dest, background_text_dest);
    }

    SDL_RenderPresent(game->m_pRenderer);
}
