//
//  Player.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 13/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__Player__
#define __SDL_Game_SpriteSheet__Player__

#include <stdio.h>
#include "SDLGameObject.h"
class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};
#endif /* defined(__SDL_Game_SpriteSheet__Player__) */
