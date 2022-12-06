#pragma once

#include "Attacks/Attack.h"

class BubuhAttack : public Attack
{
public:
    BubuhAttack(Hero* attacker, Position from, Position to);
    virtual ~BubuhAttack() override;
    void onStart() override;
    bool process(float dt) override;
    void draw() override;

};