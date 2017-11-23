#include <iostream>
#include "board.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{   srand(time(NULL));
    int startHunters=75;
    int startPrey=200;
    Board mygameBoard(startHunters, startPrey);


    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Predator VS Prey");
    window.setFramerateLimit(10);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code==sf::Keyboard::Escape){
                    window.close();
                }
                else if(event.key.code==sf::Keyboard::Return){
                    mygameBoard.ResetGameBoard(startHunters, startPrey);
                }
            }

        }
        mygameBoard.Step();

        window.clear(sf::Color::Black);

        for(int i=0; i<MAX_HEIGHT; i++){
            for(int j=0; j<MAX_WIDTH; j++){
                window.draw(mygameBoard.myGameBoardGraphic[i][j]);
            }
        }


        window.display();
    }







    cout << "\n\n====================================================\n\n" << endl;
    return 0;
}

