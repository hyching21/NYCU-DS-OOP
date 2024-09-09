#ifndef CHEST_H_INCLUDED
#define CHEST_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Room.h"
#include "Player.h"
#include "Item.h"
using namespace std;

class Chest: public Object{
private:
    vector<Item> chest;
    bool open;

public:
    Chest();
    Chest(vector<Item>);


    //void showItem(int index_1);
    bool triggerEvent(Object*);
    void setChest(vector<Item>);
    void setIsOpen(bool);
    vector<Item> getChest();
    bool getIsOpen();
};




#endif // CHEST_H_INCLUDED
