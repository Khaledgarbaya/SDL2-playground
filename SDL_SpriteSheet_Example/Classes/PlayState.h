//
//  PlayState.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 13/03/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__PlayState__
#define __SDL_Game_SpriteSheet__PlayState__
#include "GameState.h"
#include "GameState.h"
class PlayState : public GameState
{
public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const { return s_playID; }
private:
    static const std::string s_playID;
};


#endif /* defined(__SDL_Game_SpriteSheet__PlayState__) */
