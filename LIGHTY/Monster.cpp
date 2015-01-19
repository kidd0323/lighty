//
//  Monster.cpp
//  JUMP
//
//  Created by TOKI on 14-2-25.
//
//

#include "Monster.h"
#include "Player.h"
#include "ccMacros.h"

Monster::Monster()
{
    m_isAlive = false;
}

Monster::~Monster() {}

bool Monster::init()
{
    return true;
}

void Monster::show()
{
    if (getSprite() != NULL)
    {
        setVisible(true);
        m_isAlive = true;
    }
}

void Monster::hide()
{
    if (getSprite() != NULL) {
        setVisible(false);
        reset();
        m_isAlive = false;
    }
}

void Monster::reset()
{
    if (getSprite() != NULL) {
        setPosition(ccp(50 + CCRANDOM_0_1() * 500, 500 + CCRANDOM_0_1() * 400));
    }
}

bool Monster::isAlive()
{
    return m_isAlive;
}

bool Monster::isCollideWithPlayer(Player* sprite)
{
    CCRect entityRect = sprite->getBoundingBox();
    CCPoint monsterPos = getPosition();
    
    return entityRect.containsPoint(monsterPos);
    
}