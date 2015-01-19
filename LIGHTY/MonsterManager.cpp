//
//  MonsterManager.cpp
//  JUMP
//
//  Created by TOKI on 14-2-25.
//
//

#include "MonsterManager.h"
#include "Player.h"
#include "Monster.h"
#include "Score.h"

MonsterManager::MonsterManager()
{
    m_monsterArr = NULL;
}

MonsterManager::~MonsterManager()
{
    CC_SAFE_DELETE(m_monsterArr);
}

bool MonsterManager::init()
{
    bool bRet = false;
    do {
        createMonsters(monsterNum);
        
        this->scheduleUpdate();
        bRet = true;
    } while (0);
    
    return bRet;
}

void MonsterManager::createMonsters(int monsterNum)
{
    m_monsterArr = CCArray::create();
    m_monsterArr->retain();
    
    monster = NULL;
    
    for (int i = 0; i < monsterNum; i++)
    {
        monster = Monster::create();
        
        int number = CCRANDOM_0_1() * 2;
        
        switch (number) {
            case 0:
                monster->bindSprite(CCSprite::create("ladder.png"));
                break;
                
            case 1:
                monster->bindSprite(CCSprite::create("ladder2.png"));
                break;
        }
        
        monster->reset();
        
        this->addChild(monster);
        
        m_monsterArr->addObject(monster);
    }
}

void MonsterManager::update(float dt)
{
    
    CCObject* obj = NULL;
    monster = NULL;
    Score* score = NULL;
    
    int number = score->showScore();
    if (number > curScore && !speedChanged) {
        speed += 1;
        CCARRAY_FOREACH(m_monsterArr, obj)
        {
            monster = (Monster*) obj;
            monster->setVisible(false);
            monster->m_isAlive = false;
        }
        if (number > 200) {
            monsterNum -= 1;
            if (monsterNum <= 3) {
                monsterNum = 3;
            }
        }
        createMonsters(monsterNum);
        curScore += 200;
        
    }
    
    
    CCARRAY_FOREACH(m_monsterArr, obj)
    {
        monster = (Monster*) obj;
        
        if (monster->isAlive()) {
            monster->setPositionY(monster->getPositionY() - speed);
            
            if (monster->getPositionY() < 200) {
                monster->hide();
            }
            else if (monster->isCollideWithPlayer(m_player)){
                //m_player->hit();
                m_player->setPositionY(monster->getPositionY() + monster->getContentSize().height);
                m_player->flagY = 1;
                //nowBottom = true;
                m_player->jumpSpeed = 300;
                
                score->changeScore(1);
                monster->hide();
            }
        }
        else {
            monster->show();
        }
    }
}

void MonsterManager::bindPlayer(Player *player)
{
    this->m_player = player;
    this->m_player->retain();
}

void MonsterManager::createScoreLab()
{
    m_fScore = 0;
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    m_scoreLab = CCLabelTTF::create("Score:0", "Arial", 35);
    m_scoreLab->setPosition(ccp(40, visibleSize.height - 50));
    m_scoreLab->setAnchorPoint(ccp(0, 1));
    this->addChild(m_scoreLab, 100);
}