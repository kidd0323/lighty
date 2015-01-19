//
//  Monster.h
//  JUMP
//
//  Created by TOKI on 14-2-25.
//
//

#ifndef __JUMP__Monster__
#define __JUMP__Monster__

#include "cocos2d.h"
#include "Entity.h"
USING_NS_CC;

class Player;
class Monster : public Entity
{
public:
    Monster();
    ~Monster();
    CREATE_FUNC(Monster);
    virtual bool init();
    
public:
    void show();
    void hide();
    void reset();
    bool isAlive();
    
    bool isCollideWithPlayer(Player* sprite);
    bool isRectCollision(CCRect rect1, CCRect rect2);
    
public:
    bool m_isAlive;
};

#endif /* defined(__JUMP__Monster__) */
