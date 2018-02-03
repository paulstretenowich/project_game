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
#include "menustate.h"
#include "optionstate.h"
#include "texturemanager.h"

MenuState MenuState::m_MenuState;
//Game g;

void MenuState::Init()
{
    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/menu_music.ogg");
    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background = TextureManager::LoadTextureImg("../images/menu/menu_background_new_002.png");

    quit_button = TextureManager::LoadTextureImg("../images/menu/button.png");
    quit_button_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 35, 255, 255, 255, "Quitter");
//    quit_button_src.x = quit_button_src.y = 0;
//    quit_button_dest.w = 300;
//    quit_button_font_dest.w = quit_button_dest.w*2/3;
//    quit_button_dest.h = 50;
//    quit_button_font_dest.h = quit_button_dest.h*2/3;
//    quit_button_dest.x = size.x/2 - quit_button_dest.w/2;
//    quit_button_font_dest.x = size.x/2 - quit_button_font_dest.w/2;
//    quit_button_dest.y = size.y*5/8 - quit_button_dest.h/2;
//    quit_button_font_dest.y = size.y*5/8 - quit_button_font_dest.h/2;

    play_button = TextureManager::LoadTextureImg("../images/menu/button.png");
    play_button_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 35, 255, 255, 255, "Jouer");
//    play_button_src.x = play_button_src.y = 0;
//    play_button_dest.w = 300;
//    play_button_font_dest.w = play_button_dest.w*2/3;
//    play_button_dest.h = 50;
//    play_button_font_dest.h = play_button_dest.h*2/3;
//    play_button_dest.x = size.x/2 - play_button_dest.w/2;
//    play_button_font_dest.x = size.x/2 - play_button_font_dest.w/2;
//    play_button_dest.y = size.y*3/8 - play_button_dest.h/2;
//    play_button_font_dest.y = size.y*3/8 - play_button_font_dest.h/2;

    selector = TextureManager::LoadTextureImg("../images/menu/menu_selector.png");
//    selector_src.x = selector_src.y = 0;
//    selector_dest.x = play_button_dest.x - 1;
//    selector_dest.y = play_button_dest.y - 1;
//    selector_dest.w = play_button_dest.w + 1;
//    selector_dest.h = play_button_dest.h + 1;

    option_button = TextureManager::LoadTextureImg("../images/menu/button.png");
    option_button_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 35, 255, 255, 255, "Options");
//    option_button_src.x = option_button_src.y = 0;
//    option_button_dest.w = 300;
//    option_button_font_dest.w = option_button_dest.w*2/3;
//    option_button_dest.h = 50;
//    option_button_font_dest.h = option_button_dest.h*2/3;
//    option_button_dest.x = size.x/2 - option_button_dest.w/2;
//    option_button_font_dest.x = size.x/2 - option_button_font_dest.w/2;
//    option_button_dest.y = size.y*4/8 - option_button_dest.h/2;
//    option_button_font_dest.y = size.y*4/8 - option_button_font_dest.h/2;

    title = TextureManager::LoadTextureFont("../fonts/The_Wild_Breath_of_Zelda.otf", 100, 0, 0, 0, "Titre du jeu");
//    title_src.x = title_src.y = 0;
//    title_dest.w = 400;
//    title_dest.h = 120;
//    title_dest.x = size.x/2-title_dest.w/2;
//    title_dest.y = 50;

    position = 0;
//    menuSprite = NULL; // set pointer to NULL;
//    menuSprite = TextureManager::LoadTextureImg("../images/menu/menu_background_new_002.png");
//    std::cout << title << std::endl;
    printf("MenuState Init Successful\n");
}

