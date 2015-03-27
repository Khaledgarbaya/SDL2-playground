//
//  MenuState.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 13/03/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__MenuState__
#define __SDL_Game_SpriteSheet__MenuState__

#include "GameState.h"
class MenuState: public GameState
{
public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const { return s_menuID; }
private:
    static const std::string s_menuID;

};

#endif /* defined(__SDL_Game_SpriteSheet__MenuState__) */
