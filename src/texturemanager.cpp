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
    SDL_Surface* tempSurface = TTF_RenderUTF8_Blended(tmp_font, text, tmp_color);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::m_pRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    TTF_CloseFont(tmp_font);

    return tex;
}

SDL_Texture* TextureManager::LoadTextureFontStory(const char* text, SDL_Rect size)
{
//    std::cout << font << std::endl;
    TTF_Font* tmp_font = TTF_OpenFont("../fonts/almendra/Almendra-Regular.ttf", 23);
    SDL_Color tmp_color = {240, 240, 240};
    SDL_Surface* tempSurface = TTF_RenderUTF8_Blended_Wrapped(tmp_font, text, tmp_color, size.x-40);
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

SDL_Rect TextureManager::DrawBackgroundStory(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_Rect size)
{
    src.x = src.y = 0;
    dest.x = dest.y = 0;
    dest.w = size.x;
    dest.h = size.y*2/3;
    SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);
    SDL_RenderCopy(renderer, tex, &src, &dest);
    return dest;
}

SDL_Rect TextureManager::DrawBackgroundTextStory(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_Rect size, SDL_Rect background_dest)
{
    src.x = src.y = 0;
    dest.x = dest.y = 0;
    dest.w = size.x;
    dest.h = size.y*1/3;
    dest.y = size.y - background_dest.h/2;
    SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);
    SDL_RenderCopy(renderer, tex, &src, &dest);
    return dest;
}

SDL_Rect TextureManager::DrawFontStory(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect dest, SDL_Rect background_text_dest)
{
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(tex, NULL, NULL, &texW, &texH);
//    src.x = src.y = 0;
    dest.w = texW;//400;
    dest.h = texH;//120;
    dest.x = background_text_dest.x + 20;
    dest.y = background_text_dest.y + 20;
    SDL_RenderCopy(renderer, tex, NULL, &dest);
    return dest;
}

void TextureManager::DrawBackground(SDL_Renderer *renderer, SDL_Texture *tex)
{
    SDL_RenderCopy(renderer, tex, NULL, NULL);
//    SDL_DestroyTexture(tex);
}
