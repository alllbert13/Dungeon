#include "Dungeon.h"
#include "Item.h"
#include "NPC.h"
#include "Monster.h"
#include "Player.h"

Dungeon::Dungeon() = default;
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
    Meet Meet1inRoom1(2);
    Meet Meet2inRoom1(2);
    WaterBolt W(2);
    WaterBolt W2(2);
    animalMeat frompig;
    animalMeat frombird;
    Milk MilkfromPig;
    Armor armorin1;
    Monster pig("wild boar", 10, 2, 1, 20, {&frompig, &MilkfromPig});
    Monster bird("cow", 5, 1, 1, 10, {&frombird});
    LifePotion LifeinRoom1(3);
    LifePotion LifeinRoom12(4);
    Room room1("forest", 1, {});
    room1.getObjects().push_back(&pig);
    room1.getObjects().push_back(&bird);
    room1.getObjects().push_back(&Meet1inRoom1);
    room1.getObjects().push_back(&Meet2inRoom1);
    room1.getObjects().push_back(&W);
    room1.getObjects().push_back(&W2);
    room1.getObjects().push_back(&LifeinRoom1);
    room1.getObjects().push_back(&LifeinRoom12);
    room1.getObjects().push_back(&armorin1);

    Room room2("nomal", 2, {});
    Guide guide;
    Meet mroom21(2);
    Meet mroom22(2);
    WaterBolt Wr2(2);
    LifePotion lr21(4);
    room2.getObjects().push_back(&guide);
    room2.getObjects().push_back(&mroom21);
    room2.getObjects().push_back(&mroom22);
    room2.getObjects().push_back(&Wr2);
    room2.getObjects().push_back(&lr21);

    Room room3("nomal", 3, {});
    clerk albert;
    LifePotion lshop(6);
    Milk Mshop1;
    Milk Mshop2;
    Milk Mshop3;
    HeartContainer hshop;
    albert.getCommodity().push_back(&lshop);
    albert.getCommodity().push_back(&Mshop1);
    albert.getCommodity().push_back(&Mshop2);
    albert.getCommodity().push_back(&Mshop3);
    albert.getCommodity().push_back(&hshop);
    room3.getObjects().push_back(&albert);


    Room room4("desert", 4, {});
    farmer Farmer;
    Sword sword(2);
    HeartContainer hfromroomfarmer;
    Farmer.setCommodity({&sword, &hfromroomfarmer});
    Milk mfromrrom4;
    room4.getObjects().push_back(&Farmer);
    room4.getObjects().push_back(&mfromrrom4);

    Room room5("desert", 5, {});
    LifePotion lfCh(5);
    Milk mfromChi;
    Monster Chimera("Chimera", 8, 1, 2, 30, {&lfCh, &mfromChi});
    Meet meinrom5(3);
    WaterBolt winro5(4);
    WaterBolt winro52(6);
    room5.setObjects({&Chimera, &meinrom5, &winro5, &winro52});

    Room room6("desert", 6, {});
    WaterBolt warromrr5(2);
    WaterBolt warrom52(2);
    LifePotion liro5(5);
    Meet meromro5(2);
    Milk miinr5;
    Sphinx sphinx;
    HeartContainer frsphinx;
    sphinx.setCommodity({&frsphinx});
    room6.getObjects().push_back(&sphinx);
    room6.getObjects().push_back(&warromrr5);
    room6.getObjects().push_back(&warrom52);
    room6.getObjects().push_back(&liro5);
    room6.getObjects().push_back(&meromro5);
    room6.getObjects().push_back(&miinr5);
    
    

    Room room7("swamp", 7, {});
    Monster Cerberus("Cerberus", 10, 4, 2, 80, {});
    HeartContainer hfroCer;
    WaterBolt wrgcer(2);
    Milk mikdfromcer;
    Cerberus.setCommodity({&hfroCer, &wrgcer, &mikdfromcer});
    Meet inrom7(5);
    room7.setObjects({&inrom7, &Cerberus});


    Room room8("forest", 8, {});
    Boss boss;
    boss.setAttack(6);
    boss.setMaxHealth(20);
    boss.setDefense(4);
    room8.setObjects({&boss});

    Room room9("swamp", 9, {});
    chef Chef;
    LifePotion inroom9(5);
    Chef.setCommodity({&inroom9});
    room9.setObjects({&Chef});

    room1.setRightRoom(&room2);
    room1.setUpRoom(&room4);
    room2.setLeftRoom(&room1);
    room2.setRightRoom(&room3);
    room2.setUpRoom(&room5);
    room3.setLeftRoom(&room2);
    room3.setUpRoom(&room6);
    room4.setDownRoom(&room1);
    room4.setRightRoom(&room5);
    room4.setUpRoom(&room7);
    room5.setDownRoom(&room2);
    room5.setLeftRoom(&room4);
    room5.setUpRoom(&room8);
    room5.setRightRoom(&room6);
    room6.setDownRoom(&room3);
    room6.setLeftRoom(&room5);
    room6.setUpRoom(&room9);
    room7.setDownRoom(&room4);
    room7.setRightRoom(&room8);
    room8.setLeftRoom(&room7);
    room8.setDownRoom(&room5);
    room8.setRightRoom(&room9);
    room9.setLeftRoom(&room8);
    room9.setDownRoom(&room6);



    createPlayer();
    player.setCurrentRoom(&room2);
    int command;
    while(checkGameLogic()){
        cout << endl << endl;
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
                afterWork();
            }
            else if(command == length + 4){
                player.back();
                afterWork();
            }
            else if(command == length + 5){
                player.left();
                afterWork();
            }
            else{
                player.right();
                afterWork();
            }
            
        }
        else if(command <= player.getCurrentRoom()->getObjects().size() && command >= 1){
            player.getCurrentRoom()->getObjects()[command - 1]->takeItem(&player);
            //double free or corruption
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
    if(length == 0){
        cout << "this room is empty" << endl; 
    }
    for(int i = 0; i < length; i++){
        player.getCurrentRoom()->getObjects()[i]->presentItem();
        std::cout << " " << i + 1 << std::endl;
    }
    cout << endl;
    cout << "show states " << length + 1 << std::endl;
    cout << "check bag " << length + 2 << std::endl << endl;
    cout << "forward " << length + 3 << std::endl;
    cout << "backward " << length + 4 << std::endl;
    cout << "go left " << length + 5 << std::endl;
    cout << "go right " << length + 6 << std::endl;
}

bool Dungeon::checkGameLogic(){
    if(player.getCurrentHealth() <= 0){
        return 0;
    }
    if(player.gethead() == 7){
        return 0;
    }
    return 1;
}

void Dungeon::afterWork(){
    if(player.getThirsty() <= 0 || player.getHungry() <= 0){
        player.takeDamage(1);
        if(player.getThirsty() <= 0 && player.getHungry() <= 0){
            cout << "you got 1 damage because you're thirsty and hungry" << endl;
        }
        else if(player.getThirsty() <= 0 && player.getHungry() > 0){
            player.setHungry(player.getHungry() - 1);
            cout << "you got 1 damage because you're thirsty" << endl;
            if(player.getHunger() && player.getHungry() > 0){
                player.setHungry(player.getHungry() - 1);
            }
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
        if(player.getThirst() && player.getThirsty() > 0){
            player.setThirsty(player.getThirsty() - 1);
        }
        if(player.getPoison()){
            player.takeDamage(1);
            cout << "you get 1 damage because you are poinsoned" << endl;
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