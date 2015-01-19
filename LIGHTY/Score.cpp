//
//  Score.cpp
//  JUMP
//
//  Created by Liang Shi on 2/27/14.
//
//


#include "Score.h"
#include "config.h"
#include "GamePause.h"

Score::Score()
{
    m_fScore = 0;
    m_fBlood = 100;
    isWarning = false;
}

Score::~Score() {}

bool Score::init()
{
    return true;
}

void Score::createScoreLab()
{

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    m_scoreLab = CCLabelTTF::create("Score:0", "Arial", 35);
    m_scoreLab->setColor(ccc3(0, 0, 0));
    m_scoreLab->setPosition(ccp(40, visibleSize.height - 50));
    m_scoreLab->setAnchorPoint(ccp(0, 1));
    this->addChild(m_scoreLab, 300);
    
    
    m_blood  = CCControlSlider::create("bloodbg.png", "blood.png", "bloodbtn.png");
    m_blood->setPosition(ccp(100, visibleSize.height - 110));
    m_blood->setMinimumValue(0);
    m_blood->setMaximumValue(100);
    m_blood->setValue(m_fBlood);
    this->addChild(m_blood, 201);
    
    
    warning = CCSprite::create("warning1.png");
    warning->setPosition(ccp(320, 480));
    this->addChild(warning, 5);
    action = createAnimation();
    warning->runAction(action);
    warning->setVisible(false);
}

void Score::changeScore(int order)
{
    switch (order) {
        case 1:   //height
        {
            m_fScore += 10;
            m_scoreLab->setString(CCString::createWithFormat("SCORE:%d", m_fScore)->getCString());
            break;
        }
        case 2:  //score of tool
        {
            m_fScore += 30;
            m_scoreLab->setString(CCString::createWithFormat("SCORE:%d", m_fScore)->getCString());
            break;
        }
        case 3:  //blood of tool
        {
            m_fBlood += 10;
            if (m_fBlood > 20) {
                warning->setVisible(false);
            }
            m_blood->setValue(m_fBlood);
            break;
        }
        case 4:  //blood of enemy
        {
            m_fBlood -= 20;
            if (m_fBlood <= 20) {
                warning->setVisible(true);
            }
            if (m_fBlood > 20) {
                warning->setVisible(false);
            }
            if (m_fBlood < 0) {
                CCDirector::sharedDirector()->pushScene(GamePause::scene());
                return;
            }
            m_blood->setValue(m_fBlood);
            break;
        }
        case 5: //blood decreaing
        {
            m_fBlood -= 0.08;
            
            if (m_fBlood <= 20) {
                warning->setVisible(true);
            }
            if (m_fBlood > 20) {
                warning->setVisible(false);
            }
            
            if (m_fBlood < 0)
            {
                CCDirector::sharedDirector()->pushScene(GamePause::scene());
                return;
            }
            m_blood->setValue(m_fBlood);
        }
            
    }
}

int Score::showScore()
{
    return m_fScore;
}

cocos2d::CCAnimate* Score::createAnimation()
{
    int iFrameNum = 2;
    CCSpriteFrame* frame = NULL;
    CCArray* frameArray = CCArray::create();
    
    for (int i = 1; i <= iFrameNum; i++) {
        frame = CCSpriteFrame::create(CCString::createWithFormat("warning%d.png", i)->getCString(), CCRectMake(0, 0, 513, 883));
        frameArray->addObject(frame);
    }
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(frameArray);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.1f);
    
    CCAnimate* action = CCAnimate::create(animation);
    
    return action;
}