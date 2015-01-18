//
//  TextureManager.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 13/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__TextureManager__
#define __SDL_Game_SpriteSheet__TextureManager__
#include <ostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <map>
class TextureManager
{
public:
    bool load(std::string fileName,std::string id, SDL_Renderer* pRenderer);
    // draw
    void draw(std::string id, int x, int y, int width, int
              height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    // drawframe
    void drawFrame(std::string id, int x, int y, int width, int
                   height, int currentRow, int currentFrame, SDL_Renderer* pRenderer,
                   SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    static TextureManager* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }
    private:
    static TextureManager* s_pInstance;
    TextureManager() {}
    std::map<std::string, SDL_Texture*> m_textureMap;
};
typedef TextureManager TheTextureManager;
#endif /* defined(__SDL_Game_SpriteSheet__TextureManager__) */
