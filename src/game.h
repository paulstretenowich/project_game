#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

//    static void AddTile(int srcX, int srcY, int xpos, int ypos);
    static SDL_Event event;
    static SDL_Renderer *renderer;
//    static std::vector<ColliderComponent*> colliders;

private:
//    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
//    SDL_Renderer *renderer;
};

#endif // GAME_H
