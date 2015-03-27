//
//  Game.cpp
//  SDL_Game
//
//  Created by Khaled Garbaya on 12/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#include "Game.h"
#include "MenuState.h"
#include "InputHandler.h"
Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width,
                int height, bool fullscreen)
{
    // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        
        std::cout << "Loading texture"<<std::endl;
        
        //Steps Creating and SDL Texture
        
        int flags = 0;
        if(fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos,
                                     width, height, flags);
        if(m_pWindow != 0) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 255,0,0,255);
            } else {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        } else {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    } else {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }
    std::cout << "init success\n";
    //std::cout<< "SDL Base Path ::"<< SDL_GetBasePath() << std::endl;
    if(!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }
    // to load
    m_gameObjects.push_back(new Player(new LoaderParams(10, 100, 128, 82, "animate")));
    m_gameObjects.push_back(new Enemy(new LoaderParams(10, 300, 128, 82, "animate")));
    
    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());
    
    m_bRunning = true; // everything inited successfully,start the main loop
    
    return true;
}
void Game::render()
{
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
    ///all the stuff you wanna render goes here
    /// render non flipped texture
    //SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    ///Render flipped texture
    // loop through our objects and draw them
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
    
    SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
    
}
void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    delete m_pGameStateMachine;
    SDL_Quit();
}
void Game::update()
{
    // loop through and update our objects
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}