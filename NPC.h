#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"

class Player;
class Item;
using namespace std;

class NPC: public GameCharacter
{
private:
    string script;
    vector<Item*> commodity;
public:
    NPC();
    NPC(string, string, int, vector<Item*>);
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    /* Set & Get function*/
    void setScript(string);
    void setCommodity(vector<Item*>);
    void itemChange(Player*);
    void presentItem();
    string getScript();
    vector<Item*> getCommodity();
};

class Sphinx: public NPC
{
public:
    Sphinx();
    void takeItem(Player* player);
};

class farmer: public NPC
{
public:
    farmer();
    void takeItem(Player* player);
};

class chef: public NPC
{
public:
    chef();
    void takeItem(Player* player);
};


#endif // NPC_H_INCLUDED
