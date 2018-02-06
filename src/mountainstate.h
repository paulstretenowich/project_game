#ifndef MountainState_H
#define MountainState_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

class MountainState : public GameState
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
    static MountainState* Instance() { return &m_MountainState; }

protected:
    MountainState() {}

    SDL_Texture* next, * choice;
    SDL_Rect next_dest;

    SDL_Texture* background_mountain, * background_volcano, * background_forest;
    SDL_Rect background_src, background_dest;

    SDL_Texture* background_text;
    SDL_Rect background_text_src, background_text_dest;

    SDL_Texture* aragorn, * aragorn_fight;
    SDL_Rect aragorn_src, aragorn_dest, aragorn_fight_src, aragorn_fight_dest;

    SDL_Texture* text1, * text2, * text3, * text4, * text5, * text6, * text7;
    SDL_Rect text_src, text_dest;

    SDL_Rect size;

private:
    static MountainState m_MountainState;

    SDL_Texture* menuSprite;

};

#endif // MountainState_H
