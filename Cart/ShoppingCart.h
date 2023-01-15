using namespace std;
#include <iostream>
#include<string>
#include<vector>
#include "ItemToPurchase.h"

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

class ShoppingCart{
    public:
        ShoppingCart();
        ShoppingCart(string customerName,string currentDate);
        string customerName();//originally getCustomerName()
        string date();
        void addItem(ItemToPurchase item);
        void removeItem(string itemName);
          
        //not implemented yet  
        void modifyItem(ItemToPurchase item);
        int numItemsInCart();
        int costOfCart();
        void printTotal();
        void printDescriptions();

        //delete this function
        void testItems();

    private:
        string _customerName;
        string _currentDate;
        vector<ItemToPurchase> _cartItems;
};
#endif