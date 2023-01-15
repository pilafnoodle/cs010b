#include "Character.h"
#include "Elf.h"
#include <string>
#include <iostream>
using namespace std;

Elf::Elf(string name, double health, double atk,string family):Character(ELF,name, health,atk),family(family){
}

void Elf::attack(Character &opponent){
    
    
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);

        if(family == opp.getFamily()){

            cout<<"Elf "<<name<<" does not attack Elf "<<opp.getName()<<"."<<endl;
            cout<<"They are both members of the "<<family<<" family."<<endl;
        }else{
            cout<<"Elf "<<name<<" shoots an arrow at "<<opponent.getName()<<" --- TWANG!!"<<endl;
            opponent.damage(this->health/MAX_HEALTH * attackStrength );
            cout<<opponent.getName()<<" takes "<<this->health/MAX_HEALTH * attackStrength<<" damage."<<endl;
        }

    }else{
        cout<<"Elf "<<name<<" shoots an arrow at "<<opponent.getName()<<" --- TWANG!!"<<endl;
        opponent.damage(this->health/MAX_HEALTH * attackStrength );
        cout<<opponent.getName()<<" takes "<<this->health/MAX_HEALTH * attackStrength<<" damage."<<endl;
    }

}
string Elf::getFamily(){
    return family;
}