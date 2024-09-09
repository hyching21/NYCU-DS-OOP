#include "Item.h"

Item::Item(){}

Item::Item(string name, int health, int attack, int defense,int price):Object(name,"Item"){
    this->health=health;
    this->attack=attack;
    this->defense=defense;
    this->price=price;
}

int Item::getHealth(){return this->health;}
int Item::getAttack(){return this->attack;}
int Item::getDefense(){return this->defense;}
int Item::getPrice(){return this->price;}
void Item::setHealth(int health){this->health=health;}
void Item::setAttack(int attack){this->attack=attack;}
void Item::setDefense(int defense){this->defense=defense;}
void Item::setPrice(int price){this->price=price;}


/*Pickup & Get coin & Buy*/
bool Item::triggerEvent(Object* thething){
    if (thething->getTag()=="Player"){
        //TODO
        //thething=new Player;
        Player*update_player=dynamic_cast<Player*> (thething);
        update_player->addItem(*this);
        update_player->changeMoney(-this->getPrice()); //buy
        /*update_player->increaseStates(this->health,this->attack,this->defense);
        if(update_player->getOccupation()=="Magician"&&this->getName()=="Potions"){update_player->increaseStates(5,5,5);}
        else if(update_player->getOccupation()=="Warrior"&&this->getName()=="Shield"){update_player->increaseStates(5,5,5);}
        else if(update_player->getOccupation()=="Knight"&&this->getName()=="Holy sword"){update_player->increaseStates(5,5,5);}*/
        return true;

    }
    else{return false;}

 }
