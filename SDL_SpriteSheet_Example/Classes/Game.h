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
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"
class Game
{
public:
    // create the public instance function
    static Game* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }
    ~Game() {}
    // simply set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int
              height, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();
    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    // a function to access the private running variable
    bool running() { return m_bRunning; }
    
    GameObject* m_go;
    Player* m_player;
    GameObject* m_enemy;
    std::vector<GameObject*> m_gameObjects;
private:
    Game(){}
    // create the s_pInstance member variable
    static Game* s_pInstance;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    int m_currentFrame;
    bool m_bRunning;
    
    GameStateMachine* m_pGameStateMachine;
};
typedef  Game TheGame;
#endif /* defined(__SDL_Game__Game__) */
