#include "Dungeon.h"
#include <vector>
Dungeon::Dungeon(){

}
/* Create a new player, and give him/her basic status */
void Dungeon::createPlayer(){
    string user_name;
    cout<<"Please name your character: ";
    cin>>user_name;
    cout<<"\nPlease choose which occupation do you want to be:\nA.Magician\nB.Warrior\nC.Knight\n";

    while(1){
        char occupation;
        cin>>occupation;
        if(occupation=='A'){this->player=Player(user_name,100,20,15,15,"Magician");break;}
        else if(occupation=='B'){this->player=Player(user_name,100,30,5,10,"Warrior");break;}
        else if(occupation=='C'){this->player=Player(user_name,100,25,10,20,"Knight");break;}
        else{cout<<"wrong input, enter again>>"<<endl;}

    }


}

/* Create a map, which include several different rooms */
void Dungeon::createMap(){
    //set object
    vector<Object*> obj1,obj2,obj3,obj4,obj5,obj6,obj7,obj8,obj9,obj10,obj11,obj12,obj13,obj14,obj15;
    //item
    Item the_item("Medicine",30, 0, 0,25);Item the_item2("Coins",0, 0, 0,20);Item the_item3("Coins",0, 0, 0,30);Item the_item4("Coins",0, 0, 0,50);
    Item the_item5("Firecracker",0, 20,0,10);Item the_item6("Shield",5, 10, 10,10);Item the_item7("Holy sword",0, 15, 5,20);Item the_item8("Potions",10,5,10,15);
    Item the_item9("Magic book",0, 0,10,10);Item the_item10("Bomb",0, 25, 0,15);Item the_item11("Laser gun",0, 10,2,10);Item the_item12("Poison gas",0, 15,5,15);
    //npc
    vector<Item>granny_bag,merchant_bag,colonel_bag;
    granny_bag.push_back(the_item);granny_bag.push_back(the_item8);granny_bag.push_back(the_item9);
    merchant_bag.push_back(the_item7);merchant_bag.push_back(the_item12);
    colonel_bag.push_back(the_item10); colonel_bag.push_back(the_item11);colonel_bag.push_back(the_item5);
    NPC* granny = new NPC("Granny Susan","Magic is everything hahaha!", granny_bag);
    NPC* merchant = new NPC("Merchant","Money is the power!", merchant_bag);
    NPC* colonel = new NPC("Colonel James","Let failure be your energy!", colonel_bag);
    //chest
    vector<Item>thechest2,thechest3,thechest9,thechest12,thechest14;
    thechest2.push_back(the_item3);//thechest2.push_back(the_item10);
    thechest3.push_back(the_item6);thechest3.push_back(the_item4);
    thechest9.push_back(the_item8);thechest9.push_back(the_item2);
    thechest12.push_back(the_item7);thechest12.push_back(the_item);
    thechest14.push_back(the_item2);thechest14.push_back(the_item11);
    Chest* chest2 = new Chest(thechest2);
    Chest* chest3 = new Chest(thechest3);
    Chest* chest9 = new Chest(thechest9);
    Chest* chest12 = new Chest(thechest12);
    Chest* chest14 = new Chest(thechest14);
    //monster
    Monster* devil = new Monster("Little devil", 20, 18, 10);
    Monster* boss = new Monster("BOSSYBOSS", 160, 60, 40);
    Monster* zombie = new Monster("Zombie", 50, 35, 25);
    Monster* Ogres = new Monster("Ogres", 60, 45, 30);


    obj1.push_back(merchant);obj2.push_back( chest2);obj3.push_back( chest3);obj4.push_back(merchant);
    obj5.push_back(devil);obj6.push_back(granny);obj7.push_back(zombie);obj8.push_back(zombie);
    obj9.push_back(chest9);obj10.push_back(Ogres);obj12.push_back(chest12);
    obj13.push_back(colonel);obj14.push_back(chest14);obj15.push_back(boss);

     //create room
    Room *room0 = new Room(false,false, 0, vector<Object*>());
    Room *room1 = new Room(false,false, 1, obj1);
    Room *room2 = new Room(false,false, 2, obj2);
    Room *room3 = new Room(true,false, 3, obj3);
    Room *room4 = new Room(false,false, 4, obj4);
    Room *room5 = new Room(false,false, 5, obj5);
    Room *room6 = new Room(true,false, 6, obj6);
    Room *room7 = new Room(false,false, 7, obj7);
    Room *room8 = new Room(false,false, 8, obj8);
    Room *room9 = new Room(false,false, 9, obj9);
    Room *room10 = new Room(false,false, 10, obj10);
    Room *room11 = new Room(false,false, 11, obj11);
    Room *room12 = new Room(true,false, 12, obj12);
    Room *room13 = new Room(false,false, 13, obj13);
    Room *room14 = new Room(false,false, 14, obj14);
    Room *room15 = new Room(false,true, 15, obj15);

    room0->setUpRoom(NULL);room0->setDownRoom(room4);room0->setLeftRoom(NULL);room0->setRightRoom(room1);
    room1->setUpRoom(NULL);room1->setDownRoom(room5);room1->setLeftRoom(room0);room1->setRightRoom(room2);
    room2->setUpRoom(NULL);room2->setDownRoom(room6);room2->setLeftRoom(room1);room2->setRightRoom(room3);
    room3->setUpRoom(NULL);room3->setDownRoom(room7);room3->setLeftRoom(room2);room3->setRightRoom(NULL);
    room4->setUpRoom(room0);room4->setDownRoom(room8);room4->setLeftRoom(NULL);room4->setRightRoom(room5);
    room5->setUpRoom(room1);room5->setDownRoom(room9);room5->setLeftRoom(room4);room5->setRightRoom(room6);
    room6->setUpRoom(room2);room6->setDownRoom(room10);room6->setLeftRoom(room5);room6->setRightRoom(room7);
    room7->setUpRoom(room3);room7->setDownRoom(room11);room7->setLeftRoom(room6);room7->setRightRoom(NULL);
    room8->setUpRoom(room5);room8->setDownRoom(room12);room8->setLeftRoom(NULL);room8->setRightRoom(room9);

    room9->setUpRoom(room5);room9->setDownRoom(room13);room9->setLeftRoom(room8);room9->setRightRoom(room10);
    room10->setUpRoom(room6);room10->setDownRoom(room14);room10->setLeftRoom(room9);room10->setRightRoom(room11);
    room11->setUpRoom(room7);room11->setDownRoom(room15);room11->setLeftRoom(room10);room11->setRightRoom(NULL);
    room12->setUpRoom(room8);room12->setDownRoom(NULL);room12->setLeftRoom(NULL);room12->setRightRoom(room13);
    room13->setUpRoom(room9);room13->setDownRoom(NULL);room13->setLeftRoom(room12);room13->setRightRoom(room14);
    room14->setUpRoom(room10);room14->setDownRoom(NULL);room14->setLeftRoom(room13);room14->setRightRoom(room15);
    room15->setUpRoom(room11);room15->setDownRoom(NULL);room15->setLeftRoom(room14);room15->setRightRoom(NULL);



    //fill in
    this->rooms.push_back(*room0);this->rooms.push_back(*room1);this->rooms.push_back(*room2);this->rooms.push_back(*room3);
    this->rooms.push_back(*room4);this->rooms.push_back(*room5);this->rooms.push_back(*room6);this->rooms.push_back(*room7);
    this->rooms.push_back(*room8);this->rooms.push_back(*room9);this->rooms.push_back(*room10);this->rooms.push_back(*room11);
    this->rooms.push_back(*room12);this->rooms.push_back(*room13);this->rooms.push_back(*room14);this->rooms.push_back(*room15);
}

