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
#include "stage1state.h"
#include "deadstate.h"
#include "introstate.h"
#include "foreststate.h"
#include "mountainstate.h"
#include "seatownstate.h"
#include "global.h"

Stage1State Stage1State::m_Stage1State;

void Stage1State::Init()
{
//    int life = IntroState::life;

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/stage1.ogg");
    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background = TextureManager::LoadTextureImg("../images/background_story/002_PlainForest.png");

    background_text = TextureManager::LoadTextureImg("../images/background_story/background_text.png");

    aragorn = TextureManager::LoadTextureImg("../images/characters/aragorn/Face.png");
    aragorn_fight = TextureManager::LoadTextureImg("../images/characters/aragorn/BtlFace_D.png");

    ciri = TextureManager::LoadTextureImg("../images/characters/ciri/Face.png");
    ciri_fight = TextureManager::LoadTextureImg("../images/characters/ciri/BtlFace_C.png");

    next = TextureManager::LoadTextureFontStoryNextPage();
    choice = TextureManager::LoadTextureFontStoryChoice();

    text1 = TextureManager::LoadTextureFontStory("Vous avez bravement échappé aux bandits. Vous décidez donc de suivre le chemin qui s'offre à vous, en cette journée ensoleillé. Vous voyez une personne au loin en train de dormir sous l'ombre d'un arbre. Que faites vous ?\n"
                                                 "1. Vous l'ignorez complètement.\n"
                                                 "2. Vous décidez de lui dérober ses affaires.\n"
                                                 "3. Vous la réveillez doucement afin de lancer la discussion.\n"
                                                 "4. Vous lui ôtez la vie et vous récupérez tout ce qui peut être utile.",
                                                 size);
    text2 = TextureManager::LoadTextureFontStory("Vous vous faites prendra la main dans le sac. Elle vous met en fuite et vous blesse.",
                                                 size);
    text3 = TextureManager::LoadTextureFontStory("Il se trouve que cette charmante demoiselle, Ciri, est une aventurière tout comme vous.\n"
                                                 "En manque de compagnie, vous lui proposez de faire route avec elle jusqu'à la nuit pour partager un repas et plus si affinité.\n"
                                                 "Elle accepte volontiers et vous passez un excellent moment ensemble.\n"
                                                 "Après avoir passé une magnifique nuit, vous vous réveillez seul.",
                                                 size);
    text4 = TextureManager::LoadTextureFontStory("Après avoir rendu son sommeil définitif, vous remarquez que c'était une jeune aventurière. Malgré une fouille très appronfondie, vous ne trouvez rien d'interessant.",
                                                 size);
    text5 = TextureManager::LoadTextureFontStory("Après un certain temps de marche vous arrivez à une intersection. Vous vous rappelez que Ciri disait que la région montagneuse montrait des signes d'activités.\n"
                                                 "Trois choix s'offrent à vous :\n"
                                                 "1. Vous décidez de continuer dans la forêt.\n"
                                                 "2. Vous vous dirigez vers le bord de mer.\n"
                                                 "3. Vous préferez les régions montagneuses.",
                                                 size);
    text6 = TextureManager::LoadTextureFontStory("Après un certain temps de marche vous arrivez à une intersection.\n"
                                                 "Trois choix s'offrent à vous :\n"
                                                 "1. Vous décidez de continuer dans la forêt.\n"
                                                 "2. Vous vous dirigez vers le bord de mer.\n"
                                                 "3. Vous préferez les régions montagneuses.",
                                                 size);
    text7 = TextureManager::LoadTextureFontStory("Malheureusement vous mourrez de vos blessures accumulées durant votre aventure.", size);

    text_selector = 0;

//    std::cout << Global::CheckLife() << std::endl;

    printf("Stage1State Init Successful\n");
}

std::vector<SDL_Texture*> Stage1State::ChangeText()
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


void Stage1State::Clean()
{
    Mix_HaltMusic();
    Mix_CloseAudio();
    SDL_DestroyTexture(next);
    SDL_DestroyTexture(choice);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(aragorn);
    SDL_DestroyTexture(aragorn_fight);
    SDL_DestroyTexture(ciri);
    SDL_DestroyTexture(ciri_fight);
    SDL_DestroyTexture(background_text);
    SDL_DestroyTexture(text1);
    SDL_DestroyTexture(text2);
    SDL_DestroyTexture(text3);
    SDL_DestroyTexture(text4);
    SDL_DestroyTexture(text5);
    SDL_DestroyTexture(text6);
    SDL_DestroyTexture(text7);
    printf("Stage1State Clean Successful\n");
}

void Stage1State::Pause()
{
    printf("Stage1State Paused\n");
}

void Stage1State::Resume()
{
    printf("Stage1State Resumed\n");
}

