//
//  GamePause.h
//  JUMP
//
//  Created by Liang Shi on 2/26/14.
//
//

#ifndef __JUMP__GamePause__
#define __JUMP__GamePause__

#include "cocos2d.h"
#include "Score.h"
using namespace cocos2d;

class GamePause : public CCLayer
{
public:
    static CCScene* scene();
    virtual bool init();
    CREATE_FUNC(GamePause);
    
    void menuPlayAgain(CCObject* pSender);
    void menuStopGame(CCObject* pSender);
    
private:
    Score* score;
};

#endif
