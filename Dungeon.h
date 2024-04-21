#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Room.h"
#include "Record.h"

using namespace std;

class Dungeon{
private:
    Player player;
    vector<Room> rooms;
public:
    Dungeon();
    /* Create a new player, and give him/her basic status */
    void createPlayer();
    void createMap();
    /* Create a map, which include several different rooms */

    /* Deal with player's moveing action */
    void handleMovement();

    /* Deal with player's iteraction with objects in that room */
    void handleEvent(Object*);

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();


    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void chooseAction(vector<Object*>);

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();

    void showCommand();

    /* Deal with the whole game process */
    void runDungeon();

    void endGame();
    void afterWork();
};


#endif //DUNGEON_H_INCLUDED
