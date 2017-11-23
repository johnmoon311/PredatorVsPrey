
#include "creature.h"

Creature::Creature(int x, int y, char inputFace):creaturePosition(x, y)
{

    hasMoved=false;
    creatureface=inputFace;

}

void Creature::SetCeaturePosition(int x, int y){
    creaturePosition.setPosition(x, y);
}

char Creature::GetCreatureFace(){
    return creatureface;
}

void Creature::setHasMoved(){
    hasMoved==false?hasMoved=true:hasMoved=false;

}

Position Creature::FindFreeSpace(Creature* board[][MAX_WIDTH]){
    Position movePosition[8];
    int count=0;

    for(int i=(creaturePosition.y-1); i<=(creaturePosition.y+1); i++){

        for(int j=(creaturePosition.x-1); j<=(creaturePosition.x+1); j++){

            if(isInBound(Position(j, i))){

                if(board[i][j]==nullptr){

                    movePosition[count].setPosition(j, i);
                    count++;

                }
            }
        }
    }

    if(count>0){
        return movePosition[rand()%count];
    }
    else{
        return Position();
    }
}

Position Creature::FindFood(Creature* board[][MAX_WIDTH]){
    Position movePosition[8];
    int count=0;

    for(int i=(creaturePosition.y-1); i<=(creaturePosition.y+1); i++){

        for(int j=(creaturePosition.x-1); j<=(creaturePosition.x+1); j++){

            if(isInBound(Position(j, i))){

                if(board[i][j]!=nullptr){

                    if(board[i][j]->GetCreatureFace()=='p'){

                        movePosition[count].setPosition(j, i);
                        count++;
                    }
                }
            }
        }
    }

    if(count>0){
        return movePosition[rand()%count];
    }
    else{
        return Position();
    }
}


bool Creature::isInBound(Position userPosition){
    if(userPosition.x>=0&&userPosition.x<MAX_WIDTH&&userPosition.y>=0&&userPosition.y<MAX_HEIGHT){
        return true;
    }
    else{
        return false;
    }
}

bool Creature::getHasMoved(){
    return hasMoved;
}


void Creature::KillCreature(Creature *board[][MAX_WIDTH]){
    delete board[creaturePosition.y][creaturePosition.x];
    board[creaturePosition.y][creaturePosition.x]=nullptr;
}


void Creature::MoveToPosition(Creature *board[][MAX_WIDTH], Position newPosition){

    if(board[newPosition.y][newPosition.x]!=nullptr){
        delete board[newPosition.y][newPosition.x];
    }

    board[newPosition.y][newPosition.x]=board[creaturePosition.y][creaturePosition.x];

    board[creaturePosition.y][creaturePosition.x]=nullptr;

    SetCeaturePosition(newPosition.x, newPosition.y);

    setHasMoved();

}
