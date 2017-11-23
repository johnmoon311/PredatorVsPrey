#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>

const int MAX_WIDTH=75;
const int MAX_HEIGHT=75;

const int SCREEN_HEIGHT=800;
const int SCREEN_WIDTH=900;
const int BOX_SIZE=10;

struct Position{
    int x;
    int y;

    Position(){
        x=-1;
        y=-1;
    }

    Position(int userX, int userY){
        x=userX;
        y=userY;
    }

    void setPosition(int userX, int userY){
        x=userX;
        y=userY;
    }


};

class Creature
{
public:
    Creature(int x, int y, char inputFace);

    void SetCeaturePosition(int x, int y);

    void setHasMoved();

    bool getHasMoved();

    char GetCreatureFace();

    bool isInBound(Position userPosition);

    Position FindFood(Creature* board[][MAX_WIDTH]);

    Position FindFreeSpace(Creature* board[][MAX_WIDTH]);

    void MoveToPosition(Creature* board[][MAX_WIDTH], Position newPosition);

    virtual void Move(Creature* board[][MAX_WIDTH])=0;

    virtual void Breed(Creature* board[][MAX_WIDTH])=0;

    virtual void Die(Creature* board[][MAX_WIDTH])=0;

    void KillCreature(Creature *board[][MAX_WIDTH]);

private:
    Position creaturePosition;
    bool hasMoved;
    char creatureface;


};

#endif // CREATURE_H
