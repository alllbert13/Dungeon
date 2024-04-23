#include "Dungeon.h"
#include "Item.h"
#include "NPC.h"
#include "Monster.h"
#include "Player.h"

Dungeon::Dungeon(){
};
void Dungeon::createPlayer(){
    std::cout << "player name: " ;
    string name;
    cin >> name;
    player.setName(name);
}
void Dungeon::createMap(){

}

void Dungeon::startGame(){
    createPlayer();
    createMap();
}
void Dungeon::runDungeon(){
    Meet meet1(2);
    Sword frompig(2);
    Monster pig("pig", 5, 1, 1, 2, {&meet1});
    Room room1("swamp", 1, {&pig, &frompig});  
    rooms.push_back(room1); 
    player.setCurrentRoom(&room1);
    player.setInventory({&meet1});
    createPlayer();
    int command;
    while(checkGameLogic()){
        checkStata();
        int length = player.getCurrentRoom()->getObjects().size();
        showCommand();
        std::cin >> command;
        if(command > player.getCurrentRoom()->getObjects().size() && command <= player.getCurrentRoom()->getObjects().size() + 6){
            if(command == length + 1){
                player.showStates();
            }
            else if(command == length + 2){
                player.checkBag();
            }
            else if(command == length + 3){
                player.forward();
            }
            else if(command == length + 4){
                player.back();
            }
            else if(command == length + 5){
                player.left();
            }
            else{
                player.right();
            }
            afterWork();
        }
        else if(command <= player.getCurrentRoom()->getObjects().size() && command >= 1){
            player.getCurrentRoom()->getObjects()[command - 1]->takeItem(&player);
            player.getCurrentRoom()->getObjects().erase(player.getCurrentRoom()->getObjects().begin() + command - 1);
            afterWork();
        }
        else{
            std::cout << "invalid command" << std::endl;
        }
    }
    endGame();
}

void Dungeon::endGame(){
    if(player.getCurrentHealth() > 0)
        std::cout << "you win";
    else 
        cout << "you die" << endl;
}   

void Dungeon::showCommand(){
    int length = player.getCurrentRoom()->getObjects().size();
    for(int i = 0; i < length; i++){
        player.getCurrentRoom()->getObjects()[i]->presentItem();
        std::cout << " " << i + 1 << std::endl;
    }
    cout << "show states " << length + 1 << std::endl;
    cout << "check bag " << length + 2 << std::endl;
    cout << "forward " << length + 3 << std::endl;
    cout << "backward " << length + 4 << std::endl;
    cout << "go left " << length + 5 << std::endl;
    cout << "go right " << length + 6 << std::endl;
}

bool Dungeon::checkGameLogic(){
    if(player.getCurrentHealth() <= 0){
        return 0;
    }
    if(player.gethead() == 6){
        return 0;
    }
    return 1;
}

void Dungeon::afterWork(){
    if(player.getThirsty() <= 0 || player.getHungry() <= 0){
        player.takeDamage(1);
        if(player.getThirsty() <= 0 && player.getHungry() <= 0){
        }
        else if(player.getThirsty() <= 0 && player.getHungry() > 0){
            player.setHungry(player.getHungry() - 1);
            cout << "you got 1 damage because you're thirsty" << endl;
        }
        else if(player.getThirsty() > 0 && player.getHungry() <= 0){
            if(player.getThirst()){
                if(player.getThirsty() == 1)
                    player.setThirsty(0);
                else{
                    player.setThirsty(player.getThirsty() - 2);
                }
            }
            else{
                player.setThirsty(player.getThirsty() - 1);
            }
            cout << "you got 1 damage because you're hungry" << endl;
        }
        if(player.getPoison()){
            cout << "you are poisoned " << endl << "you got 1 damage" << endl;
        }
        return;
    }
    else{
        player.setHungry(player.getHungry() - 1);
        player.setThirsty(player.getThirsty() - 1);
        if(player.getThirst()){
            player.setThirsty(player.getThirsty() - 1);
        }
        if(player.getPoison()){
            player.takeDamage(1);
        }
    }
}

void Dungeon::checkStata(){
    if(player.getCurrentHealth() <= 2){
        cout << "your life: " << player.getCurrentHealth() << endl; 
    }
    if(player.getThirsty() <= 2){
        cout << "your thirsty: " << player.getThirsty() << endl;
    }
    if(player.getHungry() <= 2){
        cout << "your hungry: " << player.getHungry() << endl;
    }
}