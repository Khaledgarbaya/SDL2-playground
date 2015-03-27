//
//  GameState.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 13/03/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef SDL_Game_SpriteSheet_GameState_h
#define SDL_Game_SpriteSheet_GameState_h

#include <string>
class GameState
{
public:
    virtual void update() = 0;
    virtual void render() = 0;
    
    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;
    
    virtual std::string getStateID() const = 0;
};

#endif
