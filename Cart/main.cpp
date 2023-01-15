#include <iostream>
#include <sstream>
using namespace std;
#include "ItemToPurchase.h"
#include "ShoppingCart.h"


void printMenu(ShoppingCart c);

int main(){

    //In main(), prompt the user for a customer's name and today's date. Output the name and date. Create an object of type ShoppingCart.
    string newCustomer;
    string todaysDate;
    string dummyStr;
    istringstream inSS;

    cout<<"Enter customer's name: "<<endl; 
    getline(cin,dummyStr);
    inSS.clear();
    inSS.str(dummyStr);
    newCustomer=dummyStr; 
    cout<<"Enter today's date: "<<endl;
    inSS.clear();
    getline(cin,dummyStr);
    inSS.str(dummyStr);
    todaysDate=dummyStr;

    ShoppingCart c(newCustomer, todaysDate);


    cout<<endl;
    cout<<"Customer name: "<<newCustomer<<endl;
    cout<<"Today's date: "<<todaysDate<<endl;
    cout<<endl;

    string input;
    
    do{
        printMenu(c);
        cin>>input;

        while(input!="a"&&input!="o"&&input!="i"&&input!="d"&&input!="c"&&input!="q"){
            cout<<"Choose an option: "<<endl;
            cin>>input;

        }
            if(input=="a"){
                string newName;
                string newName2;
                string newDesc;
                int newPrice;
                int newQuantity;

                cout<<endl;
                cout<<"ADD ITEM TO CART"<<endl;
                cout<<"Enter the item name: "<<endl;
                cin.ignore();
                getline(cin,newName);
                cout<<"Enter the item description: "<<endl;
                getline(cin,newDesc);
                cout<<"Enter the item price: "<<endl;
                cin>>newPrice;
                cout<<"Enter the item quantity: "<<endl;
                cin>>newQuantity;
                cout<<endl;
                ItemToPurchase newItem(newName,newDesc,newPrice, newQuantity);
                c.addItem(newItem);
                
            }
            if(input=="o"){
                
                cout<<endl;

                cout<<"OUTPUT SHOPPING CART"<<endl;
                c.printTotal();
            }
            if(input=="i"){
                cout<<endl;
                cout<<"OUTPUT ITEMS' DESCRIPTIONS"<<endl;
                c.printDescriptions();
            }
            if(input=="d"){
                cout<<endl;
                string itemToRemove;
                cout<<"REMOVE ITEM FROM CART"<<endl;
                cout<<"Enter name of item to remove: "<<endl;

                cin.ignore();
                getline(cin,itemToRemove);
                c.removeItem(itemToRemove);

                 cout<<endl;//added this

            }
            if(input=="c"){
                cout<<endl;
                string itemName;
                int newQuantity;
                cout<<"CHANGE ITEM QUANTITY"<<endl;
                cout<<"Enter the item name: "<<endl;
                //cout<<endl;
                cin.ignore();
                getline(cin,itemName);
                cout<<"Enter the new quantity: "<<endl;
                cin>>newQuantity;                
                //cout<<endl; //uncoment this?

                ItemToPurchase dummy;
                dummy.setName(itemName);
                dummy.setQuantity(newQuantity);
                c.modifyItem(dummy);
            }
          
    }while(input!="q");

    return 0;
}
void printMenu(ShoppingCart c){
    cout<<"MENU"<<endl;
    cout<<"a - Add item to cart"<<endl;
    cout<<"d - Remove item from cart"<<endl;
    cout<<"c - Change item quantity"<<endl;
    cout<<"i - Output items' descriptions"<<endl;
    cout<<"o - Output shopping cart"<<endl;
    cout<<"q - Quit"<<endl;
    cout<<endl;
    cout<<"Choose an option: "<<endl;
}

