//
//  Cloud.cpp
//  JUMP
//
//  Created by Liang Shi on 2/26/14.
//
//

#include "Cloud.h"
#include "Player.h"
#include "ccMacros.h"

Cloud::Cloud()
{
    m_isAlive = false;
}

Cloud::~Cloud() {}

bool Cloud::init()
{
    return true;
}

void Cloud::show()
{
    if (getSprite() != NULL)
    {
        setVisible(true);
        m_isAlive = true;
    }
}

void Cloud::hide()
{
    if (getSprite() != NULL) {
        setVisible(false);
        reset();
        m_isAlive = false;
    }
}

void Cloud::reset()
{
    if (getSprite() != NULL) {
        setPosition(ccp(200 + CCRANDOM_0_1() * 500, 300 + CCRANDOM_0_1() * 400));
    }
}

bool Cloud::isAlive()
{
    return m_isAlive;
}