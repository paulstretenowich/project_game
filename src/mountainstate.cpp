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
#include "mountainstate.h"
#include "deadstate.h"
#include "introstate.h"
#include "foreststate.h"
#include "seatownstate.h"
#include "global.h"

MountainState MountainState::m_MountainState;

void MountainState::Init()
{
//    int life = IntroState::life;

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/mountain_zelda.ogg");
    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background_mountain = TextureManager::LoadTextureImg("../images/background_story/001_Brave.png");
    background_volcano = TextureManager::LoadTextureImg("../images/background_story/003_Volcano.png");
    background_forest = TextureManager::LoadTextureImg("../images/background_story/001_BraveForest.png");

    background_text = TextureManager::LoadTextureImg("../images/background_story/background_text.png");

    aragorn = TextureManager::LoadTextureImg("../images/characters/aragorn/Face.png");
    aragorn_fight = TextureManager::LoadTextureImg("../images/characters/aragorn/BtlFace_D.png");

    next = TextureManager::LoadTextureFontStoryNextPage();
    choice = TextureManager::LoadTextureFontStoryChoice();

    text1 = TextureManager::LoadTextureFontStory("Vous arrivez au pied de la montagne. Vous ressentez des secousses et vous voyez des chevaux en fuite. Que faites vous?\n"
                                                 "1. Vous continuez en direction de la montagne.\n"
                                                 "2. Vous retournez vers la forêt.\n"
                                                 "3. Vous allez vers la mer.",
                                                 size);
    text2 = TextureManager::LoadTextureFontStory("Vous arrivez en haut de la montagne. Le volcan, supposé éteint, entre dans une violente éruption.\n"
                                                 "Les secousses que vous aviez senti au pied de la montagne étaient des signes précurseurs.\n"
                                                 "Vous êtes grièvement blessé",
                                                 size);
    text3 = TextureManager::LoadTextureFontStory("Vous arrivez à descendre de la montagne. Vers où fuyez vous?.\n"
                                                 "1. Vous retournez vers la forêt.\n"
                                                 "2. Vous allez vers la mer.",
                                                 size);
    text4 = TextureManager::LoadTextureFontStory("Malheureusement vous mourrez de vos blessures accumulées durant votre aventure.", size);
    text5 = TextureManager::LoadTextureFontStory("Sur votre chemin vers la forêt vous trouvez un champignon blanc à pois rouges.\n"
                                                 "1. Vous le mangez (au point où vous en êtes c'est pas un petit champignon qui va vous tuer).\n"
                                                 "2. Vous continuez votre route (maman disait de se méfier des champignons)", size);
    text6 = TextureManager::LoadTextureFontStory("Vous vous sentez revigoré. Vous pensez même avoir grandi de quelques centimètres.", size);
    text7 = TextureManager::LoadTextureFontStory("Vous tombez malade. Maman vous avait prévenue.", size);

    text_selector = 0;

//    std::cout << Global::CheckLife() << std::endl;

    printf("MountainState Init Successful\n");
}

std::vector<SDL_Texture*> MountainState::ChangeText()
{
    std::vector<SDL_Texture*> vecOfText;
    vecOfText.push_back(text1);
    vecOfText.push_back(text2);
    vecOfText.push_back(text3);
    vecOfText.push_back(text4);
    vecOfText.push_back(text5);
    vecOfText.push_back(text6);
    vecOfText.push_back(text7);
    return vecOfText;
}


void MountainState::Clean()
{
    Mix_HaltMusic();
    Mix_CloseAudio();
    SDL_DestroyTexture(next);
    SDL_DestroyTexture(choice);
    SDL_DestroyTexture(background_mountain);
    SDL_DestroyTexture(background_volcano);
    SDL_DestroyTexture(background_forest);
    SDL_DestroyTexture(aragorn);
    SDL_DestroyTexture(aragorn_fight);
    SDL_DestroyTexture(background_text);
    SDL_DestroyTexture(text1);
    SDL_DestroyTexture(text2);
    SDL_DestroyTexture(text3);
    SDL_DestroyTexture(text4);
    SDL_DestroyTexture(text5);
    SDL_DestroyTexture(text6);
    SDL_DestroyTexture(text7);
    printf("MountainState Clean Successful\n");
}

void MountainState::Pause()
{
    printf("MountainState Paused\n");
}

void MountainState::Resume()
{
    printf("MountainState Resumed\n");
}

