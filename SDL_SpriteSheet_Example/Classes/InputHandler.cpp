//
//  InputHandler.cpp
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 26/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#include "InputHandler.h"
InputHandler::InputHandler():m_keystates(0),
m_mousePosition(new Vector2D(0,0))
{
    //reset all states
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
    
}
InputHandler* InputHandler::s_pInstance = 0;

Vector2D* InputHandler::getMousePosition()
{
    return m_mousePosition;
}
void InputHandler::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
                //Quit the game
                break;
            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;
            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;
            case SDL_KEYDOWN:
                onKeyDown();
                break;
            case SDL_KEYUP:
                onKeyUp();
                break;
            default:
                break;
 
        }
    }
}
bool InputHandler::isKeyDown(SDL_Scancode key) const
{
    if(m_keystates != 0)
    {
        if(m_keystates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    return false;
}

void InputHandler::onKeyDown()
{
    m_keystates = (Uint8*)SDL_GetKeyboardState(0);
}
void InputHandler::onKeyUp()
{
    m_keystates = (Uint8*)SDL_GetKeyboardState(0);
}

void InputHandler::onMouseButtonDown(SDL_Event & event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = true;
    }
    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = true;
    }
    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = true;
    }
}
void InputHandler::onMouseMove(SDL_Event & event)
{
    m_mousePosition->setX(event.motion.x);
    m_mousePosition->setY(event.motion.y);
}
void InputHandler::onMouseButtonUp(SDL_Event & event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = false;
    }
    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = false;
    }
    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = false;
    }
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
    return m_mouseButtonStates[buttonNumber];
}
