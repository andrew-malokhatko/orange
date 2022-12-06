#include "Attacks/BubuhAttack.h"
#include "Projectiles/HomingBullet.h"
#include "Projectiles/DeathRay.h"

BubuhAttack::BubuhAttack (Hero* attacker, Position from, Position to) : Attack (attacker, from, to)
{
    duration = 2000;
    onStart();
}

BubuhAttack::~BubuhAttack()
{

}

void BubuhAttack::onStart()
{
    //for (int i = 0; i < 20000; i++)
    //{
    projectiles.push_back(new DeathRay(attacker, posFrom, posTo));
    //projectiles.push_back(new HomingBullet(attacker, posFrom, posTo));
    //}
}

bool BubuhAttack::process(float dt)
{
    /*if (duration > 0)
    {
        projectiles.push_back(new (attacker, posFrom, posTo));
    }*/
    return Attack::process(dt);
}

void BubuhAttack::draw()
{
    return;
}