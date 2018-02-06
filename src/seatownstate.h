#ifndef SeaTownState_H
#define SeaTownState_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

class SeaTownState : public GameState
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
    static SeaTownState* Instance() { return &m_SeaTownState; }

protected:
    SeaTownState() {}

    SDL_Texture* next, * choice;
    SDL_Rect next_dest;

    SDL_Texture* background_tavern, * background_outside;
    SDL_Rect background_src, background_dest;

    SDL_Texture* background_text;
    SDL_Rect background_text_src, background_text_dest;

    SDL_Texture* aragorn;
    SDL_Rect aragorn_src, aragorn_dest;

    SDL_Texture* ogma;
    SDL_Rect ogma_src, ogma_dest;

    SDL_Texture* text1, * text2, * text3, * text4, * text5, * text6;
    SDL_Rect text_src, text_dest;

    SDL_Rect size;

private:
    static SeaTownState m_SeaTownState;

    SDL_Texture* menuSprite;

};

#endif // SeaTownState_H
