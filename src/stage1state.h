#ifndef STAGE1STATE_H
#define STAGE1STATE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

class Stage1State : public GameState
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
    static Stage1State* Instance() { return &m_Stage1State; }

protected:
    Stage1State() {}

    SDL_Texture* next, * choice;
    SDL_Rect next_dest;

    SDL_Texture* background;
    SDL_Rect background_src, background_dest;

    SDL_Texture* background_text;
    SDL_Rect background_text_src, background_text_dest;

    SDL_Texture* aragorn, * aragorn_fight;
    SDL_Rect aragorn_src, aragorn_dest, aragorn_fight_src, aragorn_fight_dest;

    SDL_Texture* ciri, * ciri_fight;
    SDL_Rect ciri_src, ciri_dest, ciri_fight_src, ciri_fight_dest;

    SDL_Texture* text1, * text2, * text3, * text4, * text5, * text6, * text7;
    SDL_Rect text_src, text_dest;

    SDL_Rect size;

private:
    static Stage1State m_Stage1State;

    SDL_Texture* menuSprite;

};

#endif // STAGE1STATE_H
