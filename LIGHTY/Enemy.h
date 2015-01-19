//
//  Enemy.h
//  JUMP
//
//  Created by Liang Shi on 3/3/14.
//
//

#ifndef __JUMP__Enemy__
#define __JUMP__Enemy__

#include "cocos2d.h"
#include "Entity.h"
USING_NS_CC;

class Player;
class Enemy : public Entity
{
public:
    Enemy();
    ~Enemy();
    CREATE_FUNC(Enemy);
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

#endif /* defined(__JUMP__Enemy__) */
