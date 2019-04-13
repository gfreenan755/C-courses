#ifndef MONSTER_H
#define MONSTER_H
#include "gameobject.h"


class Monster : public GameObject
{
private:
    int HP;
    int ATK;

public:
    Monster();


    Monster(int X,
           int Y,
           string name,
           int hp,
           int atk
          ) : GameObject( X, Y, name ){
        this->HP = hp;
        this->ATK = atk;
    }

    void Status(){

    cout<<"Monster "<<this->getName()<<" HP = "<<this->getHP()<<" "<<"ATK = "<<this->getATK()<<"\n";

    }

    int getHP() {return HP;}
    int getATK() {return ATK;}

    void setHP(int hp){
        this->HP = hp;
    }
};

#endif // MONSTER_H
