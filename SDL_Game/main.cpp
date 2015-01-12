//
//  main.cpp
//  SDL_Game
//
//  Created by Khaled Garbaya on 12/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#include "Game.h"

// our Game object
Game* g_game = 0;


int main(int argc, char* args[])
{
    g_game = new Game();
    g_game->init("SDL Game", 100, 100, 640, 480,SDL_WINDOW_FULLSCREEN);
    while(g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    g_game->clean();
    return 0;
}
