//
//  LoaderParams.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 14/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__LoaderParams__
#define __SDL_Game_SpriteSheet__LoaderParams__

#include <stdio.h>
#include <string>
class LoaderParams
{
public:
    LoaderParams(int x, int y, int width, int height, std::string
                 textureID) : m_x(x), m_y(y), m_width(width), m_height(height),
    m_textureID(textureID)
    {
    }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    std::string getTextureID() const { return m_textureID; }
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    std::string m_textureID;
};
#endif /* defined(__SDL_Game_SpriteSheet__LoaderParams__) */
