//
//  Game.h
//  SDL_Game
//
//  Created by Khaled Garbaya on 12/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game__Game__
#define __SDL_Game__Game__
#include <stdio.h>
#include <iostream>
#include "TextureManager.h"
class Game
{
public:
    Game() {}
    ~Game() {}
    // simply set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int
              height, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();
    // a function to access the private running variable
    bool running() { return m_bRunning; }
private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    int m_currentFrame;
    bool m_bRunning;
};

#endif /* defined(__SDL_Game__Game__) */
