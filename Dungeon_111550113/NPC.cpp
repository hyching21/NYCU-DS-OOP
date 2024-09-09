#include "NPC.h"

NPC::NPC(){}
NPC::NPC(string name, string script, vector<Item> commodity):GameCharacter(name,"NPC",100,100,100){
 this->script=script;
 this->commodity=commodity;
}
void NPC::listCommodity(){
    for(int i=0;i<this->commodity.size();i++){
        cout<<(i+1)<<". "<<this->commodity[i].getName()<<" cost$"<<this->commodity[i].getPrice()<<"."<<endl;
    }

}
bool NPC::triggerEvent(Object* thething){
    if(thething->getTag()=="Player"){
        //thething=new Player;
        Player*trade_player=dynamic_cast<Player*> (thething);
        char reply;
        cout<<"\n.......................................\n"<<this->getScript()<<endl;
        cout<<this->getName()<<": Hi! I am "<<this->getName()<<". I have something for you to choose:\n";
        listCommodity();
        cout<<this->getName()<<": Do you want to buy something? (Y/N)\n";
        cin>>reply;
        if(reply!='Y'){
            cout<<"byebye"<<endl;
            return true;
        }
        else{
            cout<<this->getName()<<": Which one do you want?(please enter number only)\n";
            int choice;
            cin>>choice;
            if(this->commodity[choice-1].getPrice()>trade_player->getMoney()){cout<<"Sorry, you don't have enough money."<<endl;}
            else{
                this->commodity[choice-1].triggerEvent(trade_player);
            }
            return true;
        }
    }
    else {return false;}


}
void NPC::setScript(string script){this->script = script;}
void NPC::setCommodity(vector<Item> commodity){this->commodity=commodity;}
string NPC::getScript(){return this->script;}
vector<Item> NPC::getCommodity(){return this->commodity;}
