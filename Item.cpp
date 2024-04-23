#include "Item.h"
#include "Player.h"

Item::Item():Object("empty", "empty"){}
Item::Item(std::string Name): Object(Name, "Item"){}
void Item::presentItem(){
    std::cout << "pick up " << this->getName();
}

void Item::takeItem(Player* player){
    if(player->getInventory().size() >= 12){
        std::cout << "your beg is full" << std::endl;
    }
    else{
        player->getInventory().push_back(this);
        std::cout << "add " << this->getName() << " to your bag" << endl << endl;
    }
}
Meet::Meet(int Hungry):Item("meet"), hungry(Hungry){}
int Meet::getHungry(){
    return hungry;
};
void Meet::setHungry(int Hungry){
    hungry = Hungry;
}
void Meet::useItem(Player* player){
    if(8 - player->getHungry() >= hungry){
        player->setHungry(player->getHungry() + hungry);
    }
    else{
        player->setHungry(8);
    }
}



LifePotion::LifePotion(int Healthy): Item("lifePotion"), health(Healthy){};
int LifePotion::getHealth(){
    return health;
}
void LifePotion::setHealth(int Healthy){
    health = Healthy;
}
void LifePotion::useItem(Player* player){
    if(player->getMaxHealth() - player->getCurrentHealth() >= health){
        player->setCurrentHealth(player->getCurrentHealth() + health);
    }
    else{
        player->setCurrentHealth(player->getMaxHealth());
    }
}
Sword::Sword(int atk): Item("sword"), attack(atk) {}

void Sword::setAttack(int atk){
    attack = atk;
}

int Sword::getAttack(){
    return attack;
}

Sword::Sword(){}

Armor::Armor(){}

void Sword::useItem(Player* player){
    if(player == nullptr) {
        std::cout << "Invalid player" << std::endl;
        return;
    }
    if(player->getSword() == nullptr){
        player->setSword(this);
    }
    else{
        std::cout << "You have already used a sword" << std::endl;
    }
}

void Sword::remove(Player* player){
    if(player == nullptr) {
        std::cout << "Invalid player" << std::endl;
        return;
    }
    player->setSword(nullptr);
}

Armor::Armor(int def): Item("Armor"), defense(def) {}

void Armor::setDefense(int def){
    defense = def;
}

int Armor::getDefense(){
    return defense;
}

void Armor::useItem(Player* player){
    if(player == nullptr) {
        std::cout << "Invalid player" << std::endl;
        return;
    }
    if(player->getArmor() == nullptr){
        player->setArmor(this);
    }
    else{
        std::cout << "You have already used an armor" << std::endl;
    }
}

void Armor::remove(Player* player){
    if(player == nullptr) {
        std::cout << "Invalid player" << std::endl;
        return;
    }
    player->setArmor(nullptr);
}

HeartContainer::HeartContainer():Item("heartContainer"){}
void HeartContainer::useItem(Player* player){
    player->setMaxHealth(player->getMaxHealth() + 1);
}

Milk::Milk():Item("Milk"){}
void Milk::useItem(Player* player){
    if(!player->getPoison()){
        std::cout << "you didn't get poisoned, cannot use milk" << std::endl;
    }
    else{
        player->setPoison(false);
    }
}

void WaterBolt::useItem(Player* player){
    if(8 - player->getThirsty() >= 2){
        player->setThirsty(player->getThirsty() + 2);       
    }
    else{
        player->setThirsty(8);
    }
}