void MountainState::HandleEvents(Game* game) //put our exit function back in business we can now quit with cross in corner.
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
                        switch (MountainState::text_selector)
                        {
                            case 1:
                                Global::ModifyLife(-(rand() % (5 - 3 + 1) + 4));
                                if (Global::CheckLife() <= 0)
                                {
                                    MountainState::text_selector = 3;
                                }
                                else
                                {
                                    MountainState::text_selector = 2;
                                }
                                break;

                            case 3:
                                game->ChangeState(DeadState::Instance());
                                break;

                            case 5:
                                Global::ModifyLife((rand() % (4 - 0 + 1) + 0));
                                game->ChangeState(ForestState::Instance());
                                break;
                            case 6:
                                Global::ModifyLife(-1);
                                if (Global::CheckLife() <= 0)
                                {
                                    MountainState::text_selector = 3;
                                }
                                else
                                {
                                    game->ChangeState(ForestState::Instance());
                                }
                                break;
                        }
                        break;

                    case SDLK_1:
                        switch (MountainState::text_selector)
                        {
                            case 0:
                                MountainState::text_selector = 1;
                                break;

                            case 2:
                                MountainState::text_selector = 4;
                                break;

                            case 4:
                                if ((rand() % (9 - 0 + 1) + 0) > 1)
                                {
                                    MountainState::text_selector = 5;
                                }
                                else
                                {
                                    MountainState::text_selector = 6;
                                }
                                break;
                        }
                        break;

                    case SDLK_2:
                        switch (MountainState::text_selector)
                        {
                            case 0:
                                game->ChangeState(ForestState::Instance());
                                break;

                            case 2:
                                game->ChangeState(SeaTownState::Instance());
//                                std::cout << "sea state" << std::endl;
                                break;

                            case 4:
                                game->ChangeState(ForestState::Instance());
                                break;
                        }
                        break;

                    case SDLK_3:
                        switch (MountainState::text_selector)
                        {
                            case 0:
                                game->ChangeState(SeaTownState::Instance());
//                                std::cout << "sea state" << std::endl;
                            break;
                        }
                        break;
                }
        }
    }
}

void MountainState::Update(Game* game)
{
}

void MountainState::Draw(Game* game)
{
    SDL_RenderClear(game->m_pRenderer);

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    if (MountainState::text_selector == 0 || MountainState::text_selector == 2)
    {
        background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background_mountain, background_src, background_dest, size);
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*8/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
    }
    else if (MountainState::text_selector == 1)
    {
        background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background_volcano, background_src, background_dest, size);
        aragorn_fight_src.x = aragorn_fight_src.y = 0;
        aragorn_fight_dest.w = int(size.x*2/5 + 0.5);
        aragorn_fight_dest.h = int(aragorn_fight_dest.w/1.2 + 0.5);
        aragorn_fight_dest.x = background_dest.w*8/10 - aragorn_fight_dest.h/2;
        aragorn_fight_dest.y = background_dest.h*2/3 - aragorn_fight_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn_fight, aragorn_fight_src, aragorn_fight_dest);
    }
    else if (MountainState::text_selector == 3)
    {
        background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background_mountain, background_src, background_dest, size);
        aragorn_fight_src.x = aragorn_fight_src.y = 0;
        aragorn_fight_dest.w = int(size.x*2/5 + 0.5);
        aragorn_fight_dest.h = int(aragorn_fight_dest.w/1.2 + 0.5);
        aragorn_fight_dest.x = background_dest.w*8/10 - aragorn_fight_dest.h/2;
        aragorn_fight_dest.y = background_dest.h*2/3 - aragorn_fight_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn_fight, aragorn_fight_src, aragorn_fight_dest);
    }
    else if (MountainState::text_selector == 4 || MountainState::text_selector == 5 || MountainState::text_selector == 6)
    {
        background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background_forest, background_src, background_dest, size);
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*8/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
    }

    background_text_dest = TextureManager::DrawBackgroundTextStory(game->m_pRenderer, background_text, background_text_src, background_text_dest, size, background_dest);

    TextureManager::DrawFontStory(game->m_pRenderer, ChangeText()[MountainState::text_selector], text_dest, background_text_dest);

    if (MountainState::text_selector == 0 || MountainState::text_selector == 2 || MountainState::text_selector == 4)
    {
        TextureManager::DrawFontStoryChoice(game->m_pRenderer, choice, next_dest, background_text_dest);
    }
    else
    {
        TextureManager::DrawFontStoryNextPage(game->m_pRenderer, next, next_dest, background_text_dest);
    }

    SDL_RenderPresent(game->m_pRenderer);
}
