#include "Player.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include <random>


Player::Player(){
    maxHealth = 30;
    currentHealth = 30;
    hungry = 30;
    thirsty = 30;
    defense = 2;
    attack = 5;
    previousRoom = nullptr;
    money = 0;
    inventory = {};
    poison = false;
    Thirst = false;
    sword = nullptr;
    armor = nullptr;
    head = 0;
    hunger = false;
};

Player::Player(string Name){
    name = Name;
    maxHealth = 30;
    currentHealth = 30;
    hungry = 30;
    thirsty = 30;
    defense = 2;
    attack = 3;
    previousRoom = nullptr;
    money = 0;
    inventory = {0};
    poison = false;
    Thirst = false;
    sword = nullptr;
    armor = nullptr;
    head = 0;
    hunger = false;
}
void Player::addItem(Item* newItem){
    if(inventory.size() >= 12){
        std::cout << "your bag is full";
        return;
    }
    inventory.push_back(newItem);
}
void Player::deleteItem(Item* item){
    for(int i = 0; i < inventory.size(); i++){
        if(inventory[i]->getName() == item->getName()){
            currentRoom->ItemFall(inventory[i]);
            inventory.erase(inventory.begin() + i);
            break;
        }
    }
}
void Player::takeItem(Player* player){
    cout << "fuck";
}
void Player::presentItem(){
    cout << "fuck";
}

int Player::gethead(){
    return head;
}
void Player::sethead(){
    for(int i = 0; i < currentRoom->getObjects().size(); i++){
        if(currentRoom->getObjects()[i]->getTag() == "monster" || currentRoom->getObjects()[i]->getTag() == "NPC")
        return;
    }
    head ++;
}
void Player::setPoison(bool istrue){
    poison = istrue;
}

bool Player::getPoison(){
    return poison;
}
void Player::setMoney(int Money){
    money = Money;
}
int Player::getMoney(){
    return money;
}
void Player::pickupItem(Item* item){
    if(inventory.size() >= 12){
        std::cout << "your bag is full" << std::endl;
    }
    else{
        inventory.push_back(item);
        for(int i = 0; i < currentRoom->getObjects().size(); i++){
            if(currentRoom->getObjects()[i]->getName() == item->getName()){
                currentRoom->getObjects().erase(currentRoom->getObjects().begin() + i);
                break;
            }
        }
    }
}
void Player::setSword(Sword* Sword){
    if(sword == nullptr){
        sword = Sword;
    }
    else{
        sword = Sword;
    }
}

void Player::setArmor(Armor* Armor){
    if(armor == nullptr){
        armor = Armor;
    }
    
    else{
        armor = Armor;
    }
}

void Player::checkBag(){
    if(inventory.size() == 0){
        cout << "your bag is empty" << endl;
    }
    else{
        for(int i = 0; i < inventory.size(); i++){
            std::cout << inventory[i]->getName() << " " << i + 1 << std::endl;
        }
    }
    cout << endl;
    string swordName = (sword == nullptr) ? "empty" : sword->getName();
    string aromorName = (armor == nullptr) ? "empty" : armor->getName();
    cout << "sword: " << swordName << " " << inventory.size() + 1 <<endl;
    cout << "armor: " << aromorName << " " << inventory.size() + 2 << endl << endl;
    std::cout << "-1 to quit" << std::endl;
    int command;
    while (std::cin >> command)
    {
        /* code */
        if(command == -1){
            return;
        }
        // invalid
        else if(command >= inventory.size() + 3 || command == 0 || command <= -2){
            std::cout << "invalid input" << std::endl;
        }
        else if(command == inventory.size() + 1){
            if(sword == nullptr){
                cout << "you don't have sword" << endl << endl;
                return;
            }
            if(inventory.size() >= 12){
                cout << "your bag is full, if you unequip sword, it will be discarded." << endl << "Y to discard, n to cancel action" << endl;
                string input;
                input = "empty";
                while(input != "Y" && input != "n"){
                    cin >> input;
                    if(input == "Y"){
                        currentRoom->ItemFall(sword);
                        sword == nullptr;
                    }
                    else{
                        break;       
                    }
                }
            }
            else{
                inventory.push_back(sword);
                sword = nullptr;
            }
        }
        else if(command == inventory.size() + 2){
            if(armor == nullptr){
                cout << "you don't have armor" << endl;
                return;
            }
            if(inventory.size() >= 12){
                cout << "your bag is full, if you unequip armor, it will be discarded." << endl << "Y to discard, n to cancel action" << endl;
                string input;
                input = "empty";
                while(input != "Y" && input != "n"){
                    cin >> input;
                    if(input == "Y"){
                        currentRoom->ItemFall(armor);
                        armor = nullptr;
                    }
                    else{
                        break;       
                    }
                }
            }
            else{
                inventory.push_back(armor);
                armor = nullptr;
            }
        }
        // use item
        else{
            std::cout << "use 1" << std::endl << "delete 2" << std::endl;
            int command2 = -1;
            while(command2 != 1 && command2 != 2){
                cin >> command2;
                if(command2 != 1 && command2 != 2){
                    std::cout << "invalid input" << std::endl << endl;
                }
                else if(command2 == 1){
                    inventory[command - 1]->useItem(this);
                    inventory.erase(inventory.begin() + command - 1);
                }
                else if(command2 == 2){
                    currentRoom->ItemFall(inventory[command - 1]);
                    inventory.erase(inventory.begin() + command - 1);
                }
            }
        }
        if(inventory.size() == 0){
            cout << "your bag is empty" << endl;
        }
        else{
            for(int i = 0; i < inventory.size(); i++){
                std::cout << inventory[i]->getName() << " " << i + 1 << std::endl;
            }
        }
        cout << endl;
        string swordName = (sword == nullptr) ? "empty" : sword->getName();
        string aromorName = (armor == nullptr) ? "empty" : armor->getName();
        cout << "sword: " << swordName << " " << inventory.size() + 1 <<endl;
        cout << "armor: " << aromorName << " " << inventory.size() + 2 << endl << endl;
        std::cout << "-1 to quit" << std::endl;

    }  
}