/* Deal with player's moveing action */
void Dungeon::handleMovement(){
    int r=this->player.getCurrentRoom()->getIndex();
    cout<<"You are now in room#"<<r<<". You can move:\n";
    //examine which direction can go

    string direction[4]={"up","down","left","right"};
    vector<int> num;
    if(this->rooms[r].getUpRoom()!=NULL){num.push_back(0);}
    if(this->rooms[r].getDownRoom()!=NULL){num.push_back(1);}
    if(this->rooms[r].getLeftRoom()!=NULL){num.push_back(2);}
    if(this->rooms[r].getRightRoom()!=NULL){num.push_back(3);}
    for(int i=0;i<num.size();i++){
        cout<<"("<<i+1<<")"<<"go "<<direction[num[i]]<<endl;
    }
    int choose;
    cin>>choose;
    choose=choose-1;
    int nr=num[choose];
    int indexofnext;
    if(nr==0){
        indexofnext = this->rooms[r].getUpRoom()->getIndex();
        this->player.changeRoom(&(this->rooms[indexofnext]));
    }
    else if(nr==1){
        indexofnext = this->rooms[r].getDownRoom()->getIndex();
        this->player.changeRoom(&(this->rooms[indexofnext]));
    }
    else if(nr==2){
        indexofnext = this->rooms[r].getLeftRoom()->getIndex();
        this->player.changeRoom(&(this->rooms[indexofnext]));
    }
    else if(nr==3){
        indexofnext = this->rooms[r].getRightRoom()->getIndex();
        this->player.changeRoom(&(this->rooms[indexofnext]));
    }

    cout<<"YA! You now move to room#"<<this->player.getCurrentRoom()->getIndex()<<"."<<endl;


}

