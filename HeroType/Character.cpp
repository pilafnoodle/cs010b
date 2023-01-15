#include "Character.h"
using namespace std;


Character::Character(HeroType type, const string &name, double health, double attackStrength){
    this->type=type;
    this->name=name;
    this->health=health;
    this->attackStrength=attackStrength;
}

HeroType Character::getType() const{
    return type;
}
const string & Character::getName() const{
    return name;
}
int Character::getHealth() const{
    return health/1;
}
void Character::damage(double d){
    health-=d;
}
bool Character::isAlive() const{
    if(health>0){
        return true;
    }
    return false;
}
void Character::attack(Character &){

}

