#include <stdio.h>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "game.h"
#include "optionstate.h"
#include "texturemanager.h"

OptionState OptionState::m_OptionState;

void OptionState::Init()
{

    background = TextureManager::LoadTextureImg("../images/menu/menu_background_new_002.png");

    title = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 60, 0, 0, 0, "Options");

    fullscreen_off = TextureManager::LoadTextureImg("../images/menu/button.png");
    fullscreen_off_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 35, 255, 255, 255, "Plein écran");

    fullscreen_on = TextureManager::LoadTextureImg("../images/menu/button.png");
    fullscreen_on_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 35, 255, 255, 255, "Fenêtre");

    back = TextureManager::LoadTextureImg("../images/menu/button.png");
    back_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 35, 255, 255, 255, "Retour");

    selector = TextureManager::LoadTextureImg("../images/menu/menu_selector.png");

    position = 0;

//	background = Sprite::Load("paused.bmp");
    printf("PauseState Init Successful\n");
}

std::vector<SDL_Rect> OptionState::MoveSelector()
{
//    Game* game;
    std::vector<SDL_Rect> vecOfRec;
    SDL_Rect fullscreen;

    fullscreen.x = OptionState::fullscreen_buttonPosition().x - 3;
    fullscreen.y = OptionState::fullscreen_buttonPosition().y - 3;
    fullscreen.w = OptionState::fullscreen_buttonPosition().w + 6;
    fullscreen.h = OptionState::fullscreen_buttonPosition().h + 6;

    vecOfRec.push_back(fullscreen);
    SDL_Rect back;
    back.x = OptionState::back_buttonPosition().x - 3;
    back.y = OptionState::back_buttonPosition().y - 3;
    back.w = OptionState::back_buttonPosition().w + 6;
    back.h = OptionState::back_buttonPosition().h + 6;
    vecOfRec.push_back(back);
//    std::cout << vecOfStr[0] << std::endl;
    return vecOfRec;
}

void OptionState::Clean()
{
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(fullscreen_off);
    SDL_DestroyTexture(fullscreen_off_font);
    SDL_DestroyTexture(fullscreen_on);
    SDL_DestroyTexture(fullscreen_on_font);
    SDL_DestroyTexture(back);
    SDL_DestroyTexture(back_font);
    SDL_DestroyTexture(title);
    SDL_DestroyTexture(selector);
    printf("OptionState Clean Successful\n");
}

void OptionState::Resume(){}

void OptionState::Pause() {}

void OptionState::HandleEvents(Game* game)
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
                    if ((event.motion.x > OptionState::fullscreen_buttonPosition().x)
                            && (event.motion.x < (OptionState::fullscreen_buttonPosition().x + OptionState::fullscreen_buttonPosition().w))
                            && (event.motion.y > OptionState::fullscreen_buttonPosition().y)
                            && (event.motion.y < (OptionState::fullscreen_buttonPosition().y + OptionState::fullscreen_buttonPosition().h)))
                    {
                        OptionState::position = 0;
                        OptionState::MoveSelector()[OptionState::position];
                        if (game->FullscreenMode())
                        {
                            std::cout << "on" << std::endl;
                            game->FullscreenOff();
                            SDL_SetWindowFullscreen(game->GetWindow(), 0);
    //                            game->Init("StateManager", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, false);
                        }
                        else if (!game->FullscreenMode())
                        {
                            std::cout << "off" << std::endl;
                            game->FullscreenOn();
                            SDL_SetWindowFullscreen(game->GetWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);
    //                                    std::cout << OptionState::MoveSelector()[OptionState::position].x << std::endl;
    //                            game->Init("StateManager", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, true);
                        }
                        break;
                    }
                    else if ((event.motion.x > OptionState::back_buttonPosition().x)
                             && (event.motion.x < (OptionState::back_buttonPosition().x + OptionState::back_buttonPosition().w))
                             && (event.motion.y > OptionState::back_buttonPosition().y)
                             && (event.motion.y < (OptionState::back_buttonPosition().y + OptionState::back_buttonPosition().h)))
                    {
                        OptionState::position = 1;
                        OptionState::MoveSelector()[OptionState::position];
                        game->PopState();
                        break;
                    }
                    break;
            }

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        game->Quit();
                        break;

                    case SDLK_BACKSPACE:
                        game->PopState();
                        break;

                    case SDLK_UP:
            //                    std::cout << "up" << std::endl;
                        if (OptionState::position > 0)
                        {
                            OptionState::position -= 1;
                            OptionState::MoveSelector()[OptionState::position];
//                            std::cout << OptionState::MoveSelector()[OptionState::position].x << std::endl;
                        }
            //                    isRunning = false;
                        break;
                    case SDLK_DOWN:
            //                    std::cout << "down" << std::endl;
                        if (OptionState::position < 1)
                        {
                            OptionState::position += 1;
                            OptionState::MoveSelector()[OptionState::position];
                        }
            //                    isRunning = false;
                        break;

                    case SDLK_RETURN:
                        switch (OptionState::position)
                        {
                            case 0:
                                if (game->FullscreenMode())
                                {
                                    std::cout << "on" << std::endl;
                                    game->FullscreenOff();
                                    SDL_SetWindowFullscreen(game->GetWindow(), 0);
        //                            game->Init("StateManager", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, false);
                                }
                                else if (!game->FullscreenMode())
                                {
                                    std::cout << "off" << std::endl;
                                    game->FullscreenOn();
                                    SDL_SetWindowFullscreen(game->GetWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);
//                                    std::cout << OptionState::MoveSelector()[OptionState::position].x << std::endl;
        //                            game->Init("StateManager", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, true);
                                }
                                break;
                            case 1:
                                game->PopState();
                                break;
                        }
                }
        }
    }
}

