#include "IntVector.h"
using namespace std;
#include<iostream>

int main(){

    cout<<"declaring vectors to test on"<<endl;
    IntVector* inv1=new IntVector(0);
    //IntVector* inv2=new IntVector(0);

    inv1->push_back(5);
    inv1->push_back(1000);
    inv1->push_back(42);

    if(inv1->size()!=3){
        cout<<"Failed size()"<<endl;
    }
    if(inv1->capacity()!=4){
        cout<<"Failed capacity()"<<endl;

    }
    if(inv1->empty()){
        cout<<"Failed empty()"<<endl;
    }
    if(inv1->at(1)!=1000){
        cout<<"Failed at()"<<endl;
    }
    if(inv1->front()!=5){
        cout<<"failed front()"<<endl;
    }
    if(inv1->back()!=0){
        cout<<"Failed back()"<<endl;
    }

    inv1->insert(0,8);

    if(inv1->at(0)!=8){
        cout<<"Failed insert()"<<endl;
    }
    inv1->erase(1);

    if(!(inv1->size()==3)){
        cout<<"Failed erase()"<<endl;
    }

    inv1->push_back(282);

    if(inv1->back()!=282){
        cout<<"Failed push_back()"<<endl;
    }

    inv1->pop_back();

    if(inv1->size()!=3){
        cout<<"Failed pop_back()"<<endl;
    }
    
    
    // void resize(unsigned size, int value = 0);
    // void reserve(unsigned n);
    // void assign(unsigned n, int value);
    inv1->clear();
    if(!inv1->empty()){
        cout<<"Failed clear()"<<endl;
    }

    cout<<"tests complete"<<endl;

}