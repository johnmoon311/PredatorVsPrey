#ifndef PREY_H
#define PREY_H
#include "creature.h"

class Prey:public Creature
{
public:
    Prey(int x, int y, char face);

    void Move(Creature* board[][MAX_WIDTH]);

    void Breed(Creature* board[][MAX_WIDTH]);

    void Die(Creature* board[][MAX_WIDTH]);

private:
    int PreybreedMoveTurns;
};

#endif // PREY_H
