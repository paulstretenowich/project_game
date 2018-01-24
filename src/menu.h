#ifndef MENU_H
#define MENU_H

#include "game.h"

class Menu
{
public:
    Menu();

    void Draw();

    SDL_Rect quit_buttonPosition() { return quit_button_dest; }
//    SDL_Rect GetPosition(SDL_Rect *rect);

protected:
SDL_Texture* background;

SDL_Texture* title;
SDL_Rect title_src, title_dest;

SDL_Texture* quit_button, * quit_button_font;
SDL_Rect quit_button_src, quit_button_dest, quit_button_font_src, quit_button_font_dest;

SDL_Texture* play_button, * play_button_font;
SDL_Rect play_button_src, play_button_dest, play_button_font_src, play_button_font_dest;

SDL_Texture* option_button, * option_button_font;
SDL_Rect option_button_src, option_button_dest, option_button_font_src, option_button_font_dest;

SDL_Rect size;

};

#endif // MENU_H
