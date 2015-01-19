//
//  LightyScene.cpp
//  JUMP
//
//  Created by Liang Shi on 2/25/14.
//
//

#include "LightyScene.h"
#include "Player.h"
#include "MonsterManager.h"
#include "cocos-ext.h"
#include "GamePause.h"
#include "CloudManager.h"
#include "CakeManager.h"
#include "Score.h"
#include "EnemyManager.h"

using namespace extension;

CCScene* LightyScene::scene()
{
    CCScene* scene = CCScene::create();
    LightyScene* layer = LightyScene::create();
    scene->addChild(layer);
    return scene;
}


bool LightyScene::init()
{
    bool bRet = false;
    do {
        m_player = Player::create();
        
        m_player->bindSprite(CCSprite::create("banana1.png"));
        m_player->setPosition(ccp(300, 40));
        this->addChild(m_player, 100);
        
        initBG("sky2.png");
  
        CloudManager* cloudMgr = CloudManager::create();
        this->addChild(cloudMgr, 3);
        
        
        MonsterManager* monsterMgr = MonsterManager::create();
        monsterMgr->bindPlayer(m_player);
        this->addChild(monsterMgr, 4);
        

        CakeManager* cakeMgr = CakeManager::create();
        cakeMgr->bindPlayer(m_player);
        this->addChild(cakeMgr, 6);
        
        EnemyManager* enemyMgr = EnemyManager::create();
        enemyMgr->bindPlayer(m_player);
        this->addChild(enemyMgr, 8);

        
        //monsterMgr->createScoreLab();
        changeScore = Score::create();
        changeScore->createScoreLab();
        this->addChild(changeScore, 7);
    
        
        tail = CCSprite::create("s1.png");
        this->addChild(tail);
        tail->runAction(createAnimation());
        
        this->setTouchEnabled(true);
        this->scheduleUpdate();
        
        //pause button
        CCMenuItemImage* pauseBtn = CCMenuItemImage::create("pause.png", "pause2.png", this, menu_selector(LightyScene::onPause));
        pauseBtn->setScaleX(0.3f);
        pauseBtn->setScaleY(0.3f);
        pauseBtn->setAnchorPoint(ccp(1, 1));
        CCMenu* menu = CCMenu::create(pauseBtn, NULL);
        menu->setPosition(ccp(600, 920));
        this->addChild(menu, 8, 10);
        
        
        
        bRet = true;
        
    } while (0);
    
    return bRet;
}

void LightyScene::initBG(char* bgName)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    m_bgSprite1 = CCSprite::create(bgName);
    m_bgSprite1->setScaleX(visibleSize.width/m_bgSprite1->getContentSize().width);
    m_bgSprite1->setScaleY(visibleSize.height/m_bgSprite1->getContentSize().height);
    m_bgSprite1->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    this->addChild(m_bgSprite1, 0);
    
    m_bgSprite2 = CCSprite::create(bgName);
    m_bgSprite2->setScaleX(visibleSize.width/m_bgSprite2->getContentSize().width);
    m_bgSprite2->setScaleY(visibleSize.height/m_bgSprite2->getContentSize().height);
    m_bgSprite2->setPosition(ccp(visibleSize.width/2, visibleSize.height + visibleSize.height/2));
    m_bgSprite2->setFlipY(true);
    this->addChild(m_bgSprite2, 0);
    
}

void LightyScene::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    //点击事件，主角向上移动
    curPos = m_player->getPosition();
    
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    //CCPoint pos1 = touch->getLocation();
    CCPoint pos2 = touch->getLocationInView();
    CCPoint pos3 = CCDirector::sharedDirector()->convertToUI(pos2);
    
    
    if (curPos.y < pos3.y)
    {
        CCJumpTo* jumpTo = CCJumpTo::create(0.3f, ccp(pos3.x, pos3.y),30,1);
        m_player->runAction(jumpTo);
        
        curPos = m_player->getPosition();
        
        return;
    }
    curPos = m_player->getPosition();
    //curPos = CCDirector::sharedDirector()->convertToUI(tmpPos);
}

