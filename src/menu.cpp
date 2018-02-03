//#include <iostream>
//#include <cstdlib>
//#include <vector>
//#include <list>

//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_mixer.h>

//#include "menu.h"
//#include "game.h"
//#include "texturemanager.h"

//Menu::Menu()
//{
//    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);
//    Mix_Music* background_menu_music = Mix_LoadMUS("../music/menu_music.ogg");
//    Mix_PlayMusic(background_menu_music, -1);

//    SDL_GetRendererOutputSize(Game::renderer, &size.x, &size.y);

//    background = TextureManager::LoadTextureImg("../images/menu/menu_background_new_002.png");

//    quit_button = TextureManager::LoadTextureImg("../images/menu/button.png");
//    quit_button_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 100, 255, 255, 255, "Quitter");
//    quit_button_src.x = quit_button_src.y = 0;
//    quit_button_dest.w = 300;
//    quit_button_font_dest.w = quit_button_dest.w*2/3;
//    quit_button_dest.h = 50;
//    quit_button_font_dest.h = quit_button_dest.h*2/3;
//    quit_button_dest.x = size.x/2 - quit_button_dest.w/2;
//    quit_button_font_dest.x = size.x/2 - quit_button_font_dest.w/2;
//    quit_button_dest.y = size.y*5/8 - quit_button_dest.h/2;
//    quit_button_font_dest.y = size.y*5/8 - quit_button_font_dest.h/2;

//    play_button = TextureManager::LoadTextureImg("../images/menu/button.png");
//    play_button_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 100, 255, 255, 255, "Jouer");
//    play_button_src.x = play_button_src.y = 0;
//    play_button_dest.w = 300;
//    play_button_font_dest.w = play_button_dest.w*2/3;
//    play_button_dest.h = 50;
//    play_button_font_dest.h = play_button_dest.h*2/3;
//    play_button_dest.x = size.x/2 - play_button_dest.w/2;
//    play_button_font_dest.x = size.x/2 - play_button_font_dest.w/2;
//    play_button_dest.y = size.y*3/8 - play_button_dest.h/2;
//    play_button_font_dest.y = size.y*3/8 - play_button_font_dest.h/2;

//    contour = TextureManager::LoadTextureImg("../images/menu/contour.png");
//    contour_src.x = contour_src.y = 0;
////    contour_dest.x = play_button_dest.x - 1;
////    contour_dest.y = play_button_dest.y - 1;
////    contour_dest.w = play_button_dest.w + 1;
////    contour_dest.h = play_button_dest.h + 1;

//    option_button = TextureManager::LoadTextureImg("../images/menu/button.png");
//    option_button_font = TextureManager::LoadTextureFont("../fonts/Dalelands Uncial.otf", 100, 255, 255, 255, "Options");
//    option_button_src.x = option_button_src.y = 0;
//    option_button_dest.w = 300;
//    option_button_font_dest.w = option_button_dest.w*2/3;
//    option_button_dest.h = 50;
//    option_button_font_dest.h = option_button_dest.h*2/3;
//    option_button_dest.x = size.x/2 - option_button_dest.w/2;
//    option_button_font_dest.x = size.x/2 - option_button_font_dest.w/2;
//    option_button_dest.y = size.y*4/8 - option_button_dest.h/2;
//    option_button_font_dest.y = size.y*4/8 - option_button_font_dest.h/2;

//    title = TextureManager::LoadTextureFont("../fonts/The_Wild_Breath_of_Zelda.otf", 100, 0, 0, 0, "Titre du jeu");
//    title_src.x = title_src.y = 0;
//    title_dest.w = 400;
//    title_dest.h = 120;
//    title_dest.x = size.x/2-title_dest.w/2;
//    title_dest.y = 50;

//    position = 0;
//}

////SDL_Rect Menu::GetPosition(SDL_Rect *rect)
////{
////    return rect
////}

//std::vector<SDL_Rect> Menu::Move()
//{
//    std::vector<SDL_Rect> vecOfRec;
//    SDL_Rect play;
//    play.x = Menu::play_buttonPosition().x - 3;
//    play.y = Menu::play_buttonPosition().y - 3;
//    play.w = Menu::play_buttonPosition().w + 6;
//    play.h = Menu::play_buttonPosition().h + 6;
//    vecOfRec.push_back(play);
//    SDL_Rect option;
//    option.x = Menu::option_buttonPosition().x - 3;
//    option.y = Menu::option_buttonPosition().y - 3;
//    option.w = Menu::option_buttonPosition().w + 6;
//    option.h = Menu::option_buttonPosition().h + 6;
//    vecOfRec.push_back(option);
//    SDL_Rect quit;
//    quit.x = Menu::quit_buttonPosition().x - 3;
//    quit.y = Menu::quit_buttonPosition().y - 3;
//    quit.w = Menu::quit_buttonPosition().w + 6;
//    quit.h = Menu::quit_buttonPosition().h + 6;
//    vecOfRec.push_back(quit);
////    std::cout << vecOfStr[0] << std::endl;
//    return vecOfRec;
//}

//void Menu::DrawMenu()
//{
////    if ( (SDL_GetTicks() - g_Timer) >= FRAME_RATE )
////        {
////            HandleMenuInput();

////            // Make sure nothing from the last frame is still drawn. //
////            ClearScreen();

////            DisplayText("Start (G)ame", 350, 250, 12, 255, 255, 255, 0, 0, 0);
////            DisplayText("(Q)uit Game",  350, 270, 12, 255, 255, 255, 0, 0, 0);

////            // Tell SDL to display our backbuffer. The four 0's will make //
////            // SDL display the whole screen. //
////            SDL_UpdateRect(g_Window, 0, 0, 0, 0);

////            // We've processed a frame so we now need to record the time at which we did it. //
////            // This way we can compare this time the next time our function gets called and  //
////            // see if enough time has passed between iterations. //
////            g_Timer = SDL_GetTicks();
////        }
//    TextureManager::DrawBackground(background);

//    TextureManager::Draw(quit_button, quit_button_src, quit_button_dest);
//    TextureManager::Draw(quit_button_font, quit_button_src, quit_button_font_dest);

//    TextureManager::Draw(play_button, play_button_src, play_button_dest);
//    TextureManager::Draw(play_button_font, play_button_src, play_button_font_dest);

//    TextureManager::Draw(option_button, option_button_src, option_button_dest);
//    TextureManager::Draw(option_button_font, option_button_src, option_button_font_dest);

//    TextureManager::Draw(title, title_src, title_dest);

//    TextureManager::Draw(contour, contour_src, Move()[position]);
////    Move()[position]
//}

//void Menu::DrawSubMenu()
//{
//    TextureManager::DrawBackground(background);
//}
