//
//  MonsterManager.h
//  JUMP
//
//  Created by TOKI on 14-2-25.
//
//

#ifndef __JUMP__MonsterManager__
#define __JUMP__MonsterManager__

#define MAX_MONSTER_NUM 7

#include "cocos2d.h"
#include "Score.h"
#include "Monster.h"
USING_NS_CC;


class Player;
class MonsterManager : public CCNode
{
public:
    MonsterManager();
    ~MonsterManager();
    
    CREATE_FUNC(MonsterManager);
    virtual bool init();
    
    virtual void update(float dt);
    void bindPlayer(Player* player);
    void createScoreLab();
    
private:
    void createMonsters(int monsterNum);
    
private:
    CCArray* m_monsterArr;
    Player* m_player;
    
    int m_fScore;
    CCLabelTTF* m_scoreLab;
    int speed = 4;
    bool speedChanged = false;
    int curScore = 140;
    int monsterNum = 7;
    Monster* monster;
};

#endif /* defined(__JUMP__MonsterManager__) */
