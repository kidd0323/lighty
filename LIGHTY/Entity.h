//
//  Entity.h
//  JUMP
//
//  Created by Liang Shi on 2/25/14.
//
//

#ifndef __JUMP__Entity__
#define __JUMP__Entity__

#include "cocos2d.h"
using namespace cocos2d;
USING_NS_CC;

class Entity : public CCNode
{
public:
    Entity();
    ~Entity();
    CCSprite* getSprite();
    void bindSprite(CCSprite* sprite);
    
public:
    CCSprite* m_sprite;
    
};

#endif /* defined(__JUMP__Entity__) */
