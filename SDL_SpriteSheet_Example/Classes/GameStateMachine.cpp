//
//  GameStateMachie.cpp
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 13/03/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* pState)
{
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}
void GameStateMachine::changeState(GameState* pState)
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->getStateID() == pState->getStateID())
        {
            return; // do nothing
        }
        if(m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
    // push back our new state
    m_gameStates.push_back(pState);
    // initialise it
    m_gameStates.back()->onEnter();
}
void GameStateMachine::popState()
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
}