void Stage1State::HandleEvents(Game* game) //put our exit function back in business we can now quit with cross in corner.
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
                        switch (Stage1State::text_selector)
                        {
                            case 1:
                                Global::ModifyCiri(-1);
                                Global::ModifyLife(-(rand() % (3 - 1 + 1) + 1));
                                if (Global::CheckLife() <= 0)
                                {
                                    Stage1State::text_selector = 6;
                                }
                                else
                                {
                                    Stage1State::text_selector = 5;
                                }
                                break;

                            case 2:
                                Global::ModifyCiri(1);
                                Stage1State::text_selector = 4;
                                break;

                            case 3:
                                Global::ModifyCiri(-2);
                                Stage1State::text_selector = 5;
                                break;

                            case 6:
                                game->ChangeState(DeadState::Instance());
                                break;
                        }
                        break;

                    case SDLK_1:
                        switch (Stage1State::text_selector)
                        {
                            case 0:
                                Stage1State::text_selector = 5;
                                break;
//
                            case 4:
//                                std::cout << "forest state" << std::endl;
                                game->ChangeState(ForestState::Instance());
                                break;

                            case 5:
//                                std::cout << "forest state" << std::endl;
                                game->ChangeState(ForestState::Instance());
                                break;
                        }
                        break;

                    case SDLK_2:
                        switch (Stage1State::text_selector)
                        {
                            case 0:
                                Stage1State::text_selector += 1;
                                break;

                            case 4:
//                                std::cout << "sea state" << std::endl;
                                    game->ChangeState(SeaTownState::Instance());
                                break;

                            case 5:
//                                std::cout << "sea state" << std::endl;
                                    game->ChangeState(SeaTownState::Instance());
                                break;
                        }
                        break;

                case SDLK_3:
                    switch (Stage1State::text_selector)
                    {
                        case 0:
                            Stage1State::text_selector = 2;
                            break;

                        case 4:
//                            std::cout << "mountain state" << std::endl;
                            game->ChangeState(MountainState::Instance());
                            break;

                        case 5:
//                            std::cout << "mountain state" << std::endl;
                            game->ChangeState(MountainState::Instance());
                            break;
                    }
                    break;

                case SDLK_4:
                    switch (Stage1State::text_selector)
                    {
                        case 0:
                            Stage1State::text_selector = 3;
                            break;
                    }
                    break;
                }
        }
    }
}

void Stage1State::Update(Game* game)
{
}

void Stage1State::Draw(Game* game)
{
    SDL_RenderClear(game->m_pRenderer);

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background, background_src, background_dest, size);

    if (Stage1State::text_selector == 2)
    {
        ciri_src.x = ciri_src.y = 0;
        ciri_dest.w = int(size.x*2/5 + 0.5);
        ciri_dest.h = int(ciri_dest.w/1.2 + 0.5);
        ciri_dest.x = background_dest.w*8/10 - ciri_dest.h/2;
        ciri_dest.y = background_dest.h*2/3 - ciri_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, ciri, ciri_src, ciri_dest);
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*5/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
    }
    else if (Stage1State::text_selector == 1)
    {
        ciri_fight_src.x = ciri_fight_src.y = 0;
        ciri_fight_dest.w = int(size.x*2/5 + 0.5);
        ciri_fight_dest.h = int(ciri_fight_dest.w/1.2 + 0.5);
        ciri_fight_dest.x = background_dest.w*3/10 - ciri_fight_dest.h/2;
        ciri_fight_dest.y = background_dest.h*2/3 - ciri_fight_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, ciri_fight, ciri_fight_src, ciri_fight_dest);
        aragorn_fight_src.x = aragorn_fight_src.y = 0;
        aragorn_fight_dest.w = int(size.x*2/5 + 0.5);
        aragorn_fight_dest.h = int(aragorn_fight_dest.w/1.2 + 0.5);
        aragorn_fight_dest.x = background_dest.w*8/10 - aragorn_fight_dest.h/2;
        aragorn_fight_dest.y = background_dest.h*2/3 - aragorn_fight_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn_fight, aragorn_fight_src, aragorn_fight_dest);
    }
    else
    {
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*5/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
    }

    background_text_dest = TextureManager::DrawBackgroundTextStory(game->m_pRenderer, background_text, background_text_src, background_text_dest, size, background_dest);

    TextureManager::DrawFontStory(game->m_pRenderer, ChangeText()[Stage1State::text_selector], text_dest, background_text_dest);

    if (Stage1State::text_selector == 0 || Stage1State::text_selector == 4 || Stage1State::text_selector == 5)
    {
        TextureManager::DrawFontStoryChoice(game->m_pRenderer, choice, next_dest, background_text_dest);
    }
    else
    {
        TextureManager::DrawFontStoryNextPage(game->m_pRenderer, next, next_dest, background_text_dest);
    }

    SDL_RenderPresent(game->m_pRenderer);
}
