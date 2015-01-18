//
//  Vector2D.cpp
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 15/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#include "Vector2D.h"

float Vector2D::length() { return sqrt(m_x * m_x + m_y * m_y); }

void Vector2D::normalize()
{
    float l = length();
    if ( l > 0) // we never want to attempt to divide by 0
    {
        (*this) *= 1 / l;
    }
}

/// + and += operators implementation
Vector2D Vector2D::operator+(const Vector2D& v2) const
{
    return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}
Vector2D& Vector2D::operator+=(const Vector2D& v2)
{
    m_x += v2.m_x;
    m_y += v2.m_y;
    return *this;
}

/// * and *= operator
Vector2D Vector2D::operator*(float scalar)
{
    return Vector2D(m_x * scalar, m_y * scalar);
}
Vector2D& Vector2D::operator*=(float scalar)
{
    m_x *= scalar;
    m_y *= scalar;
    return *this;
}

/// - and -= operator
Vector2D Vector2D::operator-(const Vector2D& v2) const
{
    return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}
Vector2D& Vector2D::operator-=(const Vector2D& v2)
{
    this->m_x -= v2.m_x;
    this->m_y -= v2.m_y;
    return *this;
}

/// / and /= operator
Vector2D Vector2D::operator/(float scalar)
{
    return Vector2D(m_x / scalar, m_y / scalar);
}
Vector2D& Vector2D::operator/=(float scalar)
{
    m_x /= scalar;
    m_y /= scalar;
    return *this;
}


