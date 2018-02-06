#ifndef EndState_H
#define EndState_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamestate.h"

class EndState : public GameState
{
public:
    void Init();
    void Clean();

    void Pause();
    void Resume();

    void HandleEvents(Game* game);
    void Update(Game* game);
    void Draw(Game* game);

    // Implement Singleton Pattern
    static EndState* Instance() { return &m_EndState; }

protected:
    EndState() {}

    SDL_Texture* background;
    SDL_Rect background_src, background_dest;

    SDL_Texture* background_text1, * background_text2;
    SDL_Rect background_text_src1, background_text_dest1, background_text_src2, background_text_dest2;

    SDL_Rect size;

private:
    static EndState m_EndState;

    SDL_Texture* menuSprite;

};

#endif // EndState_H
