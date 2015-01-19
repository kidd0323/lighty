//
//  CakeManager.cpp
//  JUMP
//
//  Created by Liang Shi on 2/27/14.
//
//

#include "CakeManager.h"
#include "Player.h"
#include "Cake.h"
#include "Score.h"

CakeManager::CakeManager()
{
    m_cakeArr = NULL;
}

CakeManager::~CakeManager()
{
    CC_SAFE_DELETE(m_cakeArr);
}

bool CakeManager::init()
{
    bool bRet = false;
    do {
        createCakes(cakeNum);
        
        this->scheduleUpdate();
        bRet = true;
    } while (0);
    
    return bRet;
}

void CakeManager::createCakes(int cakeNum)
{
    m_cakeArr = CCArray::create();
    m_cakeArr->retain();
    
    cake = NULL;
    
    for (int i = 0; i < cakeNum; i++)
    {
        cake = Cake::create();
        
        int number = CCRANDOM_0_1() * 5;
        
        switch (number) {
            case 0:
                cake->bindSprite(CCSprite::create("cake1.png"));
                break;
                
            case 1:
                cake->bindSprite(CCSprite::create("cake2.png"));
                break;
            case 2:
                cake->bindSprite(CCSprite::create("cake3.png"));
                break;
            case 3:
                cake->bindSprite(CCSprite::create("cake4.png"));
                break;
            case 4:
                cake->bindSprite(CCSprite::create("cake5.png"));
                break;
        }
        
        cake->reset();
        
        this->addChild(cake);
        
        m_cakeArr->addObject(cake);
    }
}

void CakeManager::update(float dt)
{
    
    CCObject* obj = NULL;
    //cake = NULL;
    Score* score = NULL;
    int number = score->showScore();
    if (number > curScore)
    {
        CCARRAY_FOREACH(m_cakeArr, obj)
        {
            cake = (Cake*) obj;
            cake->setVisible(false);
            cake->m_isAlive=false;
        }
        createCakes(cakeNum);
        curScore += 80;
    }
    
    
    CCARRAY_FOREACH(m_cakeArr, obj)
    {
        cake = (Cake*) obj;
        
        if (cake->isAlive()) {
            cake->setPositionY(cake->getPositionY() - 10);
            
            if (cake->getPositionY() < 200) {
                cake->hide();
            }
            else if (cake->isCollideWithPlayer(m_player)){
                m_player->hit();
                score->changeScore(2);
                score->changeScore(3);
                cake->hide();
            }
        }
        else {
            cake->show();
        }
    }
}

void CakeManager::bindPlayer(Player *player)
{
    this->m_player = player;
    this->m_player->retain();
}