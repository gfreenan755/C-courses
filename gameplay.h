#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <iostream>
#include "gameobject.h"
#include "player.h"
#include "monster.h"
#include "gameboard.h"

class Gameplay
{
public:
    Gameplay();

    void battle_event(Player* player, Monster* monster){

        if((player->getX() == monster->getX()) && (player->getY() == monster->getY()))
        {
            while(1){
            if(player->getHP() <= 0 ){
                cout<<"GAME OVER\n";
                break;
            }
            if(monster->getHP() <= 0 ){
                cout<<"MONSTER "<<monster->getName()<<" DEFEATED \n";
               // monster.~Monster();
                break;
            }
            player->setHP(player->getHP() - monster->getATK());
            monster->setHP(monster->getHP() - player->getATK());
            cout<<"PLAYER HP = "<<player->getHP()<<" MONSTER HP = "<<monster->getHP()<<"\n";
            }
        }

    }

    void board_event(char userInput, Player* ply, GameBoard* board){

        int x = 0,y = 0;
        if (userInput == 's') {
            x = ply->getX();
            y = ply->getY()+1;
        } else if (userInput == 'd') {
            x = ply->getX()+1;
            y = ply->getY();
        } else if (userInput == 'a') {
            x = ply->getX()-1;
            y = ply->getY();
        } else if (userInput == 'w') {
            x = ply->getX();
            y = ply->getY()-1;
        }
        if(x > GameBoard::maxX){
            x = GameBoard::maxX;
            cout<<"LIMIT_X+"<<"\n";
        }
        else{
            if(x < 0){
                x = 0;
                cout<<"LIMIT_X-"<<"\n";
            }
        }

        if(y > GameBoard::maxY){
            y = GameBoard::maxY;
            cout<<"LIMIT_Y+"<<"\n";
        }
        else{
            if(y < 0){
                y = 0;
                cout<<"LIMIT_Y-"<<"\n";
            }
        }


        //cout<<x<<"   "<<y<<endl;

            if (board->WATER[x][y]==1){
                    cout<<"WATER"<<endl;
            }
            else {
                if(board->WOOD[x][y]==1){
                    cout<<"WOOD"<<endl;
                }
                else{

                    ply->setpos(x,y);

                }

                }

            }
};

#endif // GAMEPLAY_H
