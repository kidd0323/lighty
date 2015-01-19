//
//  LightyScene.h
//  JUMP
//
//  Created by Liang Shi on 2/25/14.
//
//

#ifndef __JUMP__LightyScene__
#define __JUMP__LightyScene__

#include "Player.h"
#include "cocos2d.h"
#include "Score.h"
#include "GamePause.h"
#include "cocos-ext.h"
using namespace extension;
using namespace cocos2d;

class Player;
class LightyScene : public CCLayer
{
public:
    static CCScene* scene();
    virtual bool init();
    virtual void update(float dt);
    CREATE_FUNC(LightyScene);
    
private:
    void initBG(char* bgName);
    
    virtual void ccTouchesBegan(CCSet* pTouches, CCEvent* pEvent);
    cocos2d::CCAnimate* createAnimation();
    
    
    
private:
    CCSprite* m_bgSprite1;
    CCSprite* m_bgSprite2;
    Player* m_player;
    CCSprite* tail;
    Score* changeScore;
    
    CCPoint curPos;
    bool bgChanged = false;
    
public:
    CCSprite* pauseBg;
    void onPause(CCObject* pSender);
    void onResume(CCObject* pSender);

};

#endif /* defined(__JUMP__LightyScene__) */
