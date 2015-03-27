//
//  GameStateMachie.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 13/03/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__GameStateMachie__
#define __SDL_Game_SpriteSheet__GameStateMachie__

#include "GameState.h"

#include <vector>
class GameStateMachine
{
public:
    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();
private:
    std::vector<GameState*> m_gameStates;
};

#endif /* defined(__SDL_Game_SpriteSheet__GameStateMachie__) */
