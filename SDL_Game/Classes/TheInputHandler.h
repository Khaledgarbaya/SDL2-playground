//
//  TheInputHandler.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 15/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__TheInputHandler__
#define __SDL_Game_SpriteSheet__TheInputHandler__

#include <SDL2/SDL.h>
#include <vector>
enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};
class InputHandler
{
public:
    static InputHandler* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }
    std::vector<bool> m_mouseButtonStates;
    void update();
    void clean();
private:
    InputHandler();
    ~InputHandler() {}
    static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;

#endif /* defined(__SDL_Game_SpriteSheet__TheInputHandler__) */