/* Deal with player's iteraction with objects in that room */
void Dungeon::handleEvent(Object*obj){
    if(obj->getTag()=="Monster"){
        obj=new Monster;
        Monster *monster = dynamic_cast<Monster*> (obj);
        monster->triggerEvent(&(this->player));
    }
    else if(obj->getTag()=="NPC"){
        obj=new NPC;
        NPC *npc= dynamic_cast<NPC*> (obj);
        npc->triggerEvent(&(this->player));
    }
    else if(obj->getTag()=="Chest"){
        obj=new Chest;
        Chest *chest= dynamic_cast<Chest*> (obj);
        chest->triggerEvent(&(this->player));
    }
    else {cout<<"error"<<endl;}

}

/* Deal with all game initial setting       */
/* Including create player, create map etc  */
void Dungeon::startGame(){
     cout<<"\nWelcome to the Dungeon!...........................\n";
     this->createPlayer();
     this->createMap();
     this->player.setCurrentRoom(&(this->rooms[0]));
     this->player.setPreviousRoom(&(this->rooms[0]));
}

/* Deal with the player's action     */
/* including showing the action list */
/* that player can do at that room   */
/* and dealing with player's input   */
void Dungeon::chooseAction(vector<Object*>room_obj){

    cout<<"\n.......................................\n";
    cout<<"What do you want to do? ";
    cout<<"(You are in the Room " << this->player.getCurrentRoom()->getIndex() << ") "<< endl;
    if(this->player.getCurrentRoom()->getIsLocked()==true){
        cout<<"This room is locked. You have to pay $20 to unlock it.\n";
        cout<<"Do you want to pay to unlocked it? (Y/N)\n";
        char pay;
        cin>>pay;
        if(pay=='Y'){
            if(player.getMoney()<20){cout<<"Sorry, you don't have enough money.\n";}
            else{
                player.changeMoney(-20);
                cout<<"You now unlocked the room.\n";
                this->player.getCurrentRoom()->setIsLocked(false);
            }

        }
        else if(pay='N'){}
    }
    //cout<<room_obj.size();
    bool ismonster=false,isnpc=false,ischest=false;
    if(this->player.getCurrentRoom()->getIsLocked()==false){
        for(int i=0;i<room_obj.size();i++){
        cout<<'A'<<".";
        if (room_obj[i]->getTag() == "Monster"){
            cout<<"Combat with "<<room_obj[i]->getName()<<"\n";
            ismonster=true;
        }
        else if(room_obj[i]->getTag() == "NPC"){
            cout<<"Talk to "<<room_obj[i]->getName()<<"\n";
            isnpc=true;
        }
        else if(room_obj[i]->getTag() == "Chest"){
            Chest* chest = dynamic_cast<Chest*> (room_obj[i]);
            cout<<"Open the chest"<<endl;
            if (chest->getIsOpen() == true){
                cout << "(It has already been opened.)\n";
            }
            ischest=true;
        }
    }
    }


    if(ismonster==false&&isnpc==false&&ischest==false){cout<<"A.Move\nB.Show your status\nC.Open bag/Equip\n";}
    else if(ismonster==false){
        cout<<"B.Move\nC.Show your status\nD.Open bag/Equip\n";
    }
    else{
        cout<<"B.Show your status\nC.Open bag/Equip\n";
    }
    char choice;
    cin>>choice;



    //different circumstances
    if(ismonster==true){
        if(choice=='B'){this->player.triggerEvent(&(this->player));}
        else if(choice=='C'){this->player.equipthe(&(this->player));}
        else if(choice=='A'){
            //room_obj[0]=new Monster;
            Monster*monster = dynamic_cast<Monster*> (room_obj[0]);
            monster->triggerEvent(&(this->player));
            if (monster->checkIsDead() == true){
                this->rooms[this->player.getCurrentRoom()->getIndex()].popObject(room_obj[0]);
        }
        }
    }
    else if(ismonster==false&&isnpc==false&&ischest==false){
        if(choice=='A'){this->handleMovement();}
        else if(choice=='B'){this->player.triggerEvent(&(this->player));}
        else if(choice=='C'){this->player.equipthe(&(this->player));}
    }
    else if(ismonster==false){
        if(choice=='A'){

            if(room_obj[0]->getTag() == "NPC"){
                //room_obj[0]=new NPC;
                NPC*npc = dynamic_cast<NPC*> (room_obj[0]);
                npc->triggerEvent(&(this->player));
            }
            else if(room_obj[0]->getTag() == "Chest"){
                //room_obj[0]=new Chest;
                Chest*chest = dynamic_cast<Chest*> (room_obj[0]);
                if(chest->getIsOpen()==false){
                    chest->triggerEvent(&(this->player));
                    chest->setIsOpen(true);
                }

            }
        }
        else if(choice=='B'){this->handleMovement();}
        else if(choice=='C'){this->player.triggerEvent(&(this->player));}
        else if(choice=='D'){this->player.equipthe(&(this->player));}
    }

}

