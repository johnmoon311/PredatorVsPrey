#include "prey.h"

Prey::Prey(int x, int y, char face):Creature(x, y, face)
{
    PreybreedMoveTurns=0;
}

void Prey::Move(Creature* board[][MAX_WIDTH]){
    if(Creature::getHasMoved()==false){
        Position freePosition=Creature::FindFreeSpace(board);
        PreybreedMoveTurns++;

        if(Creature::isInBound(freePosition)){

            Creature::MoveToPosition(board, freePosition);

        }
    }
}

void Prey::Breed(Creature* board[][MAX_WIDTH]){
    Creature::setHasMoved();

    if(PreybreedMoveTurns==3){
        Position freePosition=Creature::FindFreeSpace(board);

        if(Creature::isInBound(freePosition)){

            board[freePosition.y][freePosition.x]=new Prey(freePosition.x, freePosition.y, 'p');
        }

        PreybreedMoveTurns=0;
    }
}

void Prey::Die(Creature* board[][MAX_WIDTH]){
    //do nothing.....
}
