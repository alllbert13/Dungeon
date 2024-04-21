#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster: public GameCharacter
{
private:
    vector<Item*> commodity;
public:
    Monster();
    Monster(string,int,int,int, int, vector<Item*>);
    void presentItem();
    void defeated(Player*);
    void setMoney(int);
    void setCommodity(vector<Item*>);
    int getMoney();
    vector<Item*> getCommodity();
    void takeItem(Player*);
    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
};


#endif // ENEMY_H_INCLUDED
