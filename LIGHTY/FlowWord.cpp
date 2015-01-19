//
//  FlowWord.cpp
//  JUMP
//
//  Created by Liang Shi on 2/26/14.
//
//

#include "FlowWord.h"

FlowWord* FlowWord::create()
{
    FlowWord* flowWord = new FlowWord();
    if (flowWord && flowWord->init()) {
        flowWord->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(flowWord);
    }
    
    return flowWord;
}

bool FlowWord::init()
{
    m_sprite = CCSprite::create("word1.png");
    m_sprite->setAnchorPoint(ccp(1, 0));
    m_sprite->setVisible(false);
    this->addChild(m_sprite);
    
    return true;
}

void FlowWord::showWord(const char *text, cocos2d::CCPoint pos)
{
    m_sprite->setPosition(pos);
    m_sprite->setVisible(true);
    
    CCActionInterval* scaleLarge = CCScaleTo::create(0.3f, 2.5f, 2.5f);
    CCActionInterval* scaleSmall = CCScaleTo::create(0.5f, 0.5f, 0.5f);
    
    CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(FlowWord::flowEnd));
    
    CCActionInterval* actions = CCSequence::create(scaleLarge, scaleSmall, callFunc, NULL);
    
    m_sprite->runAction(actions);
    
}

void FlowWord::flowEnd()
{
    m_sprite->setVisible(false);
    m_sprite->removeFromParentAndCleanup(true);
}
