//
//  EnemyManager.h
//  JUMP
//
//  Created by Liang Shi on 3/3/14.
//
//

#ifndef __JUMP__EnemyManager__
#define __JUMP__EnemyManager__

#define MAX_ENEMY_NUM 2

#include "cocos2d.h"
#include "Enemy.h"
USING_NS_CC;


class Player;
class EnemyManager : public CCNode
{
public:
    EnemyManager();
    ~EnemyManager();
    
    CREATE_FUNC(EnemyManager);
    virtual bool init();
    
    virtual void update(float dt);
    void bindPlayer(Player* player);
    
private:
    void createEnemies(int enemyNum);
    
private:
    CCArray* m_enemyArr;
    Player* m_player;
    Enemy* enemy;
    bool enemyProduced = false;
    int curScore = 100;
    int enemyNum = 2;
    
};

#endif /* defined(__JUMP__EnemyManager__) */
