#ifndef OPTIONSTATE_H
#define OPTIONSTATE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

class OptionState : public GameState
{
public:
    void Init();
    void Clean();

    void Pause();
    void Resume();

    void HandleEvents(Game* game);
    void Update(Game* game);
    void Draw(Game* game);

    SDL_Rect fullscreen_buttonPosition() { return fullscreen_button_dest; }
//    SDL_Rect fullscreen_off_buttonPosition() { return fullscreen_off_dest; }
//    {
//        Game* game;
//        if (game->FullscreenMode())
//        {
////            std::cout << "on_dest" << std::endl;
//            return fullscreen_on_dest;
//        }
//        else// if (!game->FullscreenMode())
//        {
////            std::cout << "off_dest" << std::endl;
//            return fullscreen_off_dest;
//        }
//    }

    SDL_Rect back_buttonPosition() { return back_dest; }

    int position;

    std::vector<SDL_Rect> MoveSelector();

    // Implement Singleton Pattern
    static OptionState* Instance() { return &m_OptionState; }

protected:
    OptionState() {}

    SDL_Rect size;

    SDL_Texture* background;

    SDL_Texture* selector;
    SDL_Rect selector_src, selector_dest;

    SDL_Texture* title;
    SDL_Rect title_src, title_dest;

    SDL_Texture* fullscreen_on, * fullscreen_on_font;
    SDL_Texture* fullscreen_off, * fullscreen_off_font;
    SDL_Rect fullscreen_button_src, fullscreen_button_dest, fullscreen_on_font_src, fullscreen_on_font_dest, fullscreen_off_font_src, fullscreen_off_font_dest;
//    SDL_Texture* fullscreen_off, * fullscreen_off_font;
//    SDL_Rect fullscreen_off_src, fullscreen_off_dest, fullscreen_off_font_src, fullscreen_off_font_dest;

    SDL_Texture* back, * back_font;
    SDL_Rect back_src, back_dest, back_font_src, back_font_dest;

private:
    static OptionState m_OptionState;

};

#endif // OPTIONSTATE_H