std::vector<SDL_Rect> MenuState::MoveSelector()
{
    std::vector<SDL_Rect> vecOfRec;
    SDL_Rect play;
    play.x = MenuState::play_buttonPosition().x - 3;
    play.y = MenuState::play_buttonPosition().y - 3;
    play.w = MenuState::play_buttonPosition().w + 6;
    play.h = MenuState::play_buttonPosition().h + 6;
    vecOfRec.push_back(play);
    SDL_Rect option;
    option.x = MenuState::option_buttonPosition().x - 3;
    option.y = MenuState::option_buttonPosition().y - 3;
    option.w = MenuState::option_buttonPosition().w + 6;
    option.h = MenuState::option_buttonPosition().h + 6;
    vecOfRec.push_back(option);
    SDL_Rect quit;
    quit.x = MenuState::quit_buttonPosition().x - 3;
    quit.y = MenuState::quit_buttonPosition().y - 3;
    quit.w = MenuState::quit_buttonPosition().w + 6;
    quit.h = MenuState::quit_buttonPosition().h + 6;
    vecOfRec.push_back(quit);
//    std::cout << vecOfStr[0] << std::endl;
    return vecOfRec;
}


void MenuState::Clean()
{
    Mix_CloseAudio();
    printf("MenuState Clean Successful\n");
}

void MenuState::Pause()
{
    printf("MenuState Paused\n");
}

void MenuState::Resume()
{
    printf("MenuState Resumed\n");
}

void MenuState::HandleEvents(Game* game) //put our exit function back in business we can now quit with cross in corner.
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                game->Quit();
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                    case SDL_BUTTON_LEFT:
    //                    SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was pressed!", window);
                        if ((event.motion.x > MenuState::quit_buttonPosition().x)
                                && (event.motion.x < (MenuState::quit_buttonPosition().x + MenuState::quit_buttonPosition().w))
                                && (event.motion.y > MenuState::quit_buttonPosition().y)
                                && (event.motion.y < (MenuState::quit_buttonPosition().y + MenuState::quit_buttonPosition().h)))
                        {
                            MenuState::position = 2;
                            MenuState::MoveSelector()[MenuState::position];
                            game->Quit();
                            break;
                        }
                        else if ((event.motion.x > MenuState::option_buttonPosition().x)
                                 && (event.motion.x < (MenuState::option_buttonPosition().x + MenuState::option_buttonPosition().w))
                                 && (event.motion.y > MenuState::option_buttonPosition().y)
                                 && (event.motion.y < (MenuState::option_buttonPosition().y + MenuState::option_buttonPosition().h)))
                        {
                            MenuState::position = 1;
                            MenuState::MoveSelector()[MenuState::position];
                            game->PushState(OptionState::Instance());
                            break;
                        }
                        else if ((event.motion.x > MenuState::play_buttonPosition().x)
                                 && (event.motion.x < (MenuState::play_buttonPosition().x + MenuState::play_buttonPosition().w))
                                 && (event.motion.y > MenuState::play_buttonPosition().y)
                                 && (event.motion.y < (MenuState::play_buttonPosition().y + MenuState::play_buttonPosition().h)))
                        {
                            MenuState::position = 0;
                            MenuState::MoveSelector()[MenuState::position];
                            std::cout << "play" << std::endl;
                            break;
                        }
                        break;
                    case SDL_BUTTON_RIGHT:
    //                    SDL_ShowSimpleMessageBox(0, "Mouse", "Right button was pressed!", window);
                        break;
                    default:
    //                    SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", window);
                        break;
                }
                break;
            case SDL_MOUSEMOTION:
            {
                int mouseX = event.motion.x;
                int mouseY = event.motion.y;

                std::stringstream ss;
                ss << "X: " << mouseX << " Y: " << mouseY;

                SDL_SetWindowTitle(game->GetWindow(), ss.str().c_str());
                break;
            }
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        game->Quit();
                        break;
                    case SDLK_UP:
            //                    std::cout << "up" << std::endl;
                        if (MenuState::position > 0)
                        {
                            MenuState::position -= 1;
                            MenuState::MoveSelector()[MenuState::position];
                        }
            //                    isRunning = false;
                        break;
                    case SDLK_DOWN:
            //                    std::cout << "down" << std::endl;
                        if (MenuState::position < 2)
                        {
                            MenuState::position += 1;
                            MenuState::MoveSelector()[MenuState::position];
                        }
            //                    isRunning = false;
                        break;
                    case SDLK_RETURN:
                        switch (MenuState::position)
                        {
                            case 0:
                                std::cout << "play" << std::endl;
                                break;

                            case 1:
                                game->PushState(OptionState::Instance());
                                break;
                            case 2:
                                game->Quit();
                                break;
                        }
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

