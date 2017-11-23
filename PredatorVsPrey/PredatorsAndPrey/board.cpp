#include "board.h"

Board::Board(int PredatorCount, int PreyCount)
{
    for(int i=0; i<MAX_HEIGHT; i++){
        for(int j=0; j<MAX_WIDTH; j++){
            myGameBoard[i][j]=nullptr;

            myGameBoardGraphic[i][j].setSize(sf::Vector2f(BOX_SIZE-1, BOX_SIZE-1));
            myGameBoardGraphic[i][j].setOutlineColor(sf::Color::Black);
            myGameBoardGraphic[i][j].setOutlineThickness(1);
            myGameBoardGraphic[i][j].setPosition(((SCREEN_WIDTH-(MAX_WIDTH*BOX_SIZE))/2)+(j*BOX_SIZE), ((SCREEN_HEIGHT-(MAX_HEIGHT*BOX_SIZE))/2)+(i*BOX_SIZE));
            myGameBoardGraphic[i][j].setFillColor(sf::Color::Black);
        }
    }




    for(int i=0; i<PredatorCount; i++){
        bool spotIsTaken=true;

        while(spotIsTaken){
            int randPositionX=rand()%MAX_WIDTH;
            int randPositionY=rand()%MAX_HEIGHT;

            if(myGameBoard[randPositionY][randPositionX]==nullptr){

                myGameBoard[randPositionY][randPositionX]=new Predator(randPositionX, randPositionY, 'P');

                myGameBoardGraphic[randPositionY][randPositionX].setFillColor(sf::Color::Red);

                spotIsTaken=false;
            }
        }


    }


    for(int i=0; i<PreyCount; i++){
        bool spotIsTaken=true;

        while(spotIsTaken){
            int randPositionX=rand()%MAX_WIDTH;
            int randPositionY=rand()%MAX_HEIGHT;

            if(myGameBoard[randPositionY][randPositionX]==nullptr){

                myGameBoard[randPositionY][randPositionX]=new Prey(randPositionX, randPositionY, 'p');

                myGameBoardGraphic[randPositionY][randPositionX].setFillColor(sf::Color::Green);

                spotIsTaken=false;
            }
        }
    }

}

Board::~Board(){
    for(int i=0; i<MAX_HEIGHT; i++){
        for(int j=0; j<MAX_WIDTH; j++){
            if(myGameBoard[i][j]!=nullptr){
                delete myGameBoard[i][j];
            }
        }
    }
}

void Board::ResetGameBoard(int PredatorCount, int PreyCount){
    for(int i=0; i<MAX_HEIGHT; i++){
        for(int j=0; j<MAX_WIDTH; j++){
            myGameBoard[i][j]=nullptr;

            myGameBoardGraphic[i][j].setSize(sf::Vector2f(BOX_SIZE-1, BOX_SIZE-1));
            myGameBoardGraphic[i][j].setOutlineColor(sf::Color::Black);
            myGameBoardGraphic[i][j].setOutlineThickness(1);
            myGameBoardGraphic[i][j].setPosition(((SCREEN_WIDTH-(MAX_WIDTH*BOX_SIZE))/2)+(j*BOX_SIZE), ((SCREEN_HEIGHT-(MAX_HEIGHT*BOX_SIZE))/2)+(i*BOX_SIZE));
            myGameBoardGraphic[i][j].setFillColor(sf::Color::Black);
        }
    }




    for(int i=0; i<PredatorCount; i++){
        bool spotIsTaken=true;

        while(spotIsTaken){
            int randPositionX=rand()%MAX_WIDTH;
            int randPositionY=rand()%MAX_HEIGHT;

            if(myGameBoard[randPositionY][randPositionX]==nullptr){

                myGameBoard[randPositionY][randPositionX]=new Predator(randPositionX, randPositionY, 'P');

                myGameBoardGraphic[randPositionY][randPositionX].setFillColor(sf::Color::Red);
                spotIsTaken=false;
            }
        }


    }


    for(int i=0; i<PreyCount; i++){
        bool spotIsTaken=true;

        while(spotIsTaken){
            int randPositionX=rand()%MAX_WIDTH;
            int randPositionY=rand()%MAX_HEIGHT;

            if(myGameBoard[randPositionY][randPositionX]==nullptr){

                myGameBoard[randPositionY][randPositionX]=new Prey(randPositionX, randPositionY, 'p');

                myGameBoardGraphic[randPositionY][randPositionX].setFillColor(sf::Color::Green);
                spotIsTaken=false;
            }
        }
    }
}

void Board::Step(){
    MoveCreatures();

    BreedCreatures();

    KillStarvingCreatures();

    UpdateMovedGraphic();



}

void Board::UpdateMovedGraphic(){
    for(int i=0; i<MAX_HEIGHT; i++){
        for(int j=0; j<MAX_WIDTH; j++){
            if(myGameBoard[i][j]!=nullptr){
                if(myGameBoard[i][j]->GetCreatureFace()=='P'){
                    myGameBoardGraphic[i][j].setFillColor(sf::Color::Red);
                }
                else if(myGameBoard[i][j]->GetCreatureFace()=='p'){
                    myGameBoardGraphic[i][j].setFillColor(sf::Color::Green);
                }
            }
            else{
                myGameBoardGraphic[i][j].setFillColor(sf::Color::Black);
            }
        }
    }
}

void Board::MoveCreatures(){
    for(int i=0; i<MAX_HEIGHT; i++){
        for(int j=0; j<MAX_WIDTH; j++){
            if(myGameBoard[i][j]!=nullptr&&myGameBoard[i][j]->GetCreatureFace()=='P'){
                myGameBoard[i][j]->Move(myGameBoard);
            }

        }
    }

    for(int i=0; i<MAX_HEIGHT; i++){
        for(int j=0; j<MAX_WIDTH; j++){
            if(myGameBoard[i][j]!=nullptr&&myGameBoard[i][j]->GetCreatureFace()=='p'){
                myGameBoard[i][j]->Move(myGameBoard);
            }
        }
    }
}

void Board::BreedCreatures(){
    for(int i=0; i<MAX_HEIGHT; i++){
        for(int j=0; j<MAX_WIDTH; j++){
            if(myGameBoard[i][j]!=nullptr){
                myGameBoard[i][j]->Breed(myGameBoard);
            }

        }
    }
}

void Board::KillStarvingCreatures(){
    for(int i=0; i<MAX_HEIGHT; i++){
        for(int j=0; j<MAX_WIDTH; j++){
            if(myGameBoard[i][j]!=nullptr){
                if(myGameBoard[i][j]->GetCreatureFace()=='P'){
                    myGameBoard[i][j]->Die(myGameBoard);
                }
            }

        }
    }
}



void Board::Show(){
    for(int i=0; i<MAX_WIDTH; i++){
        if(i==0){
            std::cout<<"   ";
        }
        std::cout<<i<<"  ";
    }
    for(int i=0; i<MAX_HEIGHT; i++){
        std::cout<<std::endl<<i<<" ";
        for (int j=0; j<MAX_WIDTH; j++){
            if(myGameBoard[i][j]==nullptr){
                std::cout<<" . ";
            }
            else if(myGameBoard[i][j]->GetCreatureFace()=='P'){
                std::cout<<" P ";
            }
            else if(myGameBoard[i][j]->GetCreatureFace()=='p'){
                std::cout<<" # ";
            }
        }
    }
}
