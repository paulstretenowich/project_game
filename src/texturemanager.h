#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "game.h"

class TextureManager
{
public:
    static SDL_Texture* LoadTextureImg(const char* fileName);

    static SDL_Texture* LoadTextureFont(const char* font, int size, int r, int g, int b, const char *text);
    static SDL_Texture* LoadTextureFontStory(const char* text, SDL_Rect size);

    static void Draw(SDL_Renderer* renderer, SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

    static SDL_Rect DrawFontStory(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect dest, SDL_Rect background_text_dest);
    static SDL_Rect DrawBackgroundStory(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_Rect size);
    static SDL_Rect DrawBackgroundTextStory(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_Rect size, SDL_Rect background_dest);

    static void DrawBackground(SDL_Renderer* renderer, SDL_Texture* surface);
    static void Size(SDL_Texture *tex);
};

#endif // TEXTUREMANAGER_H
