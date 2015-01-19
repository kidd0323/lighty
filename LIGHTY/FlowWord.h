//
//  FlowWord.h
//  JUMP
//
//  Created by Liang Shi on 2/26/14.
//
//

#ifndef __JUMP__FlowWord__
#define __JUMP__FlowWord__

#include "cocos2d.h"
USING_NS_CC;

class FlowWord : public CCNode
{
public:
    static FlowWord* create();
    bool init();
    
public:
    void showWord(const char* text, CCPoint pos);
    
private:
    CCLabelTTF* m_textLab;
    CCSprite* m_sprite;
    
    void flowEnd();
};

#endif /* defined(__JUMP__FlowWord__) */
