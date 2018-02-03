#include <iostream>

#include "texturemanager.h"

SDL_Texture* TextureManager::LoadTextureImg(const char* texture)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::m_pRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}

SDL_Texture* TextureManager::LoadTextureFont(const char* font, int size, int r, int g, int b, const char* text)
{
//    std::cout << font << std::endl;
    TTF_Font* tmp_font = TTF_OpenFont(font, size);
    SDL_Color tmp_color = {r, g, b};
    SDL_Surface* tempSurface = TTF_RenderUTF8_Solid(tmp_font, text, tmp_color);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::m_pRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    TTF_CloseFont(tmp_font);

    return tex;
}

void TextureManager::Size(SDL_Texture *tex)
{
    SDL_Rect position;
    SDL_QueryTexture(tex, NULL, NULL, &position.w, &position.h);
}

void TextureManager::Draw(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);
    SDL_RenderCopy(renderer, tex, &src, &dest);
}

void TextureManager::DrawBackground(SDL_Renderer *renderer, SDL_Texture *tex)
{
    SDL_RenderCopy(renderer, tex, NULL, NULL);
}
