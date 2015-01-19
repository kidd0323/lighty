//
//  config.h
//  JUMP
//
//  Created by Liang Shi on 2/27/14.
//
//

#ifndef JUMP_config_h
#define JUMP_config_h

#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
using namespace extension;

int m_fScore;
CCLabelTTF* m_scoreLab;

float m_fBlood;
CCControlSlider* m_blood;

int currentScore;

CCSprite* warning;

#endif