void LightyScene::update(float dt)
{
    //background rolling
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    int posY1 = m_bgSprite1->getPositionY();
    int posY2 = m_bgSprite2->getPositionY();
    
    int iSpeed = 5;
    
    posY1 -= iSpeed;
    posY2 -= iSpeed;
    
    
    if (posY1 < -visibleSize.height / 2) {
        posY2 = visibleSize.height / 2;
        posY1 = visibleSize.height + visibleSize.height / 2;
    }
    if (posY2 < -visibleSize.height / 2) {
        posY1 = visibleSize.height / 2;
        posY2 = visibleSize.height + visibleSize.height/2;
    }
    
    m_bgSprite1->setPositionY(posY1);
    m_bgSprite2->setPositionY(posY2);
    
    //jumping monitoring
    curPos = m_player->getPosition();
    
    if (curPos.y > 300) {
        m_player->gameOver = true;
    }
    
    if (curPos.y <= 40)
    {
        m_player->setPositionY(40);
        curPos = m_player->getPosition();

        m_player->flagY = 1;
        m_player->nowBottom = true;
        m_player->jumpSpeed = 300;
        
        //game over
        if (m_player->gameOver)
        {
            m_player->gameOver = false;
            CCDirector::sharedDirector()->pushScene(GamePause::scene());

        }
        
        return;
    }
    
    else
    {
        
        m_player->nowBottom = false;
    }
    
    if (m_player->flagY == 1 && m_player->jumpSpeed <= 0 && !m_player->nowBottom)
    {
        m_player->flagY = -1;
    }
    
    tail->setPosition(ccp(m_player->getPositionX() + 20, m_player->getPositionY() - 90));
    changeScore->changeScore(5);

    m_player->jumpSpeed -= m_player->flagY * 300 * dt;
    if (m_player->jumpSpeed >0 && m_player->flagY!=0)
    {
        m_player->setPositionY(curPos.y + m_player->flagY * m_player->jumpSpeed *dt);
        
    }
    
    //change background
    int number = changeScore->showScore();
    if (number > 1000 && !bgChanged) {
        this->removeChild(m_bgSprite1);
        this->removeChild(m_bgSprite2);
        initBG("sky3.png");
        bgChanged = true;
    }
}

cocos2d::CCAnimate* LightyScene::createAnimation()
{
    int iFrameNum = 4;
    CCSpriteFrame* frame = NULL;
    CCArray* frameArray = CCArray::create();
    
    for (int i = 1; i <= iFrameNum; i++) {
        frame = CCSpriteFrame::create(CCString::createWithFormat("s%d.png", i)->getCString(), CCRectMake(0, 0, 98, 166));
        frameArray->addObject(frame);
    }
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(frameArray);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.1f);
    
    CCAnimate* action = CCAnimate::create(animation);
    
    return action;
}


void LightyScene::onPause(CCObject* pSender)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    pauseBg = CCSprite::create("pauselayer.png");
    pauseBg->setScaleX(visibleSize.width/pauseBg->getContentSize().width);
    pauseBg->setScaleY(visibleSize.height/m_bgSprite1->getContentSize().height);
    pauseBg->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    this->addChild(pauseBg, 199);

    CCMenu* menu = (CCMenu*)this->getChildByTag(10);
    menu->setEnabled(false);
    
    CCMenuItemImage* pauseBtn = CCMenuItemImage::create("resume.png", "resume2.png", this, menu_selector(LightyScene::onResume));
    pauseBtn->setAnchorPoint(ccp(1, 1));
    CCMenu* menu2 = CCMenu::create(pauseBtn, NULL);
    menu2->setPosition(ccp(450, 400));
    this->addChild(menu2, 200, 20);
    
    

    
    CCDirector::sharedDirector()->pause();
}

void LightyScene::onResume(CCObject* pSender)
{
    CCMenu* menu = (CCMenu*)this->getChildByTag(10);
    menu->setEnabled(true);
    
    this->removeChild(getChildByTag(20));
    this->removeChild(pauseBg);
    CCDirector::sharedDirector()->resume();
}
