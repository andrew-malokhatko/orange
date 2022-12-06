#include "Projectiles/Projectile.h"
#include <iostream>

Projectile::Projectile(Hero* attacker, Position from, Position to)
{
    this->attacker = attacker;
    posFrom = from;
    posTo = to;
}

Projectile::~Projectile()
{
    attacker = nullptr;
    delete attacker;
    
    projctileSprite->removeFromParent();
}

double Projectile::toActualAngle(double angle)
{
    // changing direction of the circle and rotating 0deg to position of 90 deg
    double actualAngle = (360 - angle + 90);

    // removing angles more than 360deg
    actualAngle = actualAngle > 360 ? actualAngle - 360 : actualAngle;

    return actualAngle;

}

double Projectile::calculateAngle(const Position& origin, const Position& point) const
{
    // Calculate the differences in x and y coordinates
    double d_x = point.x - origin.x;
    double d_y = point.y - origin.y;

    // Use the atan2 function to calculate the angle in radians
    double angleRadian = std::atan2(d_y, d_x);

    // Convert the angle to degrees
    double angleDegrees = angleRadian * 180 / 3.1415;

    // Make sure the angle is within the range 0-360
    angleDegrees = angleDegrees < 0 ? angleDegrees + 360 : angleDegrees;
    return angleDegrees;
}

double Projectile::toRadians(double angle)
{
    return angle * 0.017453;
}

bool Projectile::process(float dt)
{
    duration -= dt * 1000;
    if (duration < 0)
    {
        return false;
    }
    return true;
}