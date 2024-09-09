#include "GameCharacter.h"

GameCharacter::GameCharacter(){}
GameCharacter::GameCharacter(string name,string tag,int health,int attack,int defense):Object(name,tag){
    this->currentHealth=health;
    this->maxHealth=health;
    this->attack=attack;
    this->defense=defense;
}

bool GameCharacter::checkIsDead(){
    if(currentHealth<=0){return true;}
    else {return false;}
}
int GameCharacter::takeDamage(int damage){
    currentHealth=currentHealth-damage;
    return currentHealth;
}




void GameCharacter::setMaxHealth(int maxHealth){this->maxHealth=maxHealth;}
void GameCharacter::setCurrentHealth(int currentHealth){this->currentHealth=currentHealth;}
void GameCharacter::setAttack(int attack){this->attack=attack;}
void GameCharacter::setDefense(int defense){ this->defense=defense;}
int GameCharacter::getMaxHealth(){return this->maxHealth;}
int GameCharacter::getCurrentHealth(){return this->currentHealth;}
int GameCharacter::getAttack(){return this->attack;}
int GameCharacter::getDefense(){return this->defense;}
