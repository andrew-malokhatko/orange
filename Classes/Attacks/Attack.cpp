#include "Attack.h"

Attack::Attack(Hero* attacker, Position from, Position to)
{
    this->attacker = attacker;
    posFrom = from;
    posTo = to;
}

// Return true if any projectiles are still being processed, false otherwise
bool Attack::process(float dt)
{
    // Decrease duration by dt * 1000 (dt is in seconds, so multiply by 1000 to convert to milliseconds)
    duration -= dt * 1000;

    bool isProcessing = false;

    for (int i = projectiles.size() - 1; i >= 0; --i)
    {
        if (!projectiles[i]->process(dt)) 
        {
            delete projectiles[i];
            projectiles.erase(projectiles.begin() + i);
        }
        else
        {
            isProcessing = true;
        }
    }

    return isProcessing;
}