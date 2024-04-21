#include "NPC.h"
#include "Item.h"
#include "Room.h"
std::string SphinxScript = "Sphinx: Behold, I am the Sphinx, guardian of this realm. To pass, answer my riddle true";
Meet meetShpinx1(2);
Meet meetShpinx2(2);
HeartContainer fromSphinx;
Milk milkfromSphinx;
Sword fromfarmer;

std::string FarmerScripts = "Traveler, I beseech thee! My daughter's trapped in the upper room, besieged by a fearsome beast. Can you aid her? I'll reward you with a lifesaver upon her safe return.";

std::string ChefScripst = "Chef: ""Seeking one meats for my fare. Exchange for goods. Deal?""";
Sword SwordfromChef(2);
Milk MilkfromChef;


//NPC setup
NPC::NPC(string Name, string Script, int Money, vector<Item*> items): GameCharacter(Name, "NPC", 0, 0, 0, Money), script(Script){}
void NPC::setScript(string Scripts){
    script = Scripts;
}
void NPC::setCommodity(vector<Item*> items){
    commodity = items;
}
string NPC::getScript(){
    return script;
}
vector<Item*> NPC::getCommodity(){
    return commodity;
}
void NPC::presentItem(){
    std::cout << "talk to " << this->getName() << std::endl;
}


//sphinx setup
Sphinx::Sphinx():NPC("Sphinx", SphinxScript, 10, {&meetShpinx1, &meetShpinx2, &milkfromSphinx, &fromSphinx}) {}

void Sphinx::takeItem(Player*player){
    cout << SphinxScript << std::endl;
    cout << "would you take the challenge Y/n" << std::endl;
    std::string respon;
    cin >> respon;
    if(respon == "Y"){
        cout << "What is the smallest postitive number that" << std::endl << "x = 2 mod 3" << std::endl << "x = 3 mod 5" << std::endl << "x = 5 mod 7";
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
                player->setMoney(player->getMoney() + 10);
                std::cout << "you earn 10 dollors from Sphinx" << std::endl;
                cout << "Correct!" << std::endl << "accept reward" << std::endl;
                //take the item
                for(int i = 0; i < 4; i++){
                    cout << this->getCommodity()[i]->getName() <<"from Sphinx";
                    //cannot take
                    if(player->getInventory().size() >= 12){
                        cout << "your bag is full";
                        player->getCurrentRoom()->ItemFall(this->getCommodity()[i]);
                    }
                    //take
                    else{
                        cout << "would you take the item Y/n" << std::endl;
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
farmer::farmer():NPC("Famer", FarmerScripts, 4, {&fromfarmer}){}

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
            player->getCurrentRoom()->ItemFall(&fromfarmer);
            for(int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++){
                if(player->getCurrentRoom()->getObjects()[i] == this){
                    player->getCurrentRoom()->getObjects().erase(player->getCurrentRoom()->getObjects().begin() + i);
                }
            }
        }
        else{
            cout << "would you take the sword Y/n";
            string ans;
            cin >> ans;
            while(cin >> ans){
                if(ans == "Y"){
                    player->pickupItem(&fromfarmer);
                    for(int i = 0; i < player->getCurrentRoom()->getObjects().size(); i++){
                        if(player->getCurrentRoom()->getObjects()[i] == this){
                         player->getCurrentRoom()->getObjects().erase(player->getCurrentRoom()->getObjects().begin() + i);
                        }
                    }
                    break;
                }
                else if(ans == "n"){
                    player->getCurrentRoom()->ItemFall(&fromfarmer);
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

chef::chef(): NPC("Chef", ChefScripst, 8, {&MilkfromChef, &SwordfromChef}){}
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
        for(int i = 0; i < 2; i++){
            cout << this->getCommodity()[i]->getName() <<"from chef";
            //cannot take
            if(player->getInventory().size() >= 12){
                cout << "your bag is full";
                Object* ptr = dynamic_cast<Item*>(this->getCommodity()[i]);
                player->getCurrentRoom()->getObjects().push_back(ptr);
            }
            //take
            else{
                cout << "would you take the item Y/n" << std::endl;
                std::string takeornot;
                while(cin >> takeornot){
                    if(takeornot == "Y"){
                        player->getInventory().push_back(this->getCommodity()[i]);
                        break;
                    }
                    else if(takeornot == "n"){
                        Object* ptr = dynamic_cast<Item*>(this->getCommodity()[i]);
                        player->getCurrentRoom()->getObjects().push_back(ptr);
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