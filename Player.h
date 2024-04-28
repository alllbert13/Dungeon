#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Sword;
class Armor;
class Item;

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Monster.h"
#include "Item.h"

using namespace std;
class Player
{
private:
    string name;
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
    int hungry;
    int thirsty;
    Room* currentRoom;
    Room* previousRoom;
    int money;
    vector<Item*> inventory;
    int maxItemlist = 12;
    bool poison;
    bool Thirst;
    Sword* sword;
    Armor* armor;
    int head;
    bool hunger;
public:
    bool getHunger();
    void setHunger(bool);
    bool checkIsDead();
    void takeDamage(int);
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


    Player();
    Player(string);
    string getName();
    void setName(string);
    int gethead();
    void setThirst(bool);
    bool getThirst();
    void sethead();
    void addItem(Item*);
    void deleteItem(Item*);
    void setPoison(bool);
    bool getPoison();
    void pickupItem(Item*);
    void setSword(Sword*);
    void setArmor(Armor*);
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */

    /* Set & Get function*/
    Sword* getSword();
    Armor* getArmor();
    void setCurrentRoom(Room*);
    void setInventory(vector<Item*>);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item*>& getInventory();
    void takeItem(Player*);
    void presentItem();
    void showStates();
    void checkBag();
    void forward();
    void back();
    void right();
    void left();
    void gopre();
    void roomCheck();
    int getfinalAttack();
    int getfinalDefense();
    bool bossCheck();
};

#endif //PLAYER_H_INCLUDED
