#include "predator.h"

Predator::Predator(int x, int y, char face):Creature(x, y, face)
{
    starveMoveTurns=0;
    PredatorbreedMoveTurns=0;

}


void Predator::Move(Creature* board[][MAX_WIDTH]){

    if(Creature::getHasMoved()==false){

        Position foodPosition=Creature::FindFood(board);

        PredatorbreedMoveTurns++;

        if(Creature::isInBound(foodPosition)){

            Creature::MoveToPosition(board, foodPosition);
            starveMoveTurns=0;



        }
        else{

            Position freePosition=Creature::FindFreeSpace(board);

            if(Creature::isInBound(freePosition)){

                Creature::MoveToPosition(board, freePosition);
                starveMoveTurns++;


            }
        }
    }
}

void Predator::Breed(Creature* board[][MAX_WIDTH]){
    Creature::setHasMoved();

    if(PredatorbreedMoveTurns==8){
        Position freePosition=Creature::FindFreeSpace(board);

        if(Creature::isInBound(freePosition)){

            board[freePosition.y][freePosition.x]=new Predator(freePosition.x, freePosition.y, 'P');
        }

        PredatorbreedMoveTurns=0;
    }
}

void Predator::Die(Creature* board[][MAX_WIDTH]){
    if(starveMoveTurns==3){
        KillCreature(board);
    }
}
