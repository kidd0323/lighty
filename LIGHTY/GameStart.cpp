//
//  GameStart.cpp
//  JUMP
//
//  Created by Liang Shi on 2/25/14.
//
//

#include "GameStart.h"
#include "cocos-ext.h"

using namespace cocos2d::extension;

CCScene* GameStart::scene()
{
    CCScene* scene = CCScene::create();
    GameStart* layer = GameStart::create();
    scene->addChild(layer);
    return scene;
}

bool GameStart::init()
{
    
    CCMenuItemImage *startButton = CCMenuItemImage::create(
                                                           "startgame.png",
                                                           "startgame2.png",
                                                           this,
                                                           menu_selector(GameStart::menuCloseCallback) );
    
    startButton->setScaleX(0.6f);
    startButton->setScaleY(0.6f);
    startButton->setPosition( ccp(300,100) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(startButton, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    CCSprite* balloon = CCSprite::create("balloon1.png");
    balloon->setPosition(ccp(550, 700));
    this->addChild(balloon, 50);
    balloon->runAction(createAnimation2());
    
    
    CCSprite* person = CCSprite::create("person1.png");
    person->setPosition(ccp(150, 100));
    this->addChild(person, 4);
    person->runAction(createAnimation());
    
    CCJumpBy* moveTo = CCJumpBy::create(2.0f, ccp(0, 0), 50, 1);
    CCRepeatForever* repeat = CCRepeatForever::create(moveTo);
    person->runAction(repeat);
    

    initBG();
    this->scheduleUpdate();
    
    
    return true;
}

void GameStart::menuCloseCallback(cocos2d::CCObject *pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionJumpZoom::create(3.0f, LightyScene::scene()));
}

void GameStart::initBG()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    m_bgSprite = CCSprite::create("gamestart.png");
    m_bgSprite->setScaleX(visibleSize.width/m_bgSprite->getContentSize().width);
    m_bgSprite->setScaleY(visibleSize.height/m_bgSprite->getContentSize().height);
    m_bgSprite->setAnchorPoint(ccp(0, 0));
    
    this->addChild(m_bgSprite, 0);
    
    
    
}

void GameStart::update(float dt)
{
    /*
    int posY = m_bgSprite->getPositionY();
    int iSpeed = 1;
    
    posY -= iSpeed;
    
    CCSize mapSize = m_bgSprite->getContentSize();
    if (posY < -mapSize.width/5)
    {
        posY = mapSize.width/5;
    }
    
    
    m_bgSprite->setPositionY(posY);
     */
}

cocos2d::CCAnimate* GameStart::createAnimation()
{
    int iFrameNum = 4;
    CCSpriteFrame* frame = NULL;
    CCArray* frameArray = CCArray::create();
    
    for (int i = 1; i <= iFrameNum; i++) {
        frame = CCSpriteFrame::create(CCString::createWithFormat("person%d.png", i)->getCString(), CCRectMake(0, 0, 80, 80));
        frameArray->addObject(frame);
    }
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(frameArray);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.1f);
    
    CCAnimate* action = CCAnimate::create(animation);
    
    return action;
}
cocos2d::CCAnimate* GameStart::createAnimation2()
{
    int iFrameNum = 5;
    CCSpriteFrame* frame = NULL;
    CCArray* frameArray = CCArray::create();
    
    for (int i = 1; i <= iFrameNum; i++) {
        frame = CCSpriteFrame::create(CCString::createWithFormat("balloon%d.png", i)->getCString(), CCRectMake(0, 0, 200, 230));
        frameArray->addObject(frame);
    }
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(frameArray);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.1f);
    
    CCAnimate* action = CCAnimate::create(animation);
    
    return action;
}
