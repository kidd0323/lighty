//
//  Cake.cpp
//  JUMP
//
//  Created by Liang Shi on 2/27/14.
//
//

#include "Cake.h"
#include "Player.h"
#include "ccMacros.h"

Cake::Cake()
{
    m_isAlive = false;
}

Cake::~Cake() {}

bool Cake::init()
{
    return true;
}

void Cake::show()
{
    if (getSprite() != NULL)
    {
        setVisible(true);
        m_isAlive = true;
    }
}

void Cake::hide()
{
    if (getSprite() != NULL) {
        setVisible(false);
        reset();
        m_isAlive = false;
    }
}

void Cake::reset()
{
    if (getSprite() != NULL) {
        setPosition(ccp(50 + CCRANDOM_0_1() * 500, 500 + CCRANDOM_0_1() * 400));
    }
}

bool Cake::isAlive()
{
    return m_isAlive;
}

bool Cake::isCollideWithPlayer(Player* sprite)
{
    CCRect entityRect = sprite->getBoundingBox();
    CCPoint monsterPos = getPosition();
    
    return entityRect.containsPoint(monsterPos);
    
}
