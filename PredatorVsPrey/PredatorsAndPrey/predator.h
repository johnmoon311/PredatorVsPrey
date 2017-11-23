#ifndef PREDATOR_H
#define PREDATOR_H
#include "creature.h"

class Predator:public Creature
{
public:
    Predator(int x, int y, char face);

    void Move(Creature* board[][MAX_WIDTH]);

    void Breed(Creature* board[][MAX_WIDTH]);

    void Die(Creature* board[][MAX_WIDTH]);

private:
    int starveMoveTurns;
    int PredatorbreedMoveTurns;

};

#endif // PREDATOR_H
