//
//  Enemy.cpp
//  JUMP
//
//  Created by Liang Shi on 3/3/14.
//
//

#include "Enemy.h"
#include "Player.h"
#include "ccMacros.h"

Enemy::Enemy()
{
    m_isAlive = false;
}

Enemy::~Enemy() {}

bool Enemy::init()
{
    return true;
}

void Enemy::show()
{
    if (getSprite() != NULL)
    {
        setVisible(true);
        m_isAlive = true;
    }
}

void Enemy::hide()
{
    if (getSprite() != NULL) {
        setVisible(false);
        reset();
        m_isAlive = false;
    }
}

void Enemy::reset()
{
    if (getSprite() != NULL) {
        setPosition(ccp(50 + CCRANDOM_0_1() * 500, 500 + CCRANDOM_0_1() * 400));
    }
}

bool Enemy::isAlive()
{
    return m_isAlive;
}

bool Enemy::isCollideWithPlayer(Player* sprite)
{
    CCRect entityRect = sprite->getBoundingBox();
    CCPoint monsterPos = getPosition();
    
    return entityRect.containsPoint(monsterPos);
    
}