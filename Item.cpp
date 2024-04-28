#include "Item.h"
#include "Player.h"

Item::Item():Object("empty", "empty"){}
Item::Item(std::string Name, int Price): Object(Name, "Item"), price(Price){}
void Item::presentItem(){
    std::cout << "pick up " << this->getName();
}

int Item::getPrice(){
    return price;
}
// Item::Item(const Item& other) : Object(other) {}

void Item::takeItem(Player* player){
    if(player->getInventory().size() >= 12){
        std::cout << "your beg is full" << std::endl;
    }
    else{
        player->getInventory().push_back(this);
        std::cout << "add " << this->getName() << " to your bag" << endl << endl;
        int position;
        // for(int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++){
        //     if(player->getCurrentRoom()->getObjects()[i]->getName() == this->getName()){
        //         position = i;
        //         break;
        //     }
        // }
        // player->getCurrentRoom()->getObjects().erase(player->getCurrentRoom()->getObjects().begin() + position);

        int objectIndexToRemove = -1;
        for (int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++) {
            if (player->getCurrentRoom()->getObjects()[i]->getName() == this->getName()) {
                objectIndexToRemove = i;
                break;
            }
        }

        // 如果找到了要删除的对象的索引，则从房间对象列表中删除对象
        if(objectIndexToRemove != -1) {
            player->getCurrentRoom()->getObjects().erase(player->getCurrentRoom()->getObjects().begin() + objectIndexToRemove);
        }
    }
}
Meet::Meet(int Hungry):Item("paddy", 15), hungry(Hungry){}
int Meet::getHungry(){
    return hungry;
};
void Meet::setHungry(int Hungry){
    hungry = Hungry;
}
void Meet::useItem(Player* player){
    if(30 - player->getHungry() >= hungry){
        player->setHungry(player->getHungry() + hungry);
    }
    else{
        player->setHungry(30);
    }
}



LifePotion::LifePotion(int Healthy): Item("lifePotion", 20), health(Healthy){};
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
Sword::Sword(int atk): Item("sword", 50), attack(atk) {}

void Sword::setAttack(int atk){
    attack = atk;
}

int Sword::getAttack(){
    return attack;
}

Sword::Sword():Item("sword", 50){}

Armor::Armor():Item("armor", 50){}

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

Armor::Armor(int def): Item("armor", 50), defense(def) {}

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

HeartContainer::HeartContainer():Item("heartContainer", 70){}
void HeartContainer::useItem(Player* player){
    player->setMaxHealth(player->getMaxHealth() + 1);
}

Milk::Milk():Item("Milk", 50){}
void Milk::useItem(Player* player){
    if(!player->getPoison()){
        std::cout << "you didn't get poisoned, cannot use milk" << std::endl;
    }
    else{
        player->setPoison(false);
    }
}

WaterBolt::WaterBolt(int value): Item("waterbolt", 15){};
void WaterBolt::useItem(Player* player){
    if(30 - player->getThirsty() >= 2){
        player->setThirsty(player->getThirsty() + 2);       
    }
    else{
        player->setThirsty(30);
    }
}
animalMeat::animalMeat(): Item("animal meat", 20){}
void animalMeat::useItem(Player* player){
    cout << "replenish hungry status" << endl;
    cout << "add 5 life" << endl;
    player->setHungry(30);
    if(player->getCurrentHealth() <= player->getMaxHealth() - 5){
        player->setCurrentHealth(player->getCurrentHealth() + 5);
    }
    else{
        player->setCurrentHealth(player->getMaxHealth());
    }
}