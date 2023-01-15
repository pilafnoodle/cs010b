#include "Character.h"
#include "Warrior.h"
#include <string>
#include <iostream>

Warrior::Warrior(string name, double health, double atk,string allegiance):Character(WARRIOR,name, health,atk),allegiance(allegiance){
}

void Warrior::attack(Character &opponent){
    

    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(allegiance == opp.getAllegiance()){
            cout<<"Warrior "<<name<<" does not attack Warrior "<<opp.getName()<<"."<<endl;
            cout<<"They share an allegiance with "<<allegiance<<"."<<endl;
        }else{
            cout<<"Warrior "<<name<<" attacks "<<opponent.getName()<<" --- SLASH!!"<<endl;
            opponent.damage(this->health/MAX_HEALTH * attackStrength );
            cout<<opponent.getName()<<" takes "<<this->health/MAX_HEALTH * attackStrength<<" damage."<<endl;
        }
    }
    else{
        cout<<"Warrior "<<name<<" attacks "<<opponent.getName()<<" --- SLASH!!"<<endl;
        cout<<opponent.getName()<<" takes "<<this->health/MAX_HEALTH * attackStrength<<" damage."<<endl;
        opponent.damage(this->health/MAX_HEALTH * attackStrength );
    }
}
string Warrior::getAllegiance(){
    return allegiance;
}

