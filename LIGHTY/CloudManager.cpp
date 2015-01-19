//
//  CloudManager.cpp
//  JUMP
//
//  Created by Liang Shi on 2/26/14.
//
//

#include "CloudManager.h"
#include "Player.h"
#include "Cloud.h"

CloudManager::CloudManager()
{
    m_cloudArr = NULL;
}

CloudManager::~CloudManager()
{
    CC_SAFE_DELETE(m_cloudArr);
}

bool CloudManager::init()
{
    bool bRet = false;
    do {
        createClouds();
        
        this->scheduleUpdate();
        bRet = true;
    } while (0);
    
    return bRet;
}

void CloudManager::createClouds()
{
    m_cloudArr = CCArray::create();
    m_cloudArr->retain();
    
    Cloud* cloud = NULL;
    
    cc_timeval psv;
    CCTime::gettimeofdayCocos2d(&psv, NULL);
    unsigned long int rand_seed = psv.tv_sec*1000 + psv.tv_usec/1000;
    srand(rand_seed);
    
    for (int i = 0; i < MAX_CLOUD_NUM; i++)
    {
        cloud = Cloud::create();
        
        int number = getRand(0, 2);
        
        switch (number) {
            case 0:
                cloud->bindSprite(CCSprite::create("cloud.png"));
                break;
                
            case 1:
            {
                CCSprite* bird = CCSprite::create("bird1.png");
                bird->runAction(createAnimation());
                cloud->bindSprite(bird);
                break;
            }
                
            case 2:
                cloud->bindSprite(CCSprite::create("plane.png"));
                break;
                
        }
        
        cloud->reset();
        
        this->addChild(cloud);
        
        m_cloudArr->addObject(cloud);
        
    }
}

void CloudManager::update(float dt)
{
    CCObject* obj = NULL;
    Cloud* cloud = NULL;
    
    
    CCARRAY_FOREACH(m_cloudArr, obj)
    {

        cloud = (Cloud*) obj;
        
        if (cloud->isAlive()) {
            cloud->setPositionX(cloud->getPositionX() - 4);
            
            if (cloud->getPositionX() < 0) {
                cloud->hide();
            }
        }
        else {
            cloud->show();
        }
    }
}

int CloudManager::getRand(int start,int end)
{
    float i = CCRANDOM_0_1()*(end-start+1)+start;  //产生一个从start到end间的随机数
    return (int)i;
}

cocos2d::CCAnimate* CloudManager::createAnimation()
{
    int iFrameNum = 4;
    CCSpriteFrame* frame = NULL;
    CCArray* frameArray = CCArray::create();
    
    for (int i = 1; i <= iFrameNum; i++) {
        frame = CCSpriteFrame::create(CCString::createWithFormat("bird%d.png", i)->getCString(), CCRectMake(0, 0, 100, 76));
        frameArray->addObject(frame);
    }
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(frameArray);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.1f);
    
    CCAnimate* action = CCAnimate::create(animation);
    
    return action;
}
