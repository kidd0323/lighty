//
//  GameStart.h
//  JUMP
//
//  Created by Liang Shi on 2/25/14.
//
//

#ifndef __JUMP__GameStart__
#define __JUMP__GameStart__

#include "LightyScene.h"
#include "cocos2d.h"
using namespace cocos2d;

class GameStart : public CCLayer
{
public:
    static CCScene* scene();
    virtual bool init();
    void menuCloseCallback(CCObject* pSender);
    virtual void update(float dt);
    CREATE_FUNC(GameStart);
    
private:
    void initBG();
    
    cocos2d::CCAnimate* createAnimation();
    cocos2d::CCAnimate* createAnimation2();
    
    
private:
    CCSprite* m_bgSprite;
};

#endif /* defined(__JUMP__GameStart__) */
