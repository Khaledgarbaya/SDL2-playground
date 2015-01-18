//
//  Enemy.cpp
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 13/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#include "Enemy.h"
#include "SDLGameObject.h"

Enemy::Enemy(const LoaderParams* pParams) :
SDLGameObject(pParams)
{
}
void Enemy::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
    m_position.setX( m_position.getX()+1);

    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::clean()
{
}