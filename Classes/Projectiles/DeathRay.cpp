#include "DeathRay.h"

DeathRay::DeathRay(Hero* attacker, Position from, Position to) : Projectile(attacker, from, to)
{
    draw();
}

DeathRay::~DeathRay()
{
    
}

bool DeathRay::process(float dt)
{
    angle += speed;
    projctileSprite->setRotation(angle);
    return Projectile::process(dt);
}

void DeathRay::draw()
{
    Position attackerPos = attacker->getPosition();
    double toAngle = toActualAngle(calculateAngle(attackerPos, posTo));

    angle = toActualAngle(calculateAngle(attackerPos, posFrom));

    // Flip speed if necessary
    double diff = abs(toAngle - angle);

    if (toAngle > angle && diff > 180) {speed = -speed;}; 
    if (toAngle < angle && diff < 180) {speed = -speed;};

    // Set the duration of the death ray
    duration = 10000;

    // Create and adjust the sprite for the death ray
    projctileSprite = cocos2d::Sprite::create("DeathRay.png");
    
    projctileSprite->setAnchorPoint(cocos2d::Vec2(0.5, 0));
    projctileSprite->setRotation(angle);
    projctileSprite->setScaleY(2);
    projctileSprite->setScaleX(0.6);
    attacker->getNode()->addChild(projctileSprite);
}