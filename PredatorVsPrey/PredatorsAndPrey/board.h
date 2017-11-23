#ifndef BOARD_H
#define BOARD_H
#include "creature.h"
#include "predator.h"
#include "prey.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <SFML/Graphics.hpp>





class Board
{
public:
    Board(int PredatorCount, int PreyCount);

    ~Board();

    void ResetGameBoard(int PredatorCount, int PreyCount);

    void Step();

    void MoveCreatures();

    void BreedCreatures();

    void KillStarvingCreatures();

    void UpdateMovedGraphic();

    void Show();

    sf::RectangleShape myGameBoardGraphic[MAX_HEIGHT][MAX_HEIGHT];
private:
    Creature* myGameBoard[MAX_HEIGHT][MAX_HEIGHT];

};

#endif // BOARD_H
