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
#include "seatownstate.h"
#include "deadstate.h"
#include "introstate.h"
#include "foreststate.h"
#include "global.h"

SeaTownState SeaTownState::m_SeaTownState;

void SeaTownState::Init()
{
//    int life = IntroState::life;

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/seatown.ogg");
    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background_tavern = TextureManager::LoadTextureImg("../images/background_story/005_CastleJP.png");
    background_outside = TextureManager::LoadTextureImg("../images/background_story/002_PlainSea.png");

    background_text = TextureManager::LoadTextureImg("../images/background_story/background_text.png");

    aragorn = TextureManager::LoadTextureImg("../images/characters/aragorn/Face.png");
    ogma = TextureManager::LoadTextureImg("../images/characters/ogma/Face.png");

    next = TextureManager::LoadTextureFontStoryNextPage();
    choice = TextureManager::LoadTextureFontStoryChoice();

    text1 = TextureManager::LoadTextureFontStory("En suivant la côte, vous arrivez à Marsalia, l'un des ports les plus corrompus de  la région.\n"
                                                 "En traversant la ville vous entendez souvent le nom de la princesse Dora, héritière du royame de l'extrême milieu.\n"
                                                 "Cette dernière est portée disparue, avec une grosse récompense pour celui qui la retrouvera. Vous décidez d'y jeter un oeil.\n"
                                                 "Ce que vous voyez vous glace le sang... Le portrait que vous voyez affiché ressemble comme deux gouttes d'eau à l'aventurière que vous avez tué dans la forêt.\n"
                                                 "Vous décidez de partir en exil pour éviter toute possibilités de représailles.",
                                                 size);
    text2 = TextureManager::LoadTextureFontStory("En suivant la côte, vous arrivez à Marsalia, l'un des ports les plus corrompus de  la région.\n"
                                                 "Ayant déjà cotoyé les pires bandits vous avez quelques connaissances dans la ville.\n"
                                                 "Vous décidez donc d'aller :\n"
                                                 "1. A la taverne pour boire une bonne cervoise et manger une bouillabaisse.\n"
                                                 "2. Au port.\n"
                                                 "3. A l'office du tourisme pour aller saluer votre ami Flash.",
                                                 size);
    text3 = TextureManager::LoadTextureFontStory("A la Taverne, vous revoyez votre ami Ogma, marin, qui se détend entre deux voyages. Après avoir ressassé vos souvenirs et partagé plusieurs bières, il vous propose de le suivre durant son prochain voyage a Niméa, un port du Gondor.",
                                                 size);
    text4 = TextureManager::LoadTextureFontStory("A la Taverne, vous entendez dire que le comte Geralt Lannister aurait kidnappé une jeune demoiselle.\n"
                                                 "Que voulez vous faire?\n"
                                                 "1. Vous allez au secours de la demoiselle en détresse\n"
                                                 "2. Ce sont ces affaires, certes vous auriez aimé déranger les plans du Comte mais le jeu n'en vaut pas la chandelle. Vous allez au port.",
                                                 size);
    text5 = TextureManager::LoadTextureFontStory("Au port, vous entendez parler d'un trésor non loin de Niméa, un port du Gondor.\n"
                                                 "Vous décidez de vous y rendre afin de tenter votre chance, vous embarquez à bord du premier bateau en partance.\n",
                                                 size);
    text6 = TextureManager::LoadTextureFontStory("Une fois dans la \"file d'attente\" de l'office du tourisme vous êtes comme pris au piège dans une lenteur sans fin.\n"
                                                 "Vous en oubliez  votre famille, amis et proches. Et mourrez de vielliesse avant d'avoir pu parler à Flash...",
                                                 size);
    if (Global::CheckCiri() == -2)
    {
        text_selector = 0;
    }
    else
    {
        text_selector = 1;
    }

//    std::cout << Global::CheckLife() << std::endl;

    printf("SeaTownState Init Successful\n");
}

std::vector<SDL_Texture*> SeaTownState::ChangeText()
{
    std::vector<SDL_Texture*> vecOfText;
    vecOfText.push_back(text1);
    vecOfText.push_back(text2);
    vecOfText.push_back(text3);
    vecOfText.push_back(text4);
    vecOfText.push_back(text5);
    vecOfText.push_back(text6);
    return vecOfText;
}


