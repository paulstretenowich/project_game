#ifndef GAME_H
#define GAME_H

#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class GameState; // make sure this class knows about the GameState class.

class Game
{
public:
    Game();
    ~Game();

    void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

//    void handleEvents();
//    void update();
//    void render();
//    void clean();

//    bool running() { return isRunning; }

//    static void AddTile(int srcX, int srcY, int xpos, int ypos);
//    static SDL_Event event;
    static SDL_Renderer *m_pRenderer;
//    static std::vector<ColliderComponent*> colliders;

    void ChangeState(GameState* state);
    void PushState(GameState* state);
    void PopState();

    void HandleEvents();

    void Update();

    void Draw();

    void Clean();

    bool Running() { return m_bRunning; }
    void Quit() { m_bRunning = false; }

    bool FullscreenMode() { return m_bFullscreen; }
    void FullscreenOn() { m_bFullscreen = true; }
    void FullscreenOff() { m_bFullscreen = false; }

    SDL_Window* GetWindow() { return m_pWindow; }


protected:
    // the stack of states
    std::vector<GameState*> states;

    SDL_Window* m_pWindow;
//    SDL_Renderer* m_pRenderer;

    bool m_bFullscreen;
    bool m_bRunning;

//    int cnt = 0;
//    bool isRunning;
//    SDL_Window *window;
//    SDL_Renderer *renderer;
};

#endif // GAME_H
