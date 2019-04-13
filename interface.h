#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <thread>
#include "gameobject.h"
#include "player.h"
#include "monster.h"
#include "gameboard.h"
#include <mutex>

extern mutex mlock;

class Interface
{
public:
    Interface();

    void drawBoard(Player* p, Monster* m, GameBoard gb){
        while(1){
            mlock.lock();
        system("cls");
            for(int j = 0; j < GameBoard::maxY+1; ++j){
                for(int i = 0; i < GameBoard::maxX+1; ++i){

                    if (gb.WOOD[i][j] == 1){
                        cout<<'*'<<' ';
                    }
                    else if (gb.WATER[i][j] == 1) {
                        cout<<'~'<<' ';
                    }
                    else if ((p->getX() == i) && (p->getY() == j)) {
                        cout<<'O'<<' ';
                    }
                    else if ((m->getX() == i) && (m->getY() == j)) {
                        if(m->getHP() != 0){
                           cout<<'M'<<' ';
                        }else if (m->getHP() == 0) {
                           cout<<'+'<<' ';
                        }
                    }
                    else{
                        cout<<'.'<<' ';
                    }
                }
                cout<<endl;
            }
        cout<<""<<endl;
        cout<<"--------------------"<<endl;
        p->Status();
        cout<<"--------------------"<<endl;
        cout<<"Log"<<endl;
        mlock.unlock();
        this_thread::sleep_for(chrono::milliseconds(1000));
         }}
};


#endif // INTERFACE_H
