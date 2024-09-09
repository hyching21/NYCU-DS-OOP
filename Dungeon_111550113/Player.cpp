#include "Player.h"

Player::Player(){}
Player::Player(string name,int health,int attack,int defense,int money,string occupation):GameCharacter(name,"Player",health,attack,defense){
    this->money=money;
    this->occupation=occupation;
}

bool Player::popbag(Item* takeoff){
    if(takeoff!=NULL){
        for(int i=0;i<this->inventory.size(); i++){
            if(this->inventory[i].getName()==takeoff->getName()){
                this->inventory.erase(inventory.begin() + i);
                return true;
            }
        }
        return false;
    }
    else{return false;}

}
bool Player::popequip(Item* takeoff){
    if(takeoff!=NULL){
        for(int i=0;i<this->equip.size(); i++){
            if(this->equip[i].getName()==takeoff->getName()){
                this->equip.erase(equip.begin() + i);
                return true;
            }
        }
        return false;
    }
    else{return false;}

}

bool Player::equipthe(Object*thething){
    if(thething->getTag()=="Player"){
        Player* player= dynamic_cast<Player*> (thething);
        cout<<"\n.......................................\n";
        if(this->inventory.size()>0){
            cout<<"Your bag has:\n";
            for(int i=0;i<this->inventory.size();i++){
                 cout << "(" << i+1 << ") " << this->inventory[i].getName()<<" ";
            }
            cout<<"\nWhich one to equip?(enter number only/0 to exit)\n";
            int ans;cin>>ans;
            if(ans==0){return true;}
            else if(ans>this->inventory.size()){cout<<"wrong input\n";return true;}
            equip.push_back(this->inventory[ans-1]);
            player->popbag(&this->inventory[ans-1]);
            player->increaseStates(this->inventory[ans-1].getHealth(),this->inventory[ans-1].getAttack(),this->inventory[ans-1].getDefense());
            if(player->getOccupation()=="Magician"&&this->inventory[ans-1].getName()=="Potions"){player->increaseStates(5,5,5);}
            else if(player->getOccupation()=="Warrior"&&this->inventory[ans-1].getName()=="Shield"){player->increaseStates(5,5,5);}
            else if(player->getOccupation()=="Knight"&&this->inventory[ans-1].getName()=="Holy sword"){player->increaseStates(5,5,5);}

        }

        else{cout<<"Your bag has: nothing:)"<<endl;}
        return true;
    }
    else{return false;}

}

void Player::addItem(Item theitem){
     this->inventory.push_back(theitem);
} //get some item

void Player::increaseStates(int health,int attack,int defense){

    this->setCurrentHealth(this->getCurrentHealth() + health);
    this->setMaxHealth(this->getMaxHealth() + health);
    this->setAttack(this->getAttack() + attack);
    this->setDefense(this->getDefense() + defense);
    //if(this->getCurrentHealth()>=100){this->setMaxHealth(this->getCurrentHealth());}


}
void Player::useskill(Player* user){
     string skill;
     if(user->getOccupation()=="Magician"){
        skill="Freeze Spell";
        user->increaseStates(0,10,5);
        user->takeDamage(5);
     }
     else if(user->getOccupation()=="Warrior"){
        skill="Roar";
        user->increaseStates(0,15,3);
        user->takeDamage(5);
     }
     else if(user->getOccupation()=="Knight"){
        skill="Lightning";
        user->increaseStates(0,15,5);
        user->takeDamage(5);
     }
    cout<<"Your skill is "<<skill<<endl;

}
void Player::unuseskill(Player* user){
    if(user->getOccupation()=="Magician"){
        user->increaseStates(0,-10,-5);
     }
     else if(user->getOccupation()=="Warrior"){
        user->increaseStates(0,-15,-3);
     }
     else if(user->getOccupation()=="Knight"){
        user->increaseStates(0,-15,-5);
     }
}

void Player::changeMoney(int money){
    this->setMoney(this->getMoney()+money);
}

void Player::changeRoom(Room* cur_room){
    Room* temp_room = this->currentRoom;
    this->currentRoom = cur_room;
    this->previousRoom = temp_room;
}

/*show status*/
bool Player::triggerEvent(Object*thething){
    if(thething->getTag()=="Player"){
        //thething=new Player;
        Player* player= dynamic_cast<Player*> (thething);
        cout<<"\n.......................................\n";
        cout<<"["<<player->getName()<<"]\nOccupation: "<<player->getOccupation()<<
        "\nHealth: "<<player->getCurrentHealth()<<"/"<<player->getMaxHealth()<<"\nAttack: "<<player->getAttack()<<"\nDefense: "<<player->getDefense()<<endl;
        cout<<"Money: $"<<player->getMoney()<<endl;
        /*cout<<"Your bag has:\n";
        if(this->inventory.size()>0){
            for(int i=0;i<this->inventory.size();i++){
                 cout << "(" << i+1 << ") " << this->inventory[i].getName()<<" ";
            }
        }
        else{cout<<"nothing:)"<<endl;}*/
        return true;
    }
    else{return false;}


}
/*
bool Player::openbag(Object*thething){
    if(thething->getTag()=="Player"){
        Player* player= dynamic_cast<Player*> (thething);
        cout<<"\n.......................................\n";
        cout<<"Your bag has:\n";
        if(this->inventory.size()>0){
            for(int i=0;i<this->inventory.size();i++){
                 cout << "(" << i+1 << ") " << this->inventory[i].getName()<<" ";
            }
        }
        else{cout<<"nothing:)"<<endl;}
        return true;
    }
    else{return false;}

}*/


void Player::setCurrentRoom(Room*cur_room){this->currentRoom=cur_room;}
void Player::setPreviousRoom(Room*pre_room){this->previousRoom=pre_room;}
void Player::setInventory(vector<Item> inventory_list){this->inventory=inventory_list;}
void Player::setEquip(vector<Item> equip_list){this->equip=equip_list;}
void Player::setOccupation(string occupation){this->occupation=occupation;}
void Player::setMoney(int money){this->money=money;}

Room* Player::getCurrentRoom(){return this->currentRoom;}
Room* Player::getPreviousRoom(){return this->previousRoom;}
vector<Item> Player::getInventory(){return this->inventory;}
vector<Item> Player::getEquip(){return this->equip;}
int Player::getMoney(){return this->money;}
string Player::getOccupation(){return this->occupation;}
