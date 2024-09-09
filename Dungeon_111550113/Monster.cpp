#include "Monster.h"

Monster::Monster(){}
Monster::Monster(string name,int health,int attack,int defense):GameCharacter(name,"Monster",health,attack,defense){}

bool Monster::triggerEvent(Object* thething){

    if(thething->getTag()=="Player"){
        //thething=new Player;
        Player*combat=dynamic_cast<Player*> (thething);
        cout<<"\n.......................................\n";
        cout<<"Warning!!"<<this->getName()<<" is coming!"<<endl;
        cout<<"Which action do you want to choose?\n"<<"A. Attack\nB. Retreat\n";
        char reply;
        cin>>reply;
        //Combat system can change to every round re-choose
        if(reply=='A'){
            cout<<"Using skill? (Y/N)\n";
            cin>>reply;
            if(reply=='Y'){
                combat->useskill(combat);

            }
            cout<<"\nFighting start!.......................................\n";
            while(1){
                int player_value=this->getAttack()-combat->getDefense();
                int monster_value=combat->getAttack()-this->getDefense();
                if(monster_value<=0){cout<<"You miss!\n";}
                else{
                    cout<<this->getName()<<" is attacked "<<monster_value<<" points by you. ";
                    int a=this->takeDamage(monster_value);
                    if(a<=0){a=0;}
                    cout<<this->getName()<<" lefts "<<a<<" health.\n";
                }

                if(this->checkIsDead()==true){
                    cout<<"You beat "<<this->getName()<<".\n";
                    if(this->getName()=="Zombie"){cout<<"Here's some reward for you.($10)\n";combat->changeMoney(10);}
                    else if(this->getName()=="Ogres"){cout<<"Here's some reward for you.($20)\n";combat->changeMoney(20);}
                    break;
                }
                if(player_value<=0){cout<<this->getName()<<" miss!\n";}
                else{
                    cout<<"You are attacked "<<player_value<<" points by "<<this->getName()<<".\n";
                    int b=combat->takeDamage(player_value);
                    if(b<=0){b=0;}
                    cout<<"You left "<<b<<" health.\n";
                }
                if(combat->checkIsDead()==true){
                    cout<<"YOU ARE DEAD!\n";
                    break;
                }
                if(monster_value<0&&player_value<0){
                    cout<<"You two are tied. Retreat to gain more attack.\n";
                    combat->changeRoom(combat->getPreviousRoom());
                    break;
                }
            }
            if(reply=='Y'){combat->unuseskill(combat);}
            if(combat->getEquip().size()>0){
                for(int i=0;i<combat->getEquip().size();i++){
                    if((combat->getEquip()[i].getName()!="Potions")&&(combat->getEquip()[i].getName()!="Holy sword")&&(combat->getEquip()[i].getName()!="Shield")){
                        combat->popequip(&combat->getEquip()[i]);
                    }
                }
            }

        }

        else if(reply=='B'){
            combat->changeRoom(combat->getPreviousRoom());
            cout << "You retreat to the previous room." << endl;
            //cout << "You are now in Room " << combatr->getCurrentRoom()->getIndex() <<")" << endl;
        }

        return true;
    }

    else {return false;}

}

