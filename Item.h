#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;
class Player;

class Item: public Object
{
private:
    int price;
public:
    Item();
    Item(string, int);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    virtual void useItem(Player*) = 0;
    /* Set & Get function*/
    void presentItem();
    int getMaxHealthy();
    void takeItem(Player*);
    void setMaxHealthy(int);
    int getPrice();
};


class Meet: public Item
{
private:
    int hungry;
public:
    Meet(int);
    void useItem(Player*);
    int getHungry();
    void setHungry(int);
};

class LifePotion: public Item
{
private:
    int health;
public:
    LifePotion(int);
    void useItem(Player*);
    int getHealth();
    void setHealth(int);
};

class WaterBolt: public Item
{
public:
    WaterBolt(int);
    void useItem(Player*);
};

class Sword: public Item
{
private:
    int attack;
public:
    Sword(int);
    Sword();
    void useItem(Player*);
    int getAttack();
    void setAttack(int);
    void remove(Player*);
};

class Armor: public Item
{
private:
    int defense;
public:
    Armor(int);
    Armor();
    void useItem(Player*);
    int getDefense();
    void setDefense(int);
    void remove(Player*);
};

class HeartContainer: public Item
{
public:
    HeartContainer();
    void useItem(Player*);
};
class Milk: public Item
{
public:
    Milk();
    void useItem(Player* player);
};

class animalMeat: public Item
{
public:
    animalMeat();
    void useItem(Player* player);
};

#endif // ITEM_H_INCLUDED
