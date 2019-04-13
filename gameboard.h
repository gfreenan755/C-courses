#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iostream>


using namespace std;



class GameBoard
{
public:
    GameBoard();

    static const int maxX = 10;
    static const int maxY = 10;

    bool WATER[11][11];
    bool WOOD[11][11];




};

#endif // GAMEBOARD_H
