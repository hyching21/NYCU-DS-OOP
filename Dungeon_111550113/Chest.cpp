#include "Chest.h"

Chest::Chest(){}
Chest::Chest(vector<Item>item){
    this->setTag("Chest");
    this->chest = item;
    for(int i=0; i<this->chest.size(); i++){
        if(this->chest[i].getPrice()!=0){this->setName("Coins");}
    }
    this->open = false;


}
//void Chest::showItem(int index_1);
bool Chest::triggerEvent(Object*thething){
    if(thething->getTag()=="Player"){
        //thething=new Player;
        Player*player=dynamic_cast<Player*> (thething);
        for(int i=0; i<this->chest.size(); i++){
            if(this->chest[i].getName()=="Coins"){
               player->changeMoney(this->chest[i].getPrice());
               cout<<"You've got $"<< this->chest[i].getPrice()<<" coins!\n";
            }
            else{
               player->addItem(this->chest[i]);
               /*player->increaseStates(this->chest[i].getHealth(),this->chest[i].getAttack(),this->chest[i].getDefense());
               if(player->getOccupation()=="Magician"&&this->chest[i].getName()=="Potions"){player->increaseStates(5,5,5);}
               else if(player->getOccupation()=="Warrior"&&this->chest[i].getName()=="Shield"){player->increaseStates(5,5,5);}
               else if(player->getOccupation()=="Knight"&&this->chest[i].getName()=="Holy sword"){player->increaseStates(5,5,5);}*/
               cout<<"You've got a "<< this->chest[i].getName()<<endl;
            }

        }
        this->open = true;
        return true;
    }
    else {return false;}

}

void Chest::setChest(vector<Item>item){this->chest = item;}
void Chest::setIsOpen(bool open){this->open=open;}
vector<Item> Chest::getChest(){ return this->chest;}
bool Chest::getIsOpen(){return this->open;}
