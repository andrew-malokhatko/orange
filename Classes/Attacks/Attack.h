#pragma once

#include "Projectiles/Projectile.h"

class Attack
{
public:
    Hero* attacker = nullptr;
    Position posFrom = Position{0,0};
    Position posTo = Position{0,0};
    std::vector<Projectile*> projectiles;
    int duration = 0;

public:
    Attack(Hero* attacker, Position from, Position to);
    virtual ~Attack() = default;
    virtual void onStart() = 0;
    virtual bool process(float dt);
    virtual void draw() = 0;
};