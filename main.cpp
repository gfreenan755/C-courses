#include <iostream>
#include "gameobject.h"
#include "player.h"
#include "monster.h"
#include "gameboard.h"
#include "gameplay.h"
#include "interface.h"
#include <thread>
#include <mutex>

using namespace std;
void thread_func(Gameplay gp, GameBoard gb, Player* p, Monster* m);

mutex mlock;
int main()
{


GameBoard gameboard;
Interface interface;
Gameplay gameplay;
Player* p1 = new Player(0,0,"Ivan",100,10);
Monster* m1 = new Monster(2,2,"Troll",50,5);


for(int i = 0; i <= gameboard.maxX; i++){
    for(int j = 0; j <= gameboard.maxY; j++){
    gameboard.WATER[i][j] = 0;
}}

for(int i = 7; i <= gameboard.maxX; i++){
    for(int j = 7; j <= gameboard.maxY; j++){
    gameboard.WATER[i][j] = 1;
}}

for(int i = 0; i <= gameboard.maxX; i++){
    for(int j = 0; j <= gameboard.maxY; j++){
    gameboard.WOOD[i][j] = 0;
}}

for(int i = 5; i <= gameboard.maxX; i++){
    for(int j = 0; j <= 3; j++){
    gameboard.WOOD[i][j] = 1;
}}


p1->Status();

    thread t1(&Interface::drawBoard,interface, p1, m1, gameboard);
    thread t2(thread_func, gameplay,gameboard, p1, m1);
           t1.join();
           t2.join();


while (1) {

    cout<<"main thread"<<endl;

 }

    return 0;
}
void thread_func(Gameplay gp, GameBoard gb, Player* p, Monster* m){
    char userInput;

    while(1){

        cin>>userInput;
        mlock.lock();
    gp.board_event(userInput, p, &gb);
    gp.battle_event(p,m);
    mlock.unlock();
    //this_thread::sleep_for(chrono::milliseconds(100));
    }

}
