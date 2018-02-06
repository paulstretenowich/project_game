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
#include "seastate.h"
#include "deadstate.h"
#include "introstate.h"
#include "foreststate.h"
#include "endstate.h"
#include "global.h"

SeaState SeaState::m_SeaState;

void SeaState::Init()
{
//    int life = IntroState::life;

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/sea.ogg");
    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background = TextureManager::LoadTextureImg("../images/background_story/background_sea.png");

    background_text = TextureManager::LoadTextureImg("../images/background_story/background_text.png");

    aragorn = TextureManager::LoadTextureImg("../images/characters/aragorn/Face.png");
    aragorn_fight = TextureManager::LoadTextureImg("../images/characters/aragorn/BtlFace_D.png");
    hector = TextureManager::LoadTextureImg("../images/characters/hector/Face.png");
    ciri = TextureManager::LoadTextureImg("../images/characters/ciri/Face.png");

    next = TextureManager::LoadTextureFontStoryNextPage();
    choice = TextureManager::LoadTextureFontStoryChoice();

    text1 = TextureManager::LoadTextureFontStory("Vous êtes sur le bateau en direction de Niméa.\n"
                                                 "Vous entendez un bruit sourd et violent puis un cri retentissant \"A l'abordage\", des pirates.\n"
                                                 "Vous vous précipitez sur le pont. Vous voyez le bateau pirate en abordage en belle. Que faites vous ?\n"
                                                 "1. Vous défendez vos positions.\n"
                                                 "2. Vous essayez de les prendre à revers en sautant sur leur bateau.",
                                                 size);
    text2 = TextureManager::LoadTextureFontStory("Le combat est d'un violence rare, les deux côtés subissent des dégâts conséquents mais vous arrivez tout de même à les repousser. Vous subissez des dégâts non négligeables durant l'affrontement.",
                                                 size);
    text3 = TextureManager::LoadTextureFontStory("Quelle idée de génie, vous arrivez à détourner leur attention en mettent le feu à leur cale.\n"
                                                 "Ils battent donc en retraite afin de sauver leur navire. Vous rejoignez votre navire en éliminant quelques pirates en déroute.",
                                                 size);
    text4 = TextureManager::LoadTextureFontStory("Quelle idée d'aller se jeter dans la gueule du loup (des mers)!!!",
                                                 size);
    text5 = TextureManager::LoadTextureFontStory("Après cette éprouvante épreuve, le capitaine décide de faire un état du navire.\"Prudence est mère de sûreté\", vous dit-il cela vous rappelle votre famille.\n"
                                                 "Pendant la vérification, une passagère clandestine est amené sur le pont pour que son sort soit décidé",
                                                 size);
    text6 = TextureManager::LoadTextureFontStory("Vous reconnaissez la clandestine, c'est Ciri la jeune aventurière que vous avez rencontré dans la forêt. Elle aussi se rappelle de vous et vous souris en réponse.\n"
                                                 "Le capitaine remarque cet échange et vous luis dites que c'est une amie très proche.\n"
                                                 "Capitaine : Ainsi soit-il, si vous êtes une amie de messire, je ne peux me permettre de vous rendre la vie difficile",
                                                 size);
    text7 = TextureManager::LoadTextureFontStory("Aragorn : Comme on se retrouve !\n"
                                                 "Ciri : Je ne saurais comment vous remercier. Vous m'avez sauvé la vie !\n"
                                                 "Aragron : Vous pourriez m'accompagner un peu pendant mon périple.\n"
                                                 "Ciri : Ce serait avec plaisir! ",
                                                 size);
    text8 = TextureManager::LoadTextureFontStory("Vous faites amplement connaissance durant le reste du trajet, elle vous révèle qu'elle est la princesse Dora, héritières des terres de l'extrême milieu mais qu'elle veut vivre une vie pleine d'aventure, elle a donc décidé de fuir.\n"
                                                 "Le destin vous a réuni pour partager une vie d'aventure et d'amour.",
                                                 size);
    text9 = TextureManager::LoadTextureFontStory("Vous ne reconnaissez pas la charmante demoiselle, mais son visage vous dit quelque chose.\n"
                                                 "Vous la fixez pour essayer de vous rappeler de quelque chose. \n"
                                                 "Capitaine : Vous la connaissez messire Targaryen ?\n"
                                                 "Aragorn : Non, enfin je ne pense pas.\n"
                                                 "Capitaine : Nous pensions lui faire prendre la planche.",
                                                 size);
    text10 = TextureManager::LoadTextureFontStory("Que décidez vous de faire ?\n"
                                                  "1. Vous décider de lui sauvez la vie en discutant avec le capitaine.\n"
                                                  "2. Son sort ne vous interesse guère et vous laissez le capitaine faire ce qu'il veut d'elle.",
                                                 size);
    text11 = TextureManager::LoadTextureFontStory("La jeune demoiselle se présente sous le nom de Ciri.\n"
                                                  "Ciri : Je ne saurais comment vous remercier. Vous m'avez sauvé la vie !\n"
                                                  "Aragron : Vous pourriez m'accompagner un peu pendant mon périple.\n"
                                                  "Ciri : Ce serait avec plaisir!",
                                                 size);
    text12 = TextureManager::LoadTextureFontStory("Vous retournez dans votre cabine comme si de rien n'était et vous continuez vers votre vie pleine d'aventure.\n"
                                                  "Cependant un sentiment de vide s'empare de vous quand vous repensez à elle.",
                                                 size);
    text13 = TextureManager::LoadTextureFontStory("Vous reconnaissez la clandestine, c'est Ciri la jeune aventurière avec que vous avez rencontré dans la forêt.\n"
                                                  "Elle aussi se rappelle de vous et vous fixe. Le capitaine remarque cet échange.\n"
                                                  "Capitaine : Vous la connaissez messire Targaryen ?\n"
                                                  "Aragorn : Oui,enfin c'est une juste une connaissance, nous nous somme juste croisés!\n"
                                                  "Capitaine : Nous pensions lui faire prendre la planche.",
                                                 size);
    text14 = TextureManager::LoadTextureFontStory("Aragorn : Comme on se retrouve !\n"
                                                  "Ciri : Je ne saurais comment vous remercier. Vous m'avez sauvé la vie !\n"
                                                  "Aragron :  Vous pourriez m'accompagner un peu pendant mon périple... et aussi éviter de me frapper\n"
                                                  "Ciri (en souriant) : Ce serait avec plaisir!",
                                                 size);
    text15 = TextureManager::LoadTextureFontStory("Malheureusement vous mourrez de vos blessures accumulées durant votre aventure.", size);

    text_selector = 0;
//    std::cout << Global::CheckLife() << std::endl;

    printf("SeaState Init Successful\n");
}

