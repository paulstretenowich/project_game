#ifndef InstructionState_H
#define InstructionState_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

class InstructionState : public GameState
{
public:
    void Init();
    void Clean();

    void Pause();
    void Resume();

    void HandleEvents(Game* game);
    void Update(Game* game);
    void Draw(Game* game);

    SDL_Rect back_buttonPosition() { return back_dest; }

    // Implement Singleton Pattern
    static InstructionState* Instance() { return &m_InstructionState; }

protected:
    InstructionState() {}

    SDL_Rect size;

    SDL_Texture* background;

    SDL_Texture* selector;
    SDL_Rect selector_src, selector_dest;

    SDL_Texture* title;
    SDL_Rect title_src, title_dest;

    SDL_Texture* instructions;
    SDL_Rect instructions_src, instructions_dest;

    SDL_Texture* back, * back_font;
    SDL_Rect back_src, back_dest, back_font_src, back_font_dest;

private:
    static InstructionState m_InstructionState;

};

#endif // InstructionState_H
