#pragma once

#include "Projectiles/Projectile.h"
#include <cstdlib>

class HomingBullet : public Projectile
{
private:
    double angle = 1 + std::rand() / ((RAND_MAX + 1u) / 360);
    double speed = 8 + std::rand() / ((RAND_MAX + 1u) / 8);
    double autoAimK = 2 + std::rand() % 5;
    double acceleration = 1.01;
    Position pos = Position{0, 0};

public:
    HomingBullet(Hero* attacker, Position from, Position to);
    ~HomingBullet();
    bool process(float dt) override;
    void draw() override;
};