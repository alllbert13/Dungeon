#include "Monster.h"

Monster::Monster(): GameCharacter("empty", "monster", 0, 0, 0, 0), commodity(0){}
Monster::Monster(string Name, int maxHealth, int Attack, int Defense, int Money, vector<Item*> Commodity): GameCharacter(Name, "monster", maxHealth, Attack, Defense, Money), commodity(Commodity){}
void Monster::presentItem(){
    std::cout << "fight against " << this->getName();
}
void Monster::setCommodity(vector<Item*> Items){
     commodity = Items;
}
void Monster::defeated(Player* player){
    player->setMoney(player->getMoney() + this->getMoney());
    cout << "from " << this->getName() << "earn " << this->getMoney() << std::endl;
    for(int i = 0; i < commodity.size(); i++){
        player->getCurrentRoom()->ItemFall(commodity[i]);
        cout << this->getName() << "drop a" << this->getCommodity()[i] << endl;
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
            this->setCurrentHealth(this->getCurrentHealth() - (player->getfinalAttack() * ((10 - this->getDefense()) / 10)));
            cout << "monster get damage " << (player->getfinalAttack() * ((10 - this->getDefense()) / 10)) << endl;
            player->takeDamage(((10 - this->getAttack()) * player->getfinalDefense() / 10));
            cout << "you got damage " << ((10 - this->getAttack()) * player->getfinalDefense() / 10) << endl ;
            cout << "monster life: " << this->getCurrentHealth() << endl;
            cout << "your life: " << player->getCurrentHealth() << endl;
        }
        else if(command == 2){
            player->gopre();
            break;
        }
        else{
            std::cout << "invalid input" << endl;
        }
    }
    if(player->getCurrentHealth() <= 0){
    }
    else{
        defeated(player);
    }
}

vector<Item*> Monster::getCommodity(){
    return commodity;
}