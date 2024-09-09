#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"
using namespace std;

class Player;

class Item: public Object
{
private:
    int health,attack,defense;
    int price;
public:
    Item();
    Item(string, int, int, int,int);

    /*occupation, price, change player value, intro*/

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object* thething); //pickup, triggered by player

    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    int getPrice();
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setPrice(int);
};

#endif // ITEM_H_INCLUDED