/* Check whether the game should end or not */
/* Including player victory, or he/she dead */
/*bool Dungeon::checkGameLogic(){

    if(this->player.checkIsDead() == true){return false;}
    //the final room
    else if(this->player.getCurrentRoom() == &this->rooms.back()){
        vector<Object*> check = this->player.getCurrentRoom()->getObjects();
        int boss=0;
        if(check[0]->getName() == "BOSS"){
            boss=1; return true;
        }
        if(boss==0){;return false;}
    }

    else{return true;}
}*/
bool Dungeon::checkGameLogic(){

    if(this->player.checkIsDead() == true){
        cout<<"GAME OVER.................................\n";
        return false;
    }
    //the final room
    else if(this->player.getCurrentRoom() == &this->rooms.back()){
        vector<Object*> objects = this->player.getCurrentRoom()->getObjects();
        bool hasBoss = false;
        for(int i=0; i<objects.size(); i++){
            if(objects[i]->getName() == "BOSSYBOSS"){
                hasBoss = true;
                break;
            }
        }
        if(hasBoss){
            return true;
        } else {
            cout<<"CONGRATS~YOU WIN! THE GAME IS OVER....................\n";
            return false;
        }
    }
    else{
        return true;
    }
}

/* Deal with the whole game process */
void Dungeon::runDungeon(){
     this->startGame();
     while(this->checkGameLogic() == true){
        this->chooseAction(this->player.getCurrentRoom()->getObjects());
     }
     if (this->player.checkIsDead() == false){

        exit(222);
     }
     else{exit(1);}
}
