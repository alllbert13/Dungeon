#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter: public Object
{
private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
    int hungry;
    int thirsty;
    int money;
public:
    GameCharacter();
    GameCharacter(string, string, int,int,int, int);
    bool checkIsDead();
    void takeDamage(int);

    /* Set & Get function*/
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setHungry(int);
    void setThirsty(int);
    void setMoney(int);
    int getMaxHealth();
    int getMoney();
    int getCurrentHealth();
    int getAttack();
    int getDefense();
    int getHungry();
    int getThirsty();

};
#endif // GAMECHARACTER_H_INCLUDED
