#include "HomingBullet.h"
#include <iostream>

HomingBullet::HomingBullet(Hero* attacker, Position from, Position to) : Projectile(attacker, from, to)
{
    draw();
}

HomingBullet::~HomingBullet()
{

}


bool HomingBullet::process(float dt)
{
    double targetAngle = calculateAngle(Position{pos.x + attacker->getPosition().x, pos.y + attacker->getPosition().y}, posTo);
    pos.x += std::cos(toRadians(angle)) * speed;
    pos.y += std::sin(toRadians(angle)) * speed;
    //speed *= acceleration;

    // Wrap the angle to within 0-360 degrees
    angle = angle < 0 ? angle + 360 : angle;
    angle = angle > 360 ? angle - 360 : angle;

    // Adjust the bullet's angle to home in on the target
    double diff = abs(targetAngle - angle);
    if (targetAngle > angle)
    {
        if (diff > 180)
        {
            angle -= autoAimK;
        }
        else
        {
            angle += autoAimK;
        }
    }
    else
    {
        if (diff < 180)
        {
            angle -= autoAimK;
        }
        else
        {
            angle += autoAimK;
        }
    }

    // Update the bullet's sprite to match its new position and angle
    projctileSprite->setRotation(toActualAngle(angle));
    projctileSprite->setPosition(pos.x, pos.y);

    // Check if the bullet should be destroyed, and return the result
    return Projectile::process(dt); 
}

void HomingBullet::draw()
{
    duration = 10000;
    projctileSprite = cocos2d::Sprite::create("SpaceRocket.png");
    projctileSprite->setScale(0.2);
    attacker->getNode()->addChild(projctileSprite);
    projctileSprite->setPosition(pos.x, pos.y);
}