#include <string>
#include"Character.h"
#ifndef _WARRIOR_H
#define _WARRIOR_H


class Warrior:public Character
{
private:
    string allegiance;
public:
    
    Warrior(string, double, double,string);
    string getAllegiance();
    void attack(Character &) override;
};

#endif



