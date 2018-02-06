#ifndef CastleState_H
#define CastleState_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

class CastleState : public GameState
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
    static CastleState* Instance() { return &m_CastleState; }

protected:
    CastleState() {}

    SDL_Texture* next, * choice;
    SDL_Rect next_dest;

    SDL_Texture* background;
    SDL_Rect background_src, background_dest;

    SDL_Texture* background_text;
    SDL_Rect background_text_src, background_text_dest;

    SDL_Texture* aragorn, * aragorn_fight, * aragorn_fight_injury;
    SDL_Rect aragorn_src, aragorn_dest, aragorn_fight_src, aragorn_fight_dest, aragorn_fight_injury_src, aragorn_fight_injury_dest;

    SDL_Texture* ciri;
    SDL_Rect ciri_src, ciri_dest;

    SDL_Texture* geralt;
    SDL_Rect geralt_src, geralt_dest;

    SDL_Texture* king;
    SDL_Rect king_src, king_dest;

    SDL_Texture* text1, * text2, * text3, * text4;
    SDL_Rect text_src, text_dest;

    SDL_Rect size;

private:
    static CastleState m_CastleState;

    SDL_Texture* menuSprite;

};

#endif // CastleState_H
