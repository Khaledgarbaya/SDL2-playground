//
//  Player.cpp
//  SDL_Game_SpriteSheet
//
//  Created by Khaled Garbaya on 13/01/15.
//  Copyright (c) 2015 Khaled Garbaya. All rights reserved.
//

#include "Player.h"
Player::Player(const LoaderParams* pParams) :
SDLGameObject(pParams)
{
}
void Player::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    m_acceleration.setX(1);
    SDLGameObject::update();
}
void Player::clean()
{
}