void OptionState::Update(Game* game)
{
}

void OptionState::Draw(Game* game)
{
    SDL_RenderClear(game->m_pRenderer);

    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    int texW = 0;
    int texH = 0;

//    std::cout << "pwet" << std::endl;
    TextureManager::DrawBackground(game->m_pRenderer, background);

    SDL_QueryTexture(title, NULL, NULL, &texW, &texH);
    title_src.x = title_src.y = 0;
    title_dest.w = texW;//400;
    title_dest.h = texH;//120;
    title_dest.x = size.x/2-title_dest.w/2;
    title_dest.y = 100;
    TextureManager::Draw(game->m_pRenderer, title, title_src, title_dest);

    fullscreen_button_src.x = fullscreen_button_src.y = 0;
    fullscreen_button_dest.w = 300;
    fullscreen_button_dest.h = 50;
    fullscreen_button_dest.x = size.x/2 - fullscreen_button_dest.w/2;
    fullscreen_button_dest.y = size.y*7/16 - fullscreen_button_dest.h/2;

    if (game->FullscreenMode())
    {
        SDL_QueryTexture(fullscreen_on_font, NULL, NULL, &texW, &texH);
//        std::cout << "on" << std::endl;
//        fullscreen_on_src.x = fullscreen_on_src.y = 0;
//        fullscreen_on_dest.w = 300;
        fullscreen_on_font_dest.w = texW;//fullscreen_button_dest.w*1/2;
//        fullscreen_on_dest.h = 50;
        fullscreen_on_font_dest.h = texH;//fullscreen_button_dest.h*2/3;
//        fullscreen_on_dest.x = size.x/2 - fullscreen_on_dest.w/2;
        fullscreen_on_font_dest.x = size.x/2 - fullscreen_on_font_dest.w/2;
//        fullscreen_on_dest.y = size.y*7/16 - fullscreen_on_dest.h/2;
        fullscreen_on_font_dest.y = size.y*7/16 - fullscreen_on_font_dest.h/2;
        TextureManager::Draw(game->m_pRenderer, fullscreen_on, fullscreen_button_src, fullscreen_button_dest);
        TextureManager::Draw(game->m_pRenderer, fullscreen_on_font, fullscreen_on_font_src, fullscreen_on_font_dest);

    }
    else
    {
        SDL_QueryTexture(fullscreen_off_font, NULL, NULL, &texW, &texH);
//        std::cout << "off" << std::endl;
//        fullscreen_off_src.x = fullscreen_off_src.y = 0;
//        fullscreen_off_dest.w = 300;
        fullscreen_off_font_dest.w = texW;//fullscreen_button_dest.w*2/3;
//        fullscreen_off_dest.h = 50;
        fullscreen_off_font_dest.h = texH;//fullscreen_button_dest.h*2/3;
//        fullscreen_off_dest.x = size.x/2 - fullscreen_off_dest.w/2;
        fullscreen_off_font_dest.x = size.x/2 - fullscreen_off_font_dest.w/2;
//        fullscreen_off_dest.y = size.y*7/16 - fullscreen_off_dest.h/2;
        fullscreen_off_font_dest.y = size.y*7/16 - fullscreen_off_font_dest.h/2;
        TextureManager::Draw(game->m_pRenderer, fullscreen_off, fullscreen_button_src, fullscreen_button_dest);
        TextureManager::Draw(game->m_pRenderer, fullscreen_off_font, fullscreen_off_font_src, fullscreen_off_font_dest);
    }

    SDL_QueryTexture(back_font, NULL, NULL, &texW, &texH);
    back_src.x = back_src.y = 0;
    back_dest.w = 300;
    back_font_dest.w = texW;//back_dest.w*1/2;
    back_dest.h = 50;
    back_font_dest.h = texH;//back_dest.h*2/3;
    back_dest.x = size.x/2 - back_dest.w/2;
    back_font_dest.x = size.x/2 - back_font_dest.w/2;
    back_dest.y = size.y*9/16 - back_dest.h/2;
    back_font_dest.y = size.y*9/16 - back_font_dest.h/2;
    TextureManager::Draw(game->m_pRenderer, back, back_src, back_dest);
    TextureManager::Draw(game->m_pRenderer, back_font, back_font_src, back_font_dest);

    selector_src.x = selector_src.y = 0;
    TextureManager::Draw(game->m_pRenderer, selector, selector_src, OptionState::MoveSelector()[position]);

    SDL_RenderPresent(game->m_pRenderer);
}

