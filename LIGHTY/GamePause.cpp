//
//  GamePause.cpp
//  JUMP
//
//  Created by Liang Shi on 2/26/14.
//
//

#include "GamePause.h"
#include "LightyScene.h"
#include "GameStart.h"
#include "Score.h"


CCScene* GamePause::scene()
{
    CCScene *scene = CCScene::create();
    GamePause *layer = GamePause::create();
    scene->addChild(layer);
    
    return scene;
}

bool GamePause::init()
{
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCSprite* m_bgSprite = CCSprite::create("gameover.png");
    m_bgSprite->setScaleX(visibleSize.width/m_bgSprite->getContentSize().width);
    m_bgSprite->setScaleY(visibleSize.height/m_bgSprite->getContentSize().height);
    m_bgSprite->setAnchorPoint(ccp(0, 0));
    
    this->addChild(m_bgSprite, 0);
    
    CCMenuItemImage *playAgainButton = CCMenuItemImage::create("gameagain.png",
                                                           "gameagain2.png",
                                                           this,
                                                           menu_selector(GamePause::menuPlayAgain));
    
    playAgainButton->setScaleX(0.6f);
    playAgainButton->setScaleY(0.6f);
    
    playAgainButton->setPosition( ccp(170,120) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(playAgainButton, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    CCMenuItemImage *stopGameButton = CCMenuItemImage::create("stop.png",
                                                               "stop2.png",
                                                               this,
                                                               menu_selector(GamePause::menuStopGame));
    
    stopGameButton->setScaleX(0.6f);
    stopGameButton->setScaleY(0.6f);
    
    stopGameButton->setPosition( ccp(460,120) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu2 = CCMenu::create(stopGameButton, NULL);
    pMenu2->setPosition( CCPointZero );
    this->addChild(pMenu2, 1);
    
    CCLabelTTF* m_scoreLab = CCLabelTTF::create("Score: 0", "Arial", 35);
    m_scoreLab->setColor(ccc3(212, 186, 242));
    m_scoreLab->setPosition(ccp(220, 310));
    m_scoreLab->setAnchorPoint(ccp(0, 1));
    this->addChild(m_scoreLab, 3);
    
    int showScore = score->showScore();
    m_scoreLab->setString(CCString::createWithFormat("SCORE: %d", showScore)->getCString());
    
    
    return true;
}



void GamePause::menuPlayAgain(CCObject *pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(3.0f, LightyScene::scene()));
}

void GamePause::menuStopGame(CCObject *pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(3.0f, GameStart::scene()));
}