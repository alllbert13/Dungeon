#include "NPC.h"
#include "Item.h"
#include "Room.h"
#include "Player.h"


Meet* meetShpinx1 = new Meet(2);
Meet* meetShpinx2 = new Meet(2);
HeartContainer* fromSphinx = new HeartContainer();
Milk* milkfromSphinx = new Milk();
Sword* fromfarmer = new Sword(2);

std::string FarmerScripts = "Traveler, I beseech thee! My daughter's trapped in the upper room, besieged by a fearsome beast. Can you aid her? I'll reward you with a lifesaver upon her safe return.";

std::string ChefScripst = "Chef: ""Seeking one meats for my fare. Exchange for goods. Deal?""";
Sword SwordfromChef(2);
Milk MilkfromChef;


//NPC setup
NPC::NPC() = default;
NPC::NPC(string Name, string Script, int Money, vector<Item*> items): GameCharacter(Name, "NPC", 15, 6, 8, Money), script(Script){}
void NPC::setScript(string Scripts){
    script = Scripts;
}
void NPC::setCommodity(vector<Item*> items){
    commodity = items;
}
string NPC::getScript(){
    return script;
}
vector<Item*>& NPC::getCommodity(){
    return commodity;
}
void NPC::presentItem(){
    std::cout << "talk to " << this->getName();
}


//sphinx setup
Sphinx::Sphinx():NPC("Sphinx", "Sphinx: Behold, I am the Sphinx, guardian of this realm. To pass, answer my riddle true", 10, {}) {}

void Sphinx::takeItem(Player*player){
    cout << "Sphinx: Behold, I am the Sphinx, guardian of this realm. To pass, answer my riddle true" << std::endl;
    cout << "would you take the challenge Y/n" << std::endl;
    std::string respon;
    cin >> respon;
    if(respon == "Y"){
        cout << "What is the smallest postitive number that" << std::endl << "x = 2 mod 3" << std::endl << "x = 3 mod 5" << std::endl << "x = 5 mod 7" << endl;
        std::string ans;
        cin >> ans;
        int times = 0;
        while(ans != "q"){
            if(times == 2){
                std::cout << "(press q to quit)" << std::endl;
                times == 0;
            }
            //the answer is correct
            if(ans == "23"){
                cout << "Correct! " << endl;
                player->setMoney(player->getMoney() + 10);
                std::cout << "you earn 10 dollors from Sphinx" << std::endl;
                cout << "accept reward" << std::endl;
                //take the item
                for(int i = 0; i < this->getCommodity().size(); i++){
                    cout << this->getCommodity()[i]->getName() <<" from Sphinx.";
                    //cannot take
                    if(player->getInventory().size() >= 12){
                        cout << "your bag is full";
                        player->getCurrentRoom()->ItemFall(this->getCommodity()[i]);
                    }
                    //take
                    else{
                        cout << " would you take the item Y/n" << std::endl;
                        std::string takeornot;
                        while(cin >> takeornot){
                            if(takeornot == "Y"){
                                player->getInventory().push_back(this->getCommodity()[i]);
                                break;
                            }
                            else if(takeornot == "n"){
                                player->getCurrentRoom()->ItemFall(this->getCommodity()[i]);
                                break;
                            }
                            else{
                                std::cout << "invalid input" << std::endl << "type Y to pick up the item, type n to pick up the item" << std::endl;
                            }
                        }
                        
                    }
                }
                //erase the NPC from the room
                for(int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++){
                    if(player->getCurrentRoom()->getObjects()[i]->getName() == "Sphinx"){
                         player->getCurrentRoom()->getObjects().erase(player->getCurrentRoom()->getObjects().begin() + i);
                         break;
                    }
                } 
                break;
            }
            else{
                std::cout << "the answer is wrong" << endl;
                std::cin >> ans;
            }
        }
        player->sethead();
    }
    else if(respon == "n"){
        
    }
    else {
        std::cout << "invalid input";
    }
}

//farmer setup
farmer::farmer():NPC("Famer", FarmerScripts, 4, {}){}

void farmer::takeItem(Player* player){
    std::cout << FarmerScripts << std::endl;
    bool defeat = true;
    for(int i = 0; i < player->getCurrentRoom()->getUpRoom()->getObjects().size(); i++){
        if(player->getCurrentRoom()->getUpRoom()->getObjects()[i]->getTag() == "monster"){
            defeat = false;
            break;
        }
    }
    if(defeat){
        cout << "Thank you" << std::endl;
        cout << "Here is the Sword, it can increase your attack power" << std::endl;
        std::cout << "you earn 4 dollors from farmer" << std::endl;
        player->setMoney(player->getMoney() + 4);
        if(player->getInventory().size() >= 12){
            std::cout << "your bag is full" << std::endl;
            player->getCurrentRoom()->ItemFall(fromfarmer);
            for(int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++){
                if(player->getCurrentRoom()->getObjects()[i] == this){
                    player->getCurrentRoom()->getObjects().erase(player->getCurrentRoom()->getObjects().begin() + i);
                }
            }
        }
        else{
            cout << "would you take the sword Y/n";
            string ans;
            while(cin >> ans){
                if(ans == "Y"){
                    player->getInventory().push_back(this->getCommodity()[0]);
                    cout << "you get sword from farmer" << endl;
                    for(int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++){
                        if(player->getCurrentRoom()->getObjects()[i] == this){
                            player->getCurrentRoom()->getObjects().erase(player->getCurrentRoom()->getObjects().begin() + i);
                        }
                    }
                    break;
                }
                else if(ans == "n"){
                    player->getCurrentRoom()->ItemFall(this->getCommodity()[0]);
                    for(int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++){
                        if(player->getCurrentRoom()->getObjects()[i] == this){
                            player->getCurrentRoom()->getObjects().erase(player->getCurrentRoom()->getObjects().begin() + i);
                        }
                    }
                    break;
                }
                else{
                    std::cout << "invalid input" << std::endl << "type Y to pick up item" << std::endl << "type n to dismiss item";
                }
            }
        }
        player->sethead();
    }
}

