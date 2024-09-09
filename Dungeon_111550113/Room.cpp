#include "Room.h"

Room::Room(){}
Room::Room(bool islocked,bool isExit, int index,vector<Object*>objects){
    this->islocked=islocked;
    this->isExit = isExit;
    this->index = index;
    this->objects = objects;
}


bool Room::popObject(Object* takeoff){
    if(takeoff!=NULL){
        for(int i=0;i<this->objects.size(); i++){
            if(this->objects[i]==takeoff){
                this->objects.erase(objects.begin() + i);
                return true;
            }
        }
        return false;
    }
    else{return false;}

}

/* Set & Get function*/
void Room::setUpRoom(Room*r){this->upRoom = r;}
void Room::setDownRoom(Room*r){this->downRoom = r;}
void Room::setLeftRoom(Room*r){this->leftRoom = r;}
void Room::setRightRoom(Room*r){this->rightRoom = r;}
void Room::setIsExit(bool isExit){this->isExit = isExit;}
void Room::setIsLocked(bool islocked){this->islocked = islocked;}
void Room::setIndex(int index){this->index=index;}
void Room::setObjects(vector<Object*> objects){ this->objects = objects;}
bool Room::getIsExit(){return this->isExit;}
bool Room::getIsLocked(){return this->islocked;}
int Room::getIndex(){return this->index;}
vector<Object*> Room::getObjects(){return this->objects;}
Room* Room::getUpRoom(){return this->upRoom;}
Room* Room::getDownRoom(){return this->downRoom;}
Room* Room::getLeftRoom(){return this->leftRoom;}
Room* Room::getRightRoom(){return this->rightRoom;}