void Player::showStates(){
    cout << endl << endl << endl;
    cout << "name: " << this->getName() << std::endl;
    cout << "money: " << this->getMoney() << endl;
    cout << "attack value: " << this->getfinalAttack() << std::endl;
    cout << "defence value: " << this->getfinalDefense() << std::endl;
    cout << "current health: " << this->getCurrentHealth() << std::endl;
    cout << "max health: " << this->getMaxHealth() << std::endl;
    cout << "current room: " << this->getCurrentRoom()->getIndex() << " "  << this->getCurrentRoom()->getType() << std::endl;
    if(armor == nullptr){
        cout << "armor: empty" << endl;
    }
    else
        cout << "armor: " << this->getArmor()->getName() << std::endl;
    if(sword == nullptr)
        cout << "sword: empty" << endl;
    else
        cout << "sword: " << this->getSword()->getName() << std::endl;
    cout << "hunger: " << this->getHungry() << endl;
    cout << "thirsty: " << this->getThirsty() << endl; 
    string poisonornot = (poison)? "yes" : "no";
    string Thirstornot = (Thirst)? "yes" : "no";
    string huornot = (hunger)? "yes" : "no";
    cout << "poison: " << poisonornot << std::endl;
    cout << "hunger: " << huornot << endl; 
    cout << "thirsty: " << Thirstornot << endl;
    cout << "room compeleted: " << head << std::endl;
}
int Player::getfinalAttack(){
    if(this->getThirsty() <= 0 || this->getHungry() <= 0){
        if(sword != nullptr){
            return attack + 1;
        }
        return attack - 1;
    }
    if(sword != nullptr){
        return attack + 2;
    }
    return attack;
}
int Player::getfinalDefense(){
    if(armor != nullptr){
        return defense + 2;
    }
    return defense;
}

Sword* Player::getSword() {
    return sword;
}

