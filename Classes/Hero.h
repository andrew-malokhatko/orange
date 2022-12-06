#pragma once
#include "cocos2d.h"
class Attack;

struct Position
{
    double x;
    double y;
};

class Hero
{
private:
    int hp = 100;
    Position pos = Position{500, 500};
    cocos2d::Sprite* target = cocos2d::Sprite::create("CloseNormal.png"); // shouldnt be here
    cocos2d::Sprite* sprite = cocos2d::Sprite::create("HelloWorld.png");
    cocos2d::Sprite* test = cocos2d::Sprite::create("CloseNormal.png");

public:
    Hero(cocos2d::Node* scene);
    virtual Attack* attack(Position mousePos);
    cocos2d::Node* getNode();
    Position getPosition();
    void onMouseDown(cocos2d::Event* event);
};