void MenuState::Update(Game* game)
{
}

void MenuState::Draw(Game* game)
{
    SDL_RenderClear(game->m_pRenderer);

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    int texW = 0;
    int texH = 0;

//    std::cout << "pwet" << std::endl;
    TextureManager::DrawBackground(game->m_pRenderer, background);

    SDL_QueryTexture(quit_button_font, NULL, NULL, &texW, &texH);
    quit_button_src.x = quit_button_src.y = 0;
    quit_button_dest.w = 300;
    quit_button_font_dest.w = texW;//quit_button_dest.w*2/3;
    quit_button_dest.h = 50;
    quit_button_font_dest.h = texH;//quit_button_dest.h*2/3;
    quit_button_dest.x = size.x/2 - quit_button_dest.w/2;
    quit_button_font_dest.x = size.x/2 - quit_button_font_dest.w/2;
    quit_button_dest.y = size.y*5/8 - quit_button_dest.h/2;
    quit_button_font_dest.y = size.y*5/8 - quit_button_font_dest.h/2;
    TextureManager::Draw(game->m_pRenderer, quit_button, quit_button_src, quit_button_dest);
    TextureManager::Draw(game->m_pRenderer, quit_button_font, quit_button_src, quit_button_font_dest);

    SDL_QueryTexture(play_button_font, NULL, NULL, &texW, &texH);
    play_button_src.x = play_button_src.y = 0;
    play_button_dest.w = 300;
    play_button_font_dest.w = texW;//play_button_dest.w*2/3;
    play_button_dest.h = 50;
    play_button_font_dest.h = texH;//play_button_dest.h*2/3;
    play_button_dest.x = size.x/2 - play_button_dest.w/2;
    play_button_font_dest.x = size.x/2 - play_button_font_dest.w/2;
    play_button_dest.y = size.y*3/8 - play_button_dest.h/2;
    play_button_font_dest.y = size.y*3/8 - play_button_font_dest.h/2;
    TextureManager::Draw(game->m_pRenderer, play_button, play_button_src, play_button_dest);
    TextureManager::Draw(game->m_pRenderer, play_button_font, play_button_src, play_button_font_dest);

    SDL_QueryTexture(option_button_font, NULL, NULL, &texW, &texH);
    option_button_src.x = option_button_src.y = 0;
    option_button_dest.w = 300;
    option_button_font_dest.w = texW;//option_button_dest.w*2/3;
    option_button_dest.h = 50;
    option_button_font_dest.h = texH;//option_button_dest.h*2/3;
    option_button_dest.x = size.x/2 - option_button_dest.w/2;
    option_button_font_dest.x = size.x/2 - option_button_font_dest.w/2;
    option_button_dest.y = size.y*4/8 - option_button_dest.h/2;
    option_button_font_dest.y = size.y*4/8 - option_button_font_dest.h/2;
    TextureManager::Draw(game->m_pRenderer, option_button, option_button_src, option_button_dest);
    TextureManager::Draw(game->m_pRenderer, option_button_font, option_button_src, option_button_font_dest);

    SDL_QueryTexture(title, NULL, NULL, &texW, &texH);
    title_src.x = title_src.y = 0;
    title_dest.w = texW;//400;
    title_dest.h = texH;//120;
    title_dest.x = size.x/2-title_dest.w/2;
    title_dest.y = 100;
    TextureManager::Draw(game->m_pRenderer, title, title_src, title_dest);

    selector_src.x = selector_src.y = 0;
    TextureManager::Draw(game->m_pRenderer, selector, selector_src, MoveSelector()[position]);

//    TextureManager::DrawBackground(game->m_pRenderer, menuSprite);

    SDL_RenderPresent(game->m_pRenderer);
}
