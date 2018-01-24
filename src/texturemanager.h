#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "game.h"

class TextureManager
{
public:
    static SDL_Texture* LoadTextureImg(const char* fileName);
    static SDL_Texture* LoadTextureFont(const char* font, int size, int r, int g, int b, const char *text);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
    static void DrawBackground(SDL_Texture* tex);
    static void Size(SDL_Texture *tex);
};

#endif // TEXTUREMANAGER_H
