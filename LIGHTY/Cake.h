//
//  Cake.h
//  JUMP
//
//  Created by Liang Shi on 2/27/14.
//
//

#ifndef __JUMP__Cake__
#define __JUMP__Cake__

#include "cocos2d.h"
#include "Entity.h"
USING_NS_CC;

class Player;
class Cake : public Entity
{
public:
    Cake();
    ~Cake();
    CREATE_FUNC(Cake);
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

#endif /* defined(__JUMP__Cake__) */
