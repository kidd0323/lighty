//
//  CloudManager.h
//  JUMP
//
//  Created by Liang Shi on 2/26/14.
//
//

#define MAX_CLOUD_NUM 3

#ifndef __JUMP__CloudManager__
#define __JUMP__CloudManager__

#include "cocos2d.h"
USING_NS_CC;


class Player;
class CloudManager : public CCNode
{
public:
    CloudManager();
    ~CloudManager();
    
    CREATE_FUNC(CloudManager);
    virtual bool init();
    
    virtual void update(float dt);
    
private:
    void createClouds();
    int getRand(int start,int end);
    cocos2d::CCAnimate* createAnimation();
    
private:
    CCArray* m_cloudArr;
};

#endif /* defined(__JUMP__CloudManager__) */