chef::chef(): NPC("Chef", ChefScripst, 8, {}){}
void chef::takeItem(Player* player){
    cout << ChefScripst << std::endl;
    bool istrue = false;
    for(int i = 0; i < player->getInventory().size(); i++){
        if(player->getInventory()[i]->getName() == "meet"){
            istrue = true;
            break;
        }
    }
    if(istrue){
        cout << "Thank you" << std::endl;
        cout << "Here are the award" << std::endl;
        std::cout << "you earn 8 dollors from chef" << std::endl;
        player->setMoney(player->getMoney() + 8);
        for(int i = 0; i < this->getCommodity().size(); i++){
            cout << this->getCommodity()[i]->getName() <<" from chef";
            //cannot take
            if(player->getInventory().size() >= 12){
                cout << "your bag is full";
                Object* ptr = dynamic_cast<Item*>(this->getCommodity()[i]);
                player->getCurrentRoom()->getObjects().push_back(ptr);
            }
            //take
            else{
                cout << " would you take the item Y/n" << std::endl;
                std::string takeornot;
                while(cin >> takeornot){
                    if(takeornot == "Y"){
                        player->getInventory().push_back(this->getCommodity()[i]);
                        break;
                    }
                    else if(takeornot == "n"){
                        player->getCurrentRoom()->getObjects().push_back(this->getCommodity()[i]);
                        break;
                    }
                    else{
                        std::cout << "invalid input" << std::endl << "type Y to pick up the item, type n to pick up the item" << std::endl;
                    }
                }              
            }
        }
        for(int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++){
            if(player->getCurrentRoom()->getObjects()[i] == this){
                 player->getCurrentRoom()->getObjects().erase(player->getCurrentRoom()->getObjects().begin() + i);
            }
        }
        player->sethead();
    }
}

Guide::Guide(): NPC("Guide", "Guide: Welcome to the dungeon! Defeat monsters, help residents, and conquer six rooms to win. But watch out! Your life decreases with each hit, and hunger or thirst weakens your attacks. Find items to boost abilities and visit the shop in the third room for supplies. Good luck!", 0, {}){}

void Guide::takeItem(Player* player){
    cout << this->getScript() << endl;
}

clerk::clerk(): NPC("clerk", "Welcome! I'm Alllbert. Here's what we've got: ", 0, {}){}

void clerk::takeItem(Player* player){
    if(this->getCommodity().size() == 0){
        cout << "everything is sold out." << endl;
        return;
    }
    for(int i = 0; i < this->getCommodity().size(); i++){
        cout << "Name: " << this->getCommodity()[i]->getName() << " Price: " << this->getCommodity()[i]->getPrice()<< "         " << i + 1 << endl;
    }
    cout << "your money: " << player->getMoney() << endl;
    cout << "-1 to quit" << endl;
    int ans;
    while(cin >> ans){
        if(ans == -1){
            return;
        }
        if(ans >= 1 && ans <= this->getCommodity().size()){
            if(player->getInventory().size() >= 12){
                cout << "your bag is full" << endl;
                return;
            }
            if(player->getMoney() < this->getCommodity()[ans - 1]->getPrice()){
                cout << "you are so poor, get more money. " << endl;
                return;
            }
            player->getInventory().push_back(this->getCommodity()[ans - 1]);
            player->setMoney(player->getMoney() - this->getCommodity()[ans - 1]->getPrice());
            cout << "add " << this->getCommodity()[ans - 1]->getName() << " to your bag" << endl;
            this->getCommodity().erase(this->getCommodity().begin() + ans - 1);
            return;
        }
        cout << "invalid input" << endl;
    }
}


Boss::Boss():  NPC("Boss", "Boss Encounter: Players face the Dark Warlord, dodging attacks and summoning allies, ultimately defeating him to save the land.", 100, {}){}

void Boss::takeItem(Player* player){
    player->setPoison(true);
    cout << this->getScript() << endl;
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
            player->takeDamage(1);
            cout << "you get 1 damage because you are poisoned" << endl;
        }
        else if(command == 2){
            //double free or corruption
            player->gopre();
            break;
        }
        else{
            std::cout << "invalid input" << endl;
        }
    }
    if(player->getCurrentHealth() <= 0){
    }
    else if(this->getCurrentHealth() <= 0){
        player->sethead();
    }
}