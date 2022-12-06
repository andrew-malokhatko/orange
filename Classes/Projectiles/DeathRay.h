#pragma onces

#include "Projectiles/Projectile.h"

class DeathRay : public Projectile
{
private:
    double angle = 0;
    double speed = 2;
    const int length = 2000;

public:
    DeathRay(Hero* attacker, Position from, Position to);
    ~DeathRay();
    bool process(float dt) override;
    void draw() override;
};