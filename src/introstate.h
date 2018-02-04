#ifndef INTROSTATE_H
#define INTROSTATE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

class IntroState : public GameState
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
    static IntroState* Instance() { return &m_IntroState; }

protected:
    IntroState() {}

    SDL_Texture* background;
    SDL_Rect background_src, background_dest;

    SDL_Texture* background_text;
    SDL_Rect background_text_src, background_text_dest;

    SDL_Texture* aragorn;
    SDL_Rect aragorn_src, aragorn_dest;

    SDL_Texture* text1, * text2;
    SDL_Rect text1_src, text1_dest, text2_src, text2_dest;

    SDL_Rect size;

private:
    static IntroState m_IntroState;

    SDL_Texture* menuSprite;

};

#endif // INTROSTATE_H
