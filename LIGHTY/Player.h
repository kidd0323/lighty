//
//  Player.h
//  JUMP
//
//  Created by Liang Shi on 2/25/14.
//
//

#ifndef __JUMP__Player__
#define __JUMP__Player__

#include "Entity.h"
#include "cocos2d.h"
using namespace cocos2d;

USING_NS_CC;


class Player : public Entity
{
public:
    Player();
    ~Player();
    CREATE_FUNC(Player);
    virtual bool init();
    
    bool nowBottom;
    int jumpSpeed = 300;
    int flagY = 1;
    
    bool gameOver = false;
    
    
public:
    void jump();
    void jumpEnd();
    void hit();
    
    CCRect getBoundingBox();
    
    
private:
    bool m_isJumping;

    CCPoint curPos;
    

    

};

#endif /* defined(__JUMP__Player__) */
