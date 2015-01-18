//
//  Vector2D.h
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 15/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#ifndef __SDL_Game_SpriteSheet__Vector2D__
#define __SDL_Game_SpriteSheet__Vector2D__

#include <math.h>
class Vector2D
{
public:
    Vector2D(float x, float y): m_x(x), m_y(y) {}
    float getX() { return m_x; }
    float getY() { return m_y; }
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }
    float length();
    
    void normalize();
    ///Operators overloading ------------------------------------------------------------
    /// + and += operators
    Vector2D operator+(const Vector2D& v2) const;
    Vector2D& operator+=(const Vector2D& v2);
    
    /// * and *= operator
    Vector2D operator*(float scalar);
    Vector2D& operator*=(float scalar);
    
    /// - and -= operator
    Vector2D operator-(const Vector2D& v2) const;
    Vector2D& operator-=(const Vector2D& v2);
    /// / and /= operator
    Vector2D operator/(float scalar);
    Vector2D& operator/=(float scalar);
private:
    float m_x;
    float m_y;
};
#endif /* defined(__SDL_Game_SpriteSheet__Vector2D__) */
