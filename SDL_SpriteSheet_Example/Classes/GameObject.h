//
//  GameObject.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 13/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__GameObject__
#define __SDL_Game_SpriteSheet__GameObject__
#include <stdio.h>
#include <iostream>
#include "TextureManager.h"
#include "LoaderParams.h"
class GameObject
{
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
protected:
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
};
#endif /* defined(__SDL_Game_SpriteSheet__GameObject__) */
