#include "Monster.h"

Monster::Monster(): GameCharacter("empty", "monster", 0, 0, 0, 0), commodity({}){}
Monster::Monster(string Name, int maxHealth, int Attack, int Defense, int Money, vector<Item*> Commodity): GameCharacter(Name, "monster", maxHealth, Attack, Defense, Money), commodity(Commodity){}
void Monster::presentItem(){
    std::cout << "fight against " << this->getName();
}
void Monster::setCommodity(vector<Item*> Items){
     commodity = Items;
}
void Monster::defeated(Player* player){
    player->setMoney(player->getMoney() + this->getMoney());
    cout << "from " << this->getName() << " earn " << this->getMoney() << " dollar" << std::endl;
    for(int i = 0; i < commodity.size(); i++){
        player->getCurrentRoom()->ItemFall(commodity[i]);
        cout << this->getName() << " drop a " << this->getCommodity()[i]->getName() << endl;
    }
    for(int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++){
        if(player->getCurrentRoom()->getObjects()[i]->getName() == this->getName()){
            player->getCurrentRoom()->getObjects().erase(player->getCurrentRoom()->getObjects().begin() + i);
        };
    }  
    player->sethead(); 
}
void Monster::takeItem(Player* player){
    while(player->getCurrentHealth() > 0 && this->getCurrentHealth() > 0){
        cout << "attack 1" << std::endl << "retreat 2" << std::endl;
        int command;
        std::cin >> command;
        if(command == 1){
            int playerDamage = player->getfinalAttack() > this->getDefense() ? player->getfinalAttack() + 1 :  player->getfinalAttack() - 1;
            int monsterDamage = this->getAttack() > player->getfinalDefense() ? this->getAttack() + 1 : this->getAttack() - 1;
            this->setCurrentHealth(this->getCurrentHealth() - playerDamage);
            cout << "monster get damage " << playerDamage << endl;
            player->takeDamage(monsterDamage);
            cout << "you got damage " << monsterDamage << endl ;
            cout << "monster life: " << this->getCurrentHealth() << endl;
            cout << "your life: " << player->getCurrentHealth() << endl;
            if(player->getPoison()){
                player->takeDamage(1);
            }
        }
        else if(command == 2){
            //double free or corruption
            player->gopre();
            break;
        }
        else{
            std::cout << "invalid input" << endl;
        }
        cout << endl;
    }
    if(player->getCurrentHealth() <= 0){
    }
    else if(this->getCurrentHealth() <= 0){
        defeated(player);
    }
    //after work
        if(player->getThirsty() <= 0 || player->getHungry() <= 0){
        player->takeDamage(1);
        if(player->getThirsty() <= 0 && player->getHungry() <= 0){
            cout << "you got 1 damage because you're thirsty and hungry" << endl;
        }
        else if(player->getThirsty() <= 0 && player->getHungry() > 0){
            player->setHungry(player->getHungry() - 1);
            cout << "you got 1 damage because you're thirsty" << endl;
        }
        else if(player->getThirsty() > 0 && player->getHungry() <= 0){
            if(player->getThirst()){
                if(player->getThirsty() == 1)
                    player->setThirsty(0);
                else{
                    player->setThirsty(player->getThirsty() - 2);
                }
            }
            else{
                player->setThirsty(player->getThirsty() - 1);
            }
            cout << "you got 1 damage because you're hungry" << endl;
        }
        if(player->getPoison()){
            cout << "you are poisoned " << endl << "you got 1 damage" << endl;
        }
        return;
    }
    else{
        player->setHungry(player->getHungry() - 1);
        player->setThirsty(player->getThirsty() - 1);
        if(player->getThirst() && player->getThirsty() > 0){
            player->setThirsty(player->getThirsty() - 1);
        }
        if(player->getPoison()){
            player->takeDamage(1);
            cout << "you get 1 damage because you are poinsoned" << endl;
        }
    }
}

vector<Item*> Monster::getCommodity(){
    return commodity;
}