#ifndef PLAYER_H
#define PLAYER_H
#include "gameobject.h"


class Player : public GameObject
{
private:
    int HP;
    int ATK;

public:
    Player();

    Player(int X,
           int Y,
           string name,
           int hp,
           int atk
          ) : GameObject( X, Y, name ){
        this->HP = hp;
        this->ATK = atk;
    }

    void Status(){

    cout<<"Player "<<this->getName()<<" standing "<<this->getX()<<" "<<this->getY()<<endl;
    cout<<"HP = "<<this->getHP()<<" "<<"ATK = "<<this->getATK()<<"\n";

    }

    int getHP() {return HP;}
    int getATK() {return ATK;}

    void setHP(int hp){
        this->HP = hp;
    }
};

#endif // PLAYER_H
