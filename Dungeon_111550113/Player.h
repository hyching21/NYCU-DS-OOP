#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
    vector<Item> equip;
    int money;
    string occupation;
public:
    Player();
    Player(string,int,int,int,int,string);
    void addItem(Item); //pickup something
    void increaseStates(int,int,int);
    void changeMoney(int);
    void changeRoom(Room*);
    void useskill(Player*);
    void unuseskill(Player*);
    bool popbag(Item*);
    bool popequip(Item*);
    bool equipthe(Object*);
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*); //showstatus triggered by player
    bool openbag(Object*);
    //bool useskill(object*);//triggered by monster
    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    void setEquip(vector<Item>);
    void setMoney(int);
    void setOccupation(string);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item> getInventory();
    vector<Item> getEquip();
    int getMoney();
    string getOccupation();
};


#endif // PLAYER_H_INCLUDED