Armor* Player::getArmor() {
    return armor;
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

void Player::setInventory(vector<Item*> items) {
    inventory = items;
}


Room* Player::getCurrentRoom() {
    return currentRoom;
}

Room* Player::getPreviousRoom() {
    return previousRoom;
}

vector<Item*>& Player::getInventory() {
    return inventory;
}


void Player::forward() {
    if(currentRoom->getUpRoom() == nullptr){
        cout << "you cannot go up" << endl;
        return;
    }
    if(currentRoom->getUpRoom()->getIndex() == 8 && head < 6){
        cout << "you cannot challenge boss before you complete all room " << endl;
        return;
    }
    else{
        previousRoom = currentRoom;
        currentRoom = currentRoom->getUpRoom();
        roomCheck();
    }
}

void Player::back() {
    if(currentRoom->getDownRoom() == nullptr){
        cout << "you cannot go down" << endl;
        return;
    }
    if(currentRoom->getDownRoom()->getIndex() == 8 && head < 6){
        cout << "you cannot challenge boss before you complete all room " << endl;
        return;
    }
    else{
        previousRoom = currentRoom;
        currentRoom = currentRoom->getDownRoom();
        roomCheck();
    }
}

void Player::right() {
    if(currentRoom->getRightRoom() == nullptr){
        cout << "you cannot go right" << endl;
        return;
    }
    if(currentRoom->getRightRoom()->getIndex() == 8 && head < 6){
        cout << "you cannot challenge boss before you complete all room " << endl;
        return;
    }
    else{
        previousRoom = currentRoom;
        currentRoom = currentRoom->getRightRoom();
        roomCheck();
    }
}

void Player::left() {
    if(currentRoom->getLeftRoom() == nullptr){
        cout << "you cannot go left" << endl;
        return;
    }
    if(currentRoom->getLeftRoom()->getIndex() == 8 && head < 6){
        cout << "you cannot challenge boss before you complete all room " << endl;
        return;
    }
    else{
        previousRoom = currentRoom;
        currentRoom = currentRoom->getLeftRoom();
        roomCheck();
    }
}
void Player::gopre(){
    if(previousRoom == nullptr){
        cout << "you are in the first room" << endl;
        return;
    }
    
    Room* temp = previousRoom;
    previousRoom = currentRoom;
    currentRoom = temp;
    roomCheck();
}

void Player::setHunger(bool h){
    hunger = h;
}

bool Player::getHunger(){
    return hunger;
}
void Player::roomCheck(){
    if(currentRoom->getType() == "swamp"){
        poison = true;
        cout << "you're in swamp, you are poisoned" << endl;
    }
    else if(currentRoom->getType() == "desert"){
        random_device rd;
        mt19937 gen(rd());
        
        // Define probabilities for each number
        double probabilities[] = {0.60, 0.20, 0.20};
        
        // Define the custom distribution
        discrete_distribution<> dis({probabilities[0], probabilities[1], probabilities[2]});

        int random_number = dis(gen) + 1; // Adding 1 to get numbers from 1 to 3
        if(random_number == 1){
            Thirst = true;
            cout << "you're in desert, your thirsty status drop dramatically";
        }
        if(random_number == 2){
            Thirst = true;
            hunger = true;
            cout << "you're in desert" << endl << "you encouter a standstorm" << endl;
            cout << "your thirsty and hunger status drop dramatically" << endl;
        }
        if(random_number == 3){
            cout << "you stumble upon an oasis in the desert, replenish your thirst status" << endl;
            thirsty = 30;
        }
    }
    else if(currentRoom->getType() == "forest"){
        random_device rd;
        mt19937 gen(rd());

        // Define probabilities for each number
        double probabilities[] = {0.70, 0.30};

        // Define the custom distribution
        discrete_distribution<> dis({probabilities[0], probabilities[1]});

        // Generate random number
        int random_number = dis(gen) + 1; // Adding 1 to get numbers from 1 to 2
        if(random_number == 1){
            cout << "you're in forest, your thirsty and hunger status drop dramatically" << endl;
            hunger = true;
        }
        else if(random_number == 2){
            cout << "you stumble upon a lake in the forest, replenish your thirst status" << endl;
            thirsty = 30;
        }
        hunger = true;
    }
    if(currentRoom->getType() != "desert"){
        Thirst = false;
    }
    if(currentRoom->getType() != "forest"){
        hunger = false;
    }
}

bool Player::getThirst(){
    return Thirst;
}
void Player::setThirst(bool istrue){
    Thirst = istrue;
}


bool Player::checkIsDead(){
    if(currentHealth <= 0){
        return true;
    }
    return false;
}

void Player::takeDamage(int Damage){
    if(currentHealth - Damage > 0)
        currentHealth = currentHealth - Damage;
    else
        currentHealth = 0;
}


void Player::setMaxHealth(int health) {
    maxHealth = health;
}

void Player::setCurrentHealth(int health) {
    currentHealth = health;
}

void Player::setAttack(int newAttack) {
    attack = newAttack;
}

void Player::setDefense(int newDefense) {
    defense = newDefense;
}

void Player::setHungry(int newHungry) {
    hungry = newHungry;
}

void Player::setThirsty(int newThirsty) {
    thirsty = newThirsty;
}
int Player::getMaxHealth() {
    return maxHealth;
}

int Player::getCurrentHealth() {
    return currentHealth;
}

int Player::getAttack() {
    return attack;
}

int Player::getDefense() {
    return defense;
}

int Player::getHungry() {
    return hungry;
}

int Player::getThirsty() {
    return thirsty;
}

string Player::getName(){
    return name;
}

void Player::setName(string Name){
    name = Name;
}
