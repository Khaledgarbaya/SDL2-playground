//
//  TheInputHandler.cpp
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 15/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#include "TheInputHandler.h"
InputHandler::InputHandler()
{
    /// Reset All mouse states to false
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
}