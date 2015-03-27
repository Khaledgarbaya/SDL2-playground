//
//  InputHandler.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 26/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__InputHandler__
#define __SDL_Game_SpriteSheet__InputHandler__
#include "Vector2D.h"
#include <stdio.h>
#include <vector>
#include <SDL2/SDL.h>
enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};
class InputHandler{
public:
    InputHandler();
    ~InputHandler(){};
    static InputHandler* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
            return s_pInstance;
        }
        return s_pInstance;
    }
    void update();
    
    /// Handling Mouse Event
    void onMouseButtonDown(SDL_Event & event);
    void onMouseMove(SDL_Event & event);
    void onMouseButtonUp(SDL_Event & event);
    bool getMouseButtonState(int buttonNumber);
    Vector2D* getMousePosition();

    ///Handling Keyboard Event
    void onKeyDown();
    void onKeyUp();
    bool isKeyDown(SDL_Scancode key) const;
    
private:
    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;
    Uint8* m_keystates;
    static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;
#endif /* defined(__SDL_Game_SpriteSheet__InputHandler__) */
