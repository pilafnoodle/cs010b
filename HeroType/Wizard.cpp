#include "Wizard.h"
#include "Character.h"
#include <iostream>
Wizard::Wizard(string name, double health, double atk,int rank ):Character(WIZARD,name, health, atk) , rank(rank){

}
int Wizard::getRank(){
    return rank;
}
void Wizard::attack(Character &opponent){
    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        cout<<"Wizard "<<name<<" attacks "<<opp.getName()<<" --- POOF!!"<<endl;
        opp.damage(attackStrength*(static_cast<double>(rank)/static_cast<double>(opp.getRank())));
        cout<<opponent.getName()<<" takes "<<attackStrength*(static_cast<double>(rank)/static_cast<double>(opp.getRank()))<<" damage."<<endl;
    }else{
        cout<<"Wizard "<<name<<" attacks "<<opponent.getName()<<" --- POOF!!"<<endl;
        opponent.damage(attackStrength );
        cout<<opponent.getName()<<" takes "<<attackStrength<<" damage."<<endl;
    }
}