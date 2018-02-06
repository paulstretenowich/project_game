#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <sstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "game.h"
#include "texturemanager.h"
#include "introstate.h"
#include "deadstate.h"
#include "endstate.h"
#include "stage1state.h"
#include "foreststate.h"
#include "mountainstate.h"
#include "global.h"

IntroState IntroState::m_IntroState;
int Global::life;
int Global::ciri = 0;
int Global::money = 0;

//int life;

void IntroState::Init()
{
    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/intro_zelda_ocarina.ogg");
    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background = TextureManager::LoadTextureImg("../images/background_story/002_PlainForest.png");

    background_text = TextureManager::LoadTextureImg("../images/background_story/background_text.png");

    aragorn = TextureManager::LoadTextureImg("../images/characters/aragorn/Face.png");
    aragorn_fight = TextureManager::LoadTextureImg("../images/characters/aragorn/BtlFace_D.png");

    next = TextureManager::LoadTextureFontStoryNextPage();
    choice = TextureManager::LoadTextureFontStoryChoice();

    text1 = TextureManager::LoadTextureFontStory("Il était une fois  ... \n"
                                                 "????? : Mais laisse moi donc parler et comment ça \"?????\" ?\n"
                                                 "????? : My name is Targaryen, Aragorn Targaryen.\n"
                                                 "Aragorn : Mais pourquoi je parle dans cette langue bizarre ? Bon ecoute moi bien ! Oui, c'est bien à toi que je parle !\n"
                                                 "Aragorn : T'as intérêt à bien faire attention à ce que tu fais parce que c'est moi que tu vas incarner pendant cette aventure.\n"
                                                 "Aragorn : Hummm... Je vais lui rendre la parole sinon je vais me faire taper sur les doigts.",
                                                 size);
    text2 = TextureManager::LoadTextureFontStory("Je disais donc, vous êtes un héros qui voyage à travers les terres de l'extrême milieu.\n"
                                                 "Pour quelles raisons ? la gloire ? la fortune ? l'amour ? Vous le déciderez avec vos choix tout au long de cette avanture.\n"
                                                 "C'est parti ! Allons-y let's go, c'est parti les amis !",
                                                 size);
    text3 = TextureManager::LoadTextureFontStory("Vous vous réveillez en plein milieu d'une forêt mais vous ne vous rappelez plus de ce qui s'est passé avant (attention l'abus d'alcool est dangereux pour la santé).\n"
                                                 "Vous entendez des bruits au loin et voyez une troupe de bandits qui se dirigent vers vous. Quelle va être votre décision ?\n"
                                                 "1. Vous décidez de faire preuve de bravoure, vous allez en découdre avec ces manants.\n"
                                                 "2. Vous n'êtes pas un peureux (on le dira à personne) mais vous décidez tout de même d'aller vous cacher.",
                                                 size);
    text4 = TextureManager::LoadTextureFontStory("Après un certain temps, vous n'entendez plus de bruit.\n"
                                                 "Que faites-vous ?\n"
                                                 "1. Vous décidez d'attendre encore un peu, comme vous l'a souvent répété votre maman : prudence est mère de sûreté !\n"
                                                 "2. Vous n'avez que faire des conseils de votre mère, vous n'avez plus 5 ans après tout et vous décidez de sortir.",
                                                 size);
    text5 = TextureManager::LoadTextureFontStory("Manque de bol ! Un des bandits vous urine dessus sans faire exprès, vous ne pouvez supporter l'affront !\n"
                                                 "Vous arrivez à l'abattre mais vous ne faites pas long feu face à ces camarades...\n"
                                                 "Peut-être aurez-vous plus de chance la prochaine fois ... ?",
                                                 size);
    text6 = TextureManager::LoadTextureFontStory("Vous tombez nez à nez avec l'un des bandits qui vient de se réveiller de sa sieste.\n"
                                                 "Vous arrivez à l'abattre mais il vous blesse.\n",
                                                 size);
    text7 = TextureManager::LoadTextureFontStory("Quelle idée de se lancer seul contre une troupe de bandits ! Vous n'êtes pas un super héros !\n"
                                                 "Aragorn : Je t'avais dit de faire attention ! Ah ces jeunes...",
                                                 size);

    text_selector = 0;


    Global::GenerateLife();
//    std::cout << Global::CheckLife() << std::endl;

    printf("IntroState Init Successful\n");
}

std::vector<SDL_Texture*> IntroState::ChangeText()
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


void IntroState::Clean()
{
    Mix_HaltMusic();
    Mix_CloseAudio();
    SDL_DestroyTexture(next);
    SDL_DestroyTexture(choice);
    SDL_DestroyTexture(background);
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
                        switch (IntroState::text_selector)
                        {
                            case 0:
                                IntroState::text_selector += 1;
                                break;

                            case 1:
                                IntroState::text_selector += 1;
                                break;

                            case 4:
                                game->ChangeState(DeadState::Instance());
                                break;

                            case 5:
                                Global::ModifyLife(-(rand() % (3 - 2 + 1) + 2));
                                game->ChangeState(Stage1State::Instance());
                                break;

                            case 6:
                                game->ChangeState(DeadState::Instance());
                                break;
                        }
                        break;

                    case SDLK_1:
                        switch (IntroState::text_selector)
                        {
                            case 2:
                                IntroState::text_selector = 6;
                                break;
//
                            case 3:
                                int tmp_rand = rand() % (9 - 0 + 1) + 0;
                                if (tmp_rand > 1)
                                {
//                                    std::cout << "next state" << std::endl;
                                    game->ChangeState(Stage1State::Instance());
                                }
                                else
                                {
                                    IntroState::text_selector = 4;
                                }
                                break;
                        }
                        break;

                    case SDLK_2:
                        switch (IntroState::text_selector)
                        {
                            case 2:
                                IntroState::text_selector += 1;
                                break;

                            case 3:
                                IntroState::text_selector += 2;
                                break;
                        }
                        break;

                    case SDLK_F1:
                        game->ChangeState(Stage1State::Instance());
                        break;

                    case SDLK_F2:
                        game->ChangeState(ForestState::Instance());
                        break;

                case SDLK_F3:
                    game->ChangeState(MountainState::Instance());
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

    background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background, background_src, background_dest, size);

    if (IntroState::text_selector == 4 || IntroState::text_selector == 5 || IntroState::text_selector == 6)
    {
        aragorn_fight_src.x = aragorn_fight_src.y = 0;
        aragorn_fight_dest.w = int(size.x*2/5 + 0.5);
        aragorn_fight_dest.h = int(aragorn_fight_dest.w/1.2 + 0.5);
        aragorn_fight_dest.x = background_dest.w*2/3 - aragorn_fight_dest.h/2;
        aragorn_fight_dest.y = background_dest.h*2/3 - aragorn_fight_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn_fight, aragorn_fight_src, aragorn_fight_dest);
    }
    else
    {
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*2/3 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
    }

    background_text_dest = TextureManager::DrawBackgroundTextStory(game->m_pRenderer, background_text, background_text_src, background_text_dest, size, background_dest);

    TextureManager::DrawFontStory(game->m_pRenderer, ChangeText()[IntroState::text_selector], text_dest, background_text_dest);

    if (IntroState::text_selector == 2 || IntroState::text_selector == 3)
    {
        TextureManager::DrawFontStoryChoice(game->m_pRenderer, choice, next_dest, background_text_dest);
    }
    else
    {
        TextureManager::DrawFontStoryNextPage(game->m_pRenderer, next, next_dest, background_text_dest);
    }

    SDL_RenderPresent(game->m_pRenderer);
}
