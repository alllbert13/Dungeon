#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"


using namespace std;

int main(){
    cout << "hello world" << endl;
    Dungeon dungeon = Dungeon();
    dungeon.runDungeon();
    cout << "Hello World" << endl;
    return 0;
}
