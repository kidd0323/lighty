//
//  Cloud.h
//  JUMP
//
//  Created by Liang Shi on 2/26/14.
//
//

#ifndef __JUMP__Cloud__
#define __JUMP__Cloud__

#include "cocos2d.h"
#include "Entity.h"
USING_NS_CC;

class Player;
class Cloud : public Entity
{
public:
    Cloud();
    ~Cloud();
    CREATE_FUNC(Cloud);
    virtual bool init();
    
public:
    void show();
    void hide();
    void reset();
    bool isAlive();
    
public:
    bool m_isAlive;
};

#endif /* defined(__JUMP__Cloud__) */