std::vector<SDL_Texture*> SeaState::ChangeText()
{
    std::vector<SDL_Texture*> vecOfText;
    vecOfText.push_back(text1);
    vecOfText.push_back(text2);
    vecOfText.push_back(text3);
    vecOfText.push_back(text4);
    vecOfText.push_back(text5);
    vecOfText.push_back(text6);
    vecOfText.push_back(text7);
    vecOfText.push_back(text8);
    vecOfText.push_back(text9);
    vecOfText.push_back(text10);
    vecOfText.push_back(text11);
    vecOfText.push_back(text12);
    vecOfText.push_back(text13);
    vecOfText.push_back(text14);
    vecOfText.push_back(text15);
    return vecOfText;
}


void SeaState::Clean()
{
    Mix_HaltMusic();
    Mix_CloseAudio();
    SDL_DestroyTexture(next);
    SDL_DestroyTexture(choice);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(aragorn_fight);
    SDL_DestroyTexture(aragorn);
    SDL_DestroyTexture(hector);
    SDL_DestroyTexture(ciri);
    SDL_DestroyTexture(background_text);
    SDL_DestroyTexture(text1);
    SDL_DestroyTexture(text2);
    SDL_DestroyTexture(text3);
    SDL_DestroyTexture(text4);
    SDL_DestroyTexture(text5);
    SDL_DestroyTexture(text6);
    SDL_DestroyTexture(text7);
    SDL_DestroyTexture(text8);
    SDL_DestroyTexture(text9);
    SDL_DestroyTexture(text10);
    SDL_DestroyTexture(text11);
    SDL_DestroyTexture(text12);
    SDL_DestroyTexture(text13);
    SDL_DestroyTexture(text14);
    SDL_DestroyTexture(text15);
    printf("SeaState Clean Successful\n");
}

void SeaState::Pause()
{
    printf("SeaState Paused\n");
}

void SeaState::Resume()
{
    printf("SeaState Resumed\n");
}

