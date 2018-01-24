#include <iostream>
#include <cstdlib>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "menu.h"
#include "game.h"
#include "texturemanager.h"

Menu::Menu()
{
    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
    Mix_Music* background_menu_music = Mix_LoadMUS("../music/menu_music.ogg");
    Mix_PlayMusic(background_menu_music, -1);

    SDL_GetRendererOutputSize(Game::renderer, &size.x, &size.y);

    background = TextureManager::LoadTextureImg("../images/menu/menu_background_new_002.png");

    quit_button = TextureManager::LoadTextureImg("../images/menu/button.png");
    quit_button_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 100, 255, 255, 255, "Quitter");
    quit_button_src.x = quit_button_src.y = 0;
    quit_button_dest.w = 300;
    quit_button_font_dest.w = quit_button_dest.w*2/3;
    quit_button_dest.h = 50;
    quit_button_font_dest.h = quit_button_dest.h*2/3;
    quit_button_dest.x = size.x/2 - quit_button_dest.w/2;
    quit_button_font_dest.x = size.x/2 - quit_button_font_dest.w/2;
    quit_button_dest.y = size.y*5/8 - quit_button_dest.h/2;
    quit_button_font_dest.y = size.y*5/8 - quit_button_font_dest.h/2;

    play_button = TextureManager::LoadTextureImg("../images/menu/button.png");
    play_button_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 100, 255, 255, 255, "Jouer");
    play_button_src.x = play_button_src.y = 0;
    play_button_dest.w = 300;
    play_button_font_dest.w = play_button_dest.w*2/3;
    play_button_dest.h = 50;
    play_button_font_dest.h = play_button_dest.h*2/3;
    play_button_dest.x = size.x/2 - play_button_dest.w/2;
    play_button_font_dest.x = size.x/2 - play_button_font_dest.w/2;
    play_button_dest.y = size.y*3/8 - play_button_dest.h/2;
    play_button_font_dest.y = size.y*3/8 - play_button_font_dest.h/2;

    option_button = TextureManager::LoadTextureImg("../images/menu/button.png");
    option_button_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 100, 255, 255, 255, "Options");
    option_button_src.x = option_button_src.y = 0;
    option_button_dest.w = 300;
    option_button_font_dest.w = option_button_dest.w*2/3;
    option_button_dest.h = 50;
    option_button_font_dest.h = option_button_dest.h*2/3;
    option_button_dest.x = size.x/2 - option_button_dest.w/2;
    option_button_font_dest.x = size.x/2 - option_button_font_dest.w/2;
    option_button_dest.y = size.y*4/8 - option_button_dest.h/2;
    option_button_font_dest.y = size.y*4/8 - option_button_font_dest.h/2;

    title = TextureManager::LoadTextureFont("../fonts/The_Wild_Breath_of_Zelda.otf", 100, 0, 0, 0, "Titre du jeu");
    title_src.x = title_src.y = 0;
    title_dest.w = 400;
    title_dest.h = 120;
    title_dest.x = size.x/2-title_dest.w/2;
    title_dest.y = 50;
}

//SDL_Rect Menu::GetPosition(SDL_Rect *rect)
//{
//    return rect
//}

void Menu::Draw()
{
    TextureManager::DrawBackground(background);

    TextureManager::Draw(quit_button, quit_button_src, quit_button_dest);
    TextureManager::Draw(quit_button_font, quit_button_src, quit_button_font_dest);

    TextureManager::Draw(play_button, play_button_src, play_button_dest);
    TextureManager::Draw(play_button_font, play_button_src, play_button_font_dest);

    TextureManager::Draw(option_button, option_button_src, option_button_dest);
    TextureManager::Draw(option_button_font, option_button_src, option_button_font_dest);

    TextureManager::Draw(title, title_src, title_dest);
}
