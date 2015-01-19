//
//  Score.h
//  JUMP
//
//  Created by Liang Shi on 2/27/14.
//
//

#ifndef __JUMP__Score__
#define __JUMP__Score__

#include "cocos2d.h"
USING_NS_CC;

class Score : public CCLayer
{
public:
    Score();
    ~Score();
    CREATE_FUNC(Score);
    virtual bool init();
    
    CCAction* action;
    //CCSprite* warning;
    bool isWarning = false;
    
public:
    void createScoreLab();
    void changeScore(int order);
    int showScore();
    cocos2d::CCAnimate* createAnimation();
    
};

#endif /* defined(__JUMP__Score__) */
