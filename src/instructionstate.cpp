#include <stdio.h>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "game.h"
#include "instructionstate.h"
#include "texturemanager.h"

InstructionState InstructionState::m_InstructionState;

void InstructionState::Init()
{
    SDL_GetRendererOutputSize(Game::m_pRenderer, &size.x, &size.y);

    background = TextureManager::LoadTextureImg("../images/menu/menu_background_new_002.png");

    title = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 60, 0, 0, 0, "Instructions");

    instructions = TextureManager::LoadTextureFontInstruction("Vous allez incarner un personnage dont vous êtes le maitre des décisions.\n"
                                                              "Chacune d'entre elles pourra avoir des répercussions sur la suite de l'histoire.\n"
                                                              "Attention!\n"
                                                              "Les évènements sont aléatoires, les mêmes choix peuvent amener à différentes conséquences.\n"
                                                              "Si vous voulez découvrir différentes issues, n'hésitez pas à le recommencer avec des choix différents (ou pas).\n"
                                                              "Bonne chance ! Que la force soit avec vous (et avec votre esprit)!",
                                                              size);

    back = TextureManager::LoadTextureImg("../images/menu/button.png");
    back_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 35, 255, 255, 255, "Retour");

    selector = TextureManager::LoadTextureImg("../images/menu/menu_selector.png");

//	background = Sprite::Load("paused.bmp");
    printf("PauseState Init Successful\n");
}

void InstructionState::Clean()
{
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(instructions);
    SDL_DestroyTexture(back);
    SDL_DestroyTexture(back_font);
    SDL_DestroyTexture(title);
    SDL_DestroyTexture(selector);
    printf("InstructionState Clean Successful\n");
}

void InstructionState::Resume(){}

void InstructionState::Pause() {}

void InstructionState::HandleEvents(Game* game)
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
                        if ((event.motion.x > InstructionState::back_buttonPosition().x)
                                 && (event.motion.x < (InstructionState::back_buttonPosition().x + InstructionState::back_buttonPosition().w))
                                 && (event.motion.y > InstructionState::back_buttonPosition().y)
                                 && (event.motion.y < (InstructionState::back_buttonPosition().y + InstructionState::back_buttonPosition().h)))
                        {
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

                    case SDLK_RETURN:
                        game->PopState();
                        break;
                }
        }
    }
}

void InstructionState::Update(Game* game)
{
}

void InstructionState::Draw(Game* game)
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

    TextureManager::DrawFontInstruction(game->m_pRenderer, instructions, instructions_dest, size);

    SDL_QueryTexture(back_font, NULL, NULL, &texW, &texH);
    back_src.x = back_src.y = 0;
    back_dest.w = 300;
    back_font_dest.w = texW;//back_dest.w*1/2;
    back_dest.h = 50;
    back_font_dest.h = texH;//back_dest.h*2/3;
    back_dest.x = size.x/2 - back_dest.w/2;
    back_font_dest.x = size.x/2 - back_font_dest.w/2;
    back_dest.y = size.y*12/15 - back_dest.h/2;
    back_font_dest.y = size.y*12/15 - back_font_dest.h/2;
    TextureManager::Draw(game->m_pRenderer, back, back_src, back_dest);
    TextureManager::Draw(game->m_pRenderer, back_font, back_font_src, back_font_dest);

    selector_src.x = selector_src.y = 0;
    selector_dest.x = InstructionState::back_buttonPosition().x - 3;
    selector_dest.y = InstructionState::back_buttonPosition().y - 3;
    selector_dest.w = InstructionState::back_buttonPosition().w + 6;
    selector_dest.h = InstructionState::back_buttonPosition().h + 6;
    TextureManager::Draw(game->m_pRenderer, selector, selector_src, selector_dest);

    SDL_RenderPresent(game->m_pRenderer);
}

