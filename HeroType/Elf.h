#include <string>
#include"Character.h"
#ifndef _ELF_H
#define _ELF_H


class Elf:public Character
{
private:
    string family;
public:
    Elf(string, double, double,string);
    string getFamily();
    void attack(Character &) override;
};

#endif