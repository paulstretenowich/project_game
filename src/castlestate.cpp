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
#include "castlestate.h"
#include "deadstate.h"
#include "introstate.h"
#include "seatownstate.h"
#include "global.h"

CastleState CastleState::m_CastleState;

void CastleState::Init()
{
//    int life = IntroState::life;

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/castle_zelda.ogg");
    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background = TextureManager::LoadTextureImg("../images/background_story/005_Castle.png");

    background_text = TextureManager::LoadTextureImg("../images/background_story/background_text.png");

    aragorn = TextureManager::LoadTextureImg("../images/characters/aragorn/Face.png");
    aragorn_fight_injury = TextureManager::LoadTextureImg("../images/characters/aragorn/BtlFace_D.png");
    aragorn_fight = TextureManager::LoadTextureImg("../images/characters/aragorn/BtlFace_flip.png");

    ciri = TextureManager::LoadTextureImg("../images/characters/ciri/Face.png");

    geralt = TextureManager::LoadTextureImg("../images/characters/geralt/BtlFace.png");

    king = TextureManager::LoadTextureImg("../images/characters/king/Face.png");

    next = TextureManager::LoadTextureFontStoryNextPage();
    choice = TextureManager::LoadTextureFontStoryChoice();

    text1 = TextureManager::LoadTextureFontStory("Vous arrivez à vous infiltrer et à accéder la plus haute salle du donjon sans trop de difficulté. (A croire que les réalisateurs en avaient marre au moment où ils ont écrit ce passage)\n"
                                                 "Vous y trouvez une personne encapuchonné et vous lui dites que vous êtes la pour la sauver.\n"
                                                 "A ce moment la garde réagi et vous décidez de fuir au plus vite.\n"
                                                 "Vous appercevez devant la porte principale le comte Geralt Lannister qui vous défie.\n"
                                                 "Vous vous battez à la loyale. C'etait un vaillant combattant, vous arrivez à le défaire et vous fuyez blessé.",
                                                 size);
    text2 = TextureManager::LoadTextureFontStory("Vous soulevez la capuche et vous y découvrez un visage aux traits finement ciselés. Vous apprenez que c'est la princesse Dora, héritières des terres de l'extrême milieu. Elle vous avoue qu'elle veut vivre une vie pleine d'aventure, elle a donc décidé de fuir.\n"
                                                 "Vous décidez de la ramener au château. Le roi vous récompense en vous offrant la main de sa fille.\n"
                                                 "Vous mourrez quelques mois plus tard victime de manigances politiques. ",
                                                 size);
    text3 = TextureManager::LoadTextureFontStory("Vous soulevez la capuche et vous y découvrez un visage familier : l'aventurière de la forêt. Vous apprenez que c'est la princesse Dora, héritières des terres de l'extrême milieu. Elle vous avoue qu'elle veut vivre une vie pleine d'aventure, elle a donc décidé de fuir.\n"
                                                 "Vous décidez de la ramener au château. Le roi vous récompense en vous offrant la main de sa fille.\n"
                                                 "Vous mourrez quelques mois plus tard victime de manigances politiques. ",
                                                 size);

    text4 = TextureManager::LoadTextureFontStory("Malheureusement vous mourrez de vos blessures accumulées durant votre aventure.", size);
    text_selector = 0;

//    std::cout << Global::CheckLife() << std::endl;

    printf("CastleState Init Successful\n");
}

std::vector<SDL_Texture*> CastleState::ChangeText()
{
    std::vector<SDL_Texture*> vecOfText;
    vecOfText.push_back(text1);
    vecOfText.push_back(text2);
    vecOfText.push_back(text3);
    vecOfText.push_back(text4);
    return vecOfText;
}


