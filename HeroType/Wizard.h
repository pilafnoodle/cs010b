#include <string>
#include"Character.h"
#ifndef _WIZARD_H
#define _WIZARD_H


class Wizard:public Character
{
private:
    int rank;
public:
    Wizard(string, double, double,int);
    int getRank();
    void attack(Character &) override;
};

#endif