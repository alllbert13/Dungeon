#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "GameCharacter.h"
#include "NPC.h"

using namespace std;

class Room
{
private:
    string type;
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    int index;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room();
    Room(string, int, vector<Object*>);

    /* Set & Get function*/
    void ItemFall(Item*);
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<Object*>);
    bool getIsExit();
    int getIndex();
    string getType(){
        return type;
    }
    void setType(string Type){
        type = Type;
    }
    vector<Object*> getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
};

#endif // ROOM_H_INCLUDED