void CastleState::Clean()
{
    Mix_HaltMusic();
    Mix_CloseAudio();
    SDL_DestroyTexture(next);
    SDL_DestroyTexture(choice);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(aragorn);
    SDL_DestroyTexture(aragorn_fight);
    SDL_DestroyTexture(aragorn_fight_injury);
    SDL_DestroyTexture(ciri);
    SDL_DestroyTexture(geralt);
    SDL_DestroyTexture(king);
    SDL_DestroyTexture(background_text);
    SDL_DestroyTexture(text1);
    SDL_DestroyTexture(text2);
    SDL_DestroyTexture(text3);
    SDL_DestroyTexture(text4);
    printf("CastleState Clean Successful\n");
}

void CastleState::Pause()
{
    printf("CastleState Paused\n");
}

void CastleState::Resume()
{
    printf("CastleState Resumed\n");
}

void CastleState::HandleEvents(Game* game) //put our exit function back in business we can now quit with cross in corner.
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
                        switch (CastleState::text_selector)
                        {
                            case 0:
                                Global::ModifyLife(-(rand() % (3 - 1 + 1) + 1));
                                if (Global::CheckLife() <= 0)
                                {
                                    CastleState::text_selector = 3;
                                }
                                else
                                {
                                    if (Global::CheckCiri() == 0)
                                    {
                                        CastleState::text_selector = 1;
                                    }
                                    else
                                    {
                                        CastleState::text_selector = 1;
                                    }
                                    break;
                                }
                                break;

                            case 1:
                                game->ChangeState(DeadState::Instance());
                                break;

                            case 2:
                                game->ChangeState(DeadState::Instance());
                                break;

                            case 3:
                                game->ChangeState(DeadState::Instance());
                                break;
                        }
                        break;
                }
        }
    }
}

void CastleState::Update(Game* game)
{
}

void CastleState::Draw(Game* game)
{
    SDL_RenderClear(game->m_pRenderer);

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background, background_src, background_dest, size);

    if (CastleState::text_selector == 0)
    {
        geralt_src.x = geralt_src.y = 0;
        geralt_dest.w = int(size.x*2/5 + 0.5);
        geralt_dest.h = int(geralt_dest.w/1.2 + 0.5);
        geralt_dest.x = background_dest.w*2/10 - geralt_dest.h/2;
        geralt_dest.y = background_dest.h*2/3 - geralt_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, geralt, geralt_src, geralt_dest);
        aragorn_fight_src.x = aragorn_fight_src.y = 0;
        aragorn_fight_dest.w = int(size.x*2/5 + 0.5);
        aragorn_fight_dest.h = int(aragorn_fight_dest.w/1.2 + 0.5);
        aragorn_fight_dest.x = background_dest.w*6/10 - aragorn_fight_dest.h/2;
        aragorn_fight_dest.y = background_dest.h*2/3 - aragorn_fight_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn_fight, aragorn_fight_src, aragorn_fight_dest);
    }
    else
    {
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*2/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
        ciri_src.x = ciri_src.y = 0;
        ciri_dest.w = int(size.x*2/5 + 0.5);
        ciri_dest.h = int(ciri_dest.w/1.2 + 0.5);
        ciri_dest.x = background_dest.w*4/10 - ciri_dest.h/2;
        ciri_dest.y = background_dest.h*2/3 - ciri_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, ciri, ciri_src, ciri_dest);
        king_src.x = king_src.y = 0;
        king_dest.w = int(size.x*2/5 + 0.5);
        king_dest.h = int(king_dest.w/1.2 + 0.5);
        king_dest.x = background_dest.w*8/10 - king_dest.h/2;
        king_dest.y = background_dest.h*2/3 - king_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, king, king_src, king_dest);
    }

    background_text_dest = TextureManager::DrawBackgroundTextStory(game->m_pRenderer, background_text, background_text_src, background_text_dest, size, background_dest);

    TextureManager::DrawFontStory(game->m_pRenderer, ChangeText()[CastleState::text_selector], text_dest, background_text_dest);

    TextureManager::DrawFontStoryNextPage(game->m_pRenderer, next, next_dest, background_text_dest);


    SDL_RenderPresent(game->m_pRenderer);
}
