//
//  Game.cpp
//  SDL_Game
//
//  Created by Khaled Garbaya on 12/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#include "Game.h"

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
                SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,255);
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
    //1.loading the image with return and SDL_Surface
    SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
    
    if(pTempSurface == NULL)
    {
        std::cout<< "Error while loading the bitmap assets/rider.bmp, Error: "<< SDL_GetError()<< std::endl;
    }
    //2.Create a texture out of it
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    
    if(m_pTexture == NULL)
    {
        std::cout<< "Error while creating the texture, SDL_Error: "<< SDL_GetError()<< std::endl;
    }
    //3.Free the surface after creating the texture
    SDL_FreeSurface(pTempSurface);
    
    //Displaying the texture
    
    /// Query the created texture for width and height
    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
    m_sourceRectangle.w = 50;
    m_sourceRectangle.h = 50;
    ///set where we want to render the texture on the wondow
    m_sourceRectangle.x = 0;
    m_sourceRectangle.y = 0;
    m_destinationRectangle.x = 100;
    m_destinationRectangle.y = 100;
    
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;
    
    ///Render to the screen in the render method
    
    m_bRunning = true; // everything inited successfully,start the main loop
    return true;
}
void Game::render()
{
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
    ///all the stuff you wanna render goes here
    SDL_RenderCopy(m_pRenderer, m_pTexture, NULL, NULL);
    
    SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            // keyboard Events
            case SDL_KEYUP :
                switch (event.key.keysym.sym)
                {
                    case SDLK_q:
                        m_bRunning = false;
                        break;
                }
                break;
            default:
            break;
        }
    }
}
void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}