void SeaState::HandleEvents(Game* game) //put our exit function back in business we can now quit with cross in corner.
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
                        switch (SeaState::text_selector)
                        {
                            case 1:
                                if (Global::CheckLife() <= 0)
                                {
                                    SeaState::text_selector = 14;
                                }
                                else
                                {
                                    SeaState::text_selector = 4;
                                }
                                break;

                            case 2:
                                SeaState::text_selector = 4;
                                break;

                            case 3:
                                game->ChangeState(DeadState::Instance());
                                break;

                            case 4:
                                switch (Global::CheckCiri())
                                {
                                    case -1:
                                        SeaState::text_selector = 12;
                                        break;

                                    case 0:
                                        SeaState::text_selector = 8;
                                        break;

                                    case 1:
                                        SeaState::text_selector = 5;
                                        break;
                                }
                                break;

                            case 5:
                                SeaState::text_selector = 6;
                                break;

                            case 6:
                                SeaState::text_selector = 7;
                                break;

                            case 7:
                                game->ChangeState(EndState::Instance());
                                break;

                            case 8:
                                SeaState::text_selector = 9;
                                break;

                            case 10:
                                SeaState::text_selector = 7;
                                break;

                            case 11:
                                game->ChangeState(EndState::Instance());
                                break;

                            case 12:
                                SeaState::text_selector = 9;
                                break;

                            case 13:
                                SeaState::text_selector = 7;
                                break;

                            case 14:
                                game->ChangeState(DeadState::Instance());
                                break;
                        }
                        break;

                    case SDLK_1:
                        switch (SeaState::text_selector)
                        {
                            case 0:
                                Global::ModifyLife(-(rand() % (3 - 2 + 1) + 2));
                                SeaState::text_selector = 4;
                                break;

                            case 9:
                                SeaState::text_selector = 10;
                                break;
                        }
                        break;

                    case SDLK_2:
                        switch (SeaState::text_selector)
                        {
                            case 0:
                                if ((rand() % (9 - 0 + 1) + 0) > 2)
                                {
                                    SeaState::text_selector = 2;
                                }
                                else
                                {
                                    SeaState::text_selector = 3;
                                }
                                break;

                            case 9:
                                SeaState::text_selector = 11;
                                break;
                        }
                        break;
                }
        }
    }
}

void SeaState::Update(Game* game)
{
}

void SeaState::Draw(Game* game)
{
    SDL_RenderClear(game->m_pRenderer);

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background_dest = TextureManager::DrawBackgroundStory(game->m_pRenderer, background, background_src, background_dest, size);

    if (SeaState::text_selector == 0 || SeaState::text_selector == 11 || SeaState::text_selector == 2)
    {
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*6/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
    }
    else if (SeaState::text_selector == 4 || SeaState::text_selector == 5 || SeaState::text_selector == 8 || SeaState::text_selector == 12)
    {
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*6/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
        ciri_src.x = ciri_src.y = 0;
        ciri_dest.w = int(size.x*2/5 + 0.5);
        ciri_dest.h = int(ciri_dest.w/1.2 + 0.5);
        ciri_dest.x = background_dest.w*8/10 - ciri_dest.h/2;
        ciri_dest.y = background_dest.h*2/3 - ciri_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, ciri, ciri_src, ciri_dest);
        hector_src.x = hector_src.y = 0;
        hector_dest.w = int(size.x*2/5 + 0.5);
        hector_dest.h = int(hector_dest.w/1.2 + 0.5);
        hector_dest.x = background_dest.w*2/10 - hector_dest.h/2;
        hector_dest.y = background_dest.h*2/3 - hector_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, hector, hector_src, hector_dest);
    }
    else if (SeaState::text_selector == 6 || SeaState::text_selector == 7 || SeaState::text_selector == 10 || SeaState::text_selector == 13)
    {
        aragorn_src.x = aragorn_src.y = 0;
        aragorn_dest.w = int(size.x*2/5 + 0.5);
        aragorn_dest.h = int(aragorn_dest.w/1.2 + 0.5);
        aragorn_dest.x = background_dest.w*6/10 - aragorn_dest.h/2;
        aragorn_dest.y = background_dest.h*2/3 - aragorn_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn, aragorn_src, aragorn_dest);
        ciri_src.x = ciri_src.y = 0;
        ciri_dest.w = int(size.x*2/5 + 0.5);
        ciri_dest.h = int(ciri_dest.w/1.2 + 0.5);
        ciri_dest.x = background_dest.w*8/10 - ciri_dest.h/2;
        ciri_dest.y = background_dest.h*2/3 - ciri_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, ciri, ciri_src, ciri_dest);
    }
    else if (SeaState::text_selector == 1 || SeaState::text_selector == 3 || SeaState::text_selector == 14)
    {
        aragorn_fight_src.x = aragorn_fight_src.y = 0;
        aragorn_fight_dest.w = int(size.x*2/5 + 0.5);
        aragorn_fight_dest.h = int(aragorn_fight_dest.w/1.2 + 0.5);
        aragorn_fight_dest.x = background_dest.w*6/10 - aragorn_fight_dest.h/2;
        aragorn_fight_dest.y = background_dest.h*2/3 - aragorn_fight_dest.w/2 + 5;
        TextureManager::Draw(game->m_pRenderer, aragorn_fight, aragorn_fight_src, aragorn_fight_dest);
    }
    background_text_dest = TextureManager::DrawBackgroundTextStory(game->m_pRenderer, background_text, background_text_src, background_text_dest, size, background_dest);

    TextureManager::DrawFontStory(game->m_pRenderer, ChangeText()[SeaState::text_selector], text_dest, background_text_dest);

    if (SeaState::text_selector == 0 || SeaState::text_selector == 9)
    {
        TextureManager::DrawFontStoryChoice(game->m_pRenderer, choice, next_dest, background_text_dest);
    }
    else
    {
        TextureManager::DrawFontStoryNextPage(game->m_pRenderer, next, next_dest, background_text_dest);
    }

    SDL_RenderPresent(game->m_pRenderer);
}
