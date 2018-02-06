#ifndef SeaState_H
#define SeaState_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

class SeaState : public GameState
{
public:
    void Init();
    void Clean();

    void Pause();
    void Resume();

    void HandleEvents(Game* game);
    void Update(Game* game);
    void Draw(Game* game);

    std::vector<SDL_Texture*> ChangeText();

    int text_selector;

    // Implement Singleton Pattern
    static SeaState* Instance() { return &m_SeaState; }

protected:
    SeaState() {}

    SDL_Texture* next, * choice;
    SDL_Rect next_dest;

    SDL_Texture* background;
    SDL_Rect background_src, background_dest;

    SDL_Texture* background_text;
    SDL_Rect background_text_src, background_text_dest;

    SDL_Texture* aragorn, * aragorn_fight;
    SDL_Rect aragorn_src, aragorn_dest, aragorn_fight_src, aragorn_fight_dest;

    SDL_Texture* hector;
    SDL_Rect hector_src, hector_dest;

    SDL_Texture* ciri;
    SDL_Rect ciri_src, ciri_dest;

    SDL_Texture* text1, * text2, * text3, * text4, * text5, * text6, * text7, * text8, * text9, * text10, * text11, * text12, * text13, * text14, * text15;
    SDL_Rect text_src, text_dest;

    SDL_Rect size;

private:
    static SeaState m_SeaState;

    SDL_Texture* menuSprite;

};

#endif // SeaState_H
