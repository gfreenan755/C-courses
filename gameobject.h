#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "gameboard.h"

using namespace std;


class GameObject
{
private:
    int posX,posY;
    string objName;


public:
    GameObject();

    GameObject(int X,int Y,string name)
        {

        this->posX = X;
        this->posY = Y;
        this->objName = name;

        }

    void draw(){

        cout<<objName<<" at "<<posX<<" "<<posY<<"\n";

    }

    void setpos(int x, int y){


        if((x > GameBoard::maxX) || (x < 0)){
            //posX = x;
            cout<<"LIMIT_X"<<"\n";
        }
        else{
            posX = x;
        }

        if((y > GameBoard::maxY) || (y < 0)){
            //posY = y;
            cout<<"LIMIT_Y"<<"\n";
        }
        else {
            posY = y;
        }

    }

    int getX() {return posX;}
    int getY() {return posY;}
    string getName() {return objName;}


};

#endif // GAMEOBJECT_H
