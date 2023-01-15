using namespace std;
#include <iostream>
#include<string>
#include<vector>
#include "ShoppingCart.h"


ShoppingCart::ShoppingCart(){
    this->_customerName="none";
    this->_currentDate="January 1, 2016";
}
ShoppingCart::ShoppingCart(const string customerName,const string currentDate){
    this->_customerName=customerName;
    this->_currentDate=currentDate;
}

string ShoppingCart::customerName(){
    return _customerName;
}
string ShoppingCart::date(){
    return _currentDate;
}
void ShoppingCart::addItem(ItemToPurchase item){
    _cartItems.push_back(item);
}
void ShoppingCart::removeItem(string itemName){
   bool found=false;
   unsigned i;
    for(i=0; i<_cartItems.size();i++){
        if(_cartItems.at(i).name()==itemName){
            _cartItems.erase(_cartItems.begin()+i); // why does this line work
            found=true;
        }
    }
    if(!found){   

        cout<<"Item not found in cart. Nothing removed."<<endl;
    }
}

//tester function delete 
void ShoppingCart::testItems(){
    unsigned i;
    for(i=0; i<_cartItems.size();i++){
        cout<<_cartItems.at(i).name()<<endl;
    }
}

void ShoppingCart::modifyItem(ItemToPurchase item){ //not tested yet
    unsigned i;
    bool found=false;
    for(i=0; i<_cartItems.size();i++){
        if(item.name()==_cartItems.at(i).name()){
            found=true;
            if(found){
                cout<<endl;
            }
            if(_cartItems.at(i).price()!=0){
                _cartItems.at(i).setPrice(_cartItems.at(i).price());
            }
            if(_cartItems.at(i).quantity()!=0){ //if the item with the same name has a quantity that isn't 0
                                                //set that item with
                _cartItems.at(i).setQuantity(item.quantity()); //   _cartItems.at(i).setQuantity(_cartItems.at(i).quantity());

            }
            if(_cartItems.at(i).description()!="none"){
                _cartItems.at(i).setDescription(_cartItems.at(i).description());
            }
        }

    }
    if(!found){
        //cout<<endl;
        cout<<"Item not found in cart. Nothing modified."<<endl;//PUT THIS BACK
        //delest this
        cout<<endl;
    }
    

}

int ShoppingCart::numItemsInCart(){
    int numItems=0;
    unsigned i;
    for(i=0; i<_cartItems.size();i++){
        numItems+=_cartItems.at(i).quantity();
    }
    return numItems;
}
int ShoppingCart::costOfCart(){
    int totalCost=0;
    unsigned i;
    for(i=0; i<_cartItems.size();i++){
        totalCost+=_cartItems.at(i).quantity()*_cartItems.at(i).price();
    }
    return totalCost;
}
void ShoppingCart::printTotal(){

    cout<<customerName()<<"'s Shopping Cart - "<<date()<<endl;
    cout<<"Number of Items: "<<numItemsInCart()<<endl;
    cout<<endl;
    
    if(_cartItems.size()==0){
        cout<<"SHOPPING CART IS EMPTY"<<endl;
    }
    unsigned i;
    for(i=0;i<_cartItems.size();i++){
        _cartItems.at(i).printItemCost();
    }
    cout<<endl;
    cout<<"Total: $"<<costOfCart()<<endl;
    cout<<endl;
}
void ShoppingCart::printDescriptions(){
    cout<<customerName()<<"'s Shopping Cart - "<<date()<<endl;
    cout<<endl;
    unsigned i;
    cout<<"Item Descriptions"<<endl;
    for(i=0;i<_cartItems.size();i++){
        _cartItems.at(i).printItemDescription();
    }
    cout<<endl;
}

