#pragma once

#include "Hero.h"

class Projectile
{
public:
    cocos2d::Sprite* projctileSprite = nullptr;
    Hero* attacker = nullptr;
    Position posFrom = Position{0,0};
    Position posTo = Position{0,0};
    int duration = 0;

public:
    double toActualAngle(double angle);
    double calculateAngle(const Position& origin, const Position& point) const;
    double toRadians(double angle);

    Projectile(Hero* attacker, Position from, Position to);
    virtual ~Projectile();
    virtual bool process(float dt);
    virtual void draw() = 0;
};