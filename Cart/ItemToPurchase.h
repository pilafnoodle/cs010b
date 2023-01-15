using namespace std;
#include <iostream>
#include<string>
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H


class ItemToPurchase{
    public:
    //default constructor
    ItemToPurchase();
    //parameterized constructor
    ItemToPurchase(string n, string d,int p, int q);

    //getters/setters
    void setName(string n);
    string name();//originally getName()
    void setPrice(int p);
    int price();//originally getprice()
    void setQuantity(int q);
    int quantity();//originally getquantitin
    void setDescription(string d);
    string description();//originally getDescritption()

    void printItemCost();// - Outputs the item name followed by the quantity, price, and subtotal
    void printItemDescription();//- Outputs the item name and description
   
    private:
        string _name;
        int _price;
        int _quantity;
        string _description;
};

#endif
