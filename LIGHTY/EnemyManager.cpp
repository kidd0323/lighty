//
//  EnemyManager.cpp
//  JUMP
//
//  Created by Liang Shi on 3/3/14.
//
//

#include "EnemyManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Score.h"

EnemyManager::EnemyManager()
{
    m_enemyArr = NULL;
}

EnemyManager::~EnemyManager()
{
    CC_SAFE_DELETE(m_enemyArr);
}

bool EnemyManager::init()
{
    bool bRet = false;
    do {
        createEnemies(enemyNum);
        
        this->scheduleUpdate();
        bRet = true;
    } while (0);
    
    return bRet;
}

void EnemyManager::createEnemies(int enemyNum)
{
    m_enemyArr = CCArray::create();
    m_enemyArr->retain();
    
    enemy = NULL;
    
    for (int i = 0; i < enemyNum; i++)
    {
        enemy = Enemy::create();
        
        int number = CCRANDOM_0_1() * 6;
        
        switch (number) {
            case 0:
                enemy->bindSprite(CCSprite::create("worm1.png"));
                break;
                
            case 1:
                enemy->bindSprite(CCSprite::create("worm2.png"));
                break;
            case 2:
                enemy->bindSprite(CCSprite::create("worm3.png"));
                break;
            case 3:
                enemy->bindSprite(CCSprite::create("worm4.png"));
                break;
            case 4:
                enemy->bindSprite(CCSprite::create("worm5.png"));
                break;
            case 5:
                enemy->bindSprite(CCSprite::create("worm6.png"));
                break;
        }
        
        enemy->reset();
        
        this->addChild(enemy);
        
        m_enemyArr->addObject(enemy);
    }
}

void EnemyManager::update(float dt)
{
    
    CCObject* obj = NULL;
    //Enemy* enemy = NULL;
    Score* score = NULL;
    int number = score->showScore();
    if (number > curScore && !enemyProduced)
    {
        CCARRAY_FOREACH(m_enemyArr, obj)
        {
            enemy = (Enemy*) obj;
            enemy->setVisible(false);
            enemy->m_isAlive = false;
        }
        if (curScore > 1000) {
            enemyNum += 1;
            if (enemyNum >= 6) {
                enemyNum = 6;
            }
        }
    
        createEnemies(enemyNum);
        curScore += 200;

    }
        
    CCARRAY_FOREACH(m_enemyArr, obj)
    {
        enemy = (Enemy*) obj;
        
        if (enemy->isAlive()) {
            enemy->setPositionY(enemy->getPositionY() - 4);
            
            if (enemy->getPositionY() < 200) {
                enemy->hide();
            }
            else if (enemy->isCollideWithPlayer(m_player)){
                score->changeScore(4);
                enemy->hide();
            }
        }
        else {
            enemy->show();
        }
    }
}

void EnemyManager::bindPlayer(Player *player)
{
    this->m_player = player;
    this->m_player->retain();
}