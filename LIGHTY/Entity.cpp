//
//  Entity.cpp
//  JUMP
//
//  Created by Liang Shi on 2/25/14.
//
//

#include "Entity.h"

Entity::Entity()
{
    m_sprite = NULL;
}
Entity::~Entity()
{}

CCSprite* Entity::getSprite()
{
    return this->m_sprite;
}
void Entity::bindSprite(CCSprite* sprite)
{
    this->m_sprite = sprite;
    this->addChild(m_sprite);
}
