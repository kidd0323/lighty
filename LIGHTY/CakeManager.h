//
//  CakeManager.h
//  JUMP
//
//  Created by Liang Shi on 2/27/14.
//
//

#ifndef __JUMP__CakeManager__
#define __JUMP__CakeManager__

#define MAX_CAKE_NUM 3

#include "cocos2d.h"
#include "Cake.h"
USING_NS_CC;


class Player;
class CakeManager : public CCNode
{
public:
    CakeManager();
    ~CakeManager();
    
    CREATE_FUNC(CakeManager);
    virtual bool init();
    
    virtual void update(float dt);
    void bindPlayer(Player* player);
    
private:
    void createCakes(int cakeNum);
    
private:
    CCArray* m_cakeArr;
    Player* m_player;
    Cake* cake;
    //bool cakeProduced = false;
    int curScore = 80;
    int cakeNum = 3;
};

#endif /* defined(__JUMP__CakeManager__) */
