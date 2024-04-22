#include "GameCharacter.h"

GameCharacter::GameCharacter() : Object("empty", "character"), maxHealth(0), currentHealth(0), attack(0), defense(0), hungry(0), thirsty(0) {}
GameCharacter::GameCharacter(string name, string type, int maxHealth, int attack, int defense, int Money) : Object(name,type), maxHealth(maxHealth), currentHealth(maxHealth), attack(attack), defense(defense), hungry(8), thirsty(8), money(Money){}

bool GameCharacter::checkIsDead(){
    if(currentHealth == 0){
        return true;
    }
    return false;
}

void GameCharacter::takeDamage(int damage){
    if(currentHealth >= damage){
        currentHealth -= damage; 
    }
    else{
        currentHealth = 0;
    }
    
}


void GameCharacter::setMaxHealth(int health) {
    maxHealth = health;
}

void GameCharacter::setCurrentHealth(int health) {
    currentHealth = health;
}

void GameCharacter::setAttack(int newAttack) {
    attack = newAttack;
}

void GameCharacter::setDefense(int newDefense) {
    defense = newDefense;
}

void GameCharacter::setHungry(int newHungry) {
    hungry = newHungry;
}

void GameCharacter::setThirsty(int newThirsty) {
    thirsty = newThirsty;
}

void GameCharacter::setMoney(int Money){
    money = Money;
}
int GameCharacter::getMaxHealth() {
    return maxHealth;
}

int GameCharacter::getCurrentHealth() {
    return currentHealth;
}

int GameCharacter::getAttack() {
    return attack;
}

int GameCharacter::getDefense() {
    return defense;
}

int GameCharacter::getHungry() {
    return hungry;
}

int GameCharacter::getThirsty() {
    return thirsty;
}
int GameCharacter::getMoney(){
    return money;
}

