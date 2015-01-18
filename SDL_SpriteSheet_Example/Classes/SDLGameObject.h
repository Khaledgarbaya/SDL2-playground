//
//  SDLGameObject.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 14/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__SDLGameObject__
#define __SDL_Game_SpriteSheet__SDLGameObject__

#include <stdio.h>
#include <string>
#include "GameObject.h"
#include "Vector2D.h"
class SDLGameObject : public GameObject
{
public:
    SDLGameObject(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
protected:
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;
    int m_width;
    int m_height;
    int m_currentRow;
    int m_currentFrame;
    std::string m_textureID;
};
#endif /* defined(__SDL_Game_SpriteSheet__SDLGameObject__) */