void SeaTownState::Clean()
{
    Mix_HaltMusic();
    Mix_CloseAudio();
    SDL_DestroyTexture(next);
    SDL_DestroyTexture(choice);
    SDL_DestroyTexture(background_tavern);
    SDL_DestroyTexture(background_outside);
    SDL_DestroyTexture(aragorn);
    SDL_DestroyTexture(ogma);
    SDL_DestroyTexture(background_text);
    SDL_DestroyTexture(text1);
    SDL_DestroyTexture(text2);
    SDL_DestroyTexture(text3);
    SDL_DestroyTexture(text4);
    SDL_DestroyTexture(text5);
    SDL_DestroyTexture(text6);
    printf("SeaTownState Clean Successful\n");
}

void SeaTownState::Pause()
{
    printf("SeaTownState Paused\n");
}

void SeaTownState::Resume()
{
    printf("SeaTownState Resumed\n");
}

void SeaTownState::HandleEvents(Game* game) //put our exit function back in business we can now quit with cross in corner.
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
                        switch (SeaTownState::text_selector)
                        {
                            case 0:
                                game->ChangeState(DeadState::Instance());
                                break;

                            case 2:
                                std::cout << "sea state" << std::endl;
//                                game->ChangeState(DeadState::Instance());
                                break;

                            case 4:
                                std::cout << "sea state" << std::endl;
//                                game->ChangeState(DeadState::Instance());
                                break;

                            case 5:
                                game->ChangeState(DeadState::Instance());
                                break;
                        }
                        break;

                    case SDLK_1:
                        switch (SeaTownState::text_selector)
                        {
                            case 1:
                                Global::ModifyLife((rand() % (4 - 2 + 1) + 2));
                                if ((rand() % (9 - 0 + 1) + 0) > 4)
                                {
                                    SeaTownState::text_selector = 2;
                                }
                                else
                                {
                                    SeaTownState::text_selector = 3;
                                }
                                break;

                            case 3:
                                std::cout << "castle state" << std::endl;
//                                game->ChangeState(DeadState::Instance());
                                break;
                        }
                        break;

                    case SDLK_2:
                        switch (SeaTownState::text_selector)
                        {
                            case 1:
                                SeaTownState::text_selector = 4;
                                break;

                            case 2:
                                std::cout << "sea state" << std::endl;
                                break;

                            case 3:
                                SeaTownState::text_selector = 4;
                                break;
                        }
                        break;

                    case SDLK_3:
                        switch (SeaTownState::text_selector)
                        {
                            case 1:
                                SeaTownState::text_selector = 5;
                            break;
                        }
                        break;
                }
        }
    }
}

void SeaTownState::Update(Game* game)
{
}

void SeaTownState::Draw(Game* game)
{
    SDL_RenderClear(game->m_pRenderer);

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    if (SeaTownState::text_selector == 0 || SeaTownState::text_selector == 1 || SeaTownState::text_selector == 4 || SeaTownState::text_selector == 5)
    {
        background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background_outside, background_src, background_dest, size);
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*2/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
    }
    else if (SeaTownState::text_selector == 2)
    {
        background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background_tavern, background_src, background_dest, size);
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*7/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
        ogma_src.x = ogma_src.y = 0;
        ogma_dest.w = int(size.x*2/5 + 0.5);
        ogma_dest.h = int(ogma_dest.w/1.2 + 0.5);
        ogma_dest.x = background_dest.w*4/10 - ogma_dest.h/2;
        ogma_dest.y = background_dest.h*2/3 - ogma_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, ogma, ogma_src, ogma_dest);
    }
    else if (SeaTownState::text_selector == 3)
    {
        background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background_tavern, background_src, background_dest, size);
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*7/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
    }

    background_text_dest = TextureManager::DrawBackgroundTextStory(game->m_pRenderer, background_text, background_text_src, background_text_dest, size, background_dest);

    TextureManager::DrawFontStory(game->m_pRenderer, ChangeText()[SeaTownState::text_selector], text_dest, background_text_dest);

    if (SeaTownState::text_selector == 1 || SeaTownState::text_selector == 3)
    {
        TextureManager::DrawFontStoryChoice(game->m_pRenderer, choice, next_dest, background_text_dest);
    }
    else
    {
        TextureManager::DrawFontStoryNextPage(game->m_pRenderer, next, next_dest, background_text_dest);
    }

    SDL_RenderPresent(game->m_pRenderer);
}
