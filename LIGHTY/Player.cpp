//
//  Player.cpp
//  JUMP
//
//  Created by Liang Shi on 2/25/14.
//
//

#include "Player.h"
#include "FlowWord.h"

Player::Player()
{
    m_isJumping = false;
}

Player::~Player(){}

bool Player::init()
{
    this->scheduleUpdate();
    return true;
}

void Player::jump()
{
    if (getSprite() == NULL) {
        return;
    }
    
    if (m_isJumping) {
        return;
    }
    
    
    m_isJumping = true;
    
    
    
    CCJumpBy* jump = CCJumpBy::create(1.5f, ccp(0, 0), 200, 1);
    CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Player::jumpEnd));
    CCActionInterval* jumpActions = CCSequence::create(jump, callFunc, NULL);
     
    getSprite()->runAction(jumpActions);
     
     
    
}

void Player::jumpEnd()
{
    m_isJumping = false;
}

void Player::hit()
{
    if (getSprite() == NULL) {
        return;
    }
    

        int number = CCRANDOM_0_1() * 3;
        
        switch (number) {
            case 0:
            {
                FlowWord* flowWord = FlowWord::create();
                this->addChild(flowWord);
                flowWord->showWord("Good Job", getSprite()->getPosition());
                break;
            }
            
            case 1:
            {
                FlowWord* flowWord = FlowWord::create();
                this->addChild(flowWord);
                flowWord->showWord("Nice", getSprite()->getPosition());
                break;
            }
            case 2:
                break;
            
        }

    

}

CCRect Player::getBoundingBox()
{
    if (getSprite() == NULL) {
        return CCRectMake(0, 0, 0, 0);
    }
    
    CCSize spriteSize = getSprite()->getContentSize();
    CCPoint entityPos = getPosition();
    
    return CCRectMake(entityPos.x - spriteSize.width / 2,
                      entityPos.y - spriteSize.height / 2,
                      spriteSize.width,
                      spriteSize.height);
}


