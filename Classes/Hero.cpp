#include "Hero.h"
#include "Attacks/BubuhAttack.h"

Hero::Hero(cocos2d::Node* scene)
{
    sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
    target->setPosition(1500, 500);
    test->setPosition(pos.x, pos.y);
    sprite->setPosition(pos.x, pos.y);
    scene->addChild(target);
    scene->addChild(sprite);
    scene->addChild(test);
}

Attack* Hero::attack(Position mousePos)
{
    return new BubuhAttack(this, mousePos, Position{1500, 500}); // change consts + add attack!!!!
}

cocos2d::Node* Hero::getNode()
{
    return sprite;
}

Position Hero::getPosition()
{
    return pos;
} 