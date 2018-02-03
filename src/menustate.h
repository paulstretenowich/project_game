#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

class MenuState : public GameState
{
public:
    void Init();
    void Clean();

    void Pause();
    void Resume();

    void HandleEvents(Game* game);
    void Update(Game* game);
    void Draw(Game* game);

    SDL_Rect quit_buttonPosition() { return quit_button_dest; }
    SDL_Rect play_buttonPosition() { return play_button_dest; }
    SDL_Rect option_buttonPosition() { return option_button_dest; }

    std::vector<SDL_Rect> MoveSelector();

    int position;

    // Implement Singleton Pattern
    static MenuState* Instance() { return &m_MenuState; }

protected:
    MenuState() {}

    SDL_Texture* background;

    SDL_Texture* title;
    SDL_Rect title_src, title_dest;

    SDL_Texture* quit_button, * quit_button_font;
    SDL_Rect quit_button_src, quit_button_dest, quit_button_font_src, quit_button_font_dest;

    SDL_Texture* selector;
    SDL_Rect selector_src, selector_dest;

    SDL_Texture* play_button, * play_button_font;
    SDL_Rect play_button_src, play_button_dest, play_button_font_src, play_button_font_dest;

    SDL_Texture* option_button, * option_button_font;
    SDL_Rect option_button_src, option_button_dest, option_button_font_src, option_button_font_dest;

    SDL_Rect size;

private:
    static MenuState m_MenuState;

    SDL_Texture* menuSprite;

};

#endif // MENUSTATE_H
