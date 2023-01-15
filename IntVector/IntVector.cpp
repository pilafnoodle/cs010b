#include "IntVector.h"
#include <stdexcept>
#include <iostream>
using namespace std;


//default constructor
IntVector::IntVector(){//added this
    _size=0;
    _capacity=0;
    _data=new int[0];
}

IntVector::IntVector(unsigned capacity){
    _size=capacity;
    _capacity=capacity;
    _data=new int[capacity]; 
}

/*Sets both the size and capacity of the IntVector to the value of the parameter passed in
and dynamically allocates an array of that size as well. 
However, if the capacity is 0, then there is no array. 
Make sure you do not leave a dangling pointer.
This function should initialize all elements (if any) of the array to the value of the 2nd parameter.*/
IntVector::IntVector(unsigned capacity, int value){
    _size=capacity;
    _capacity=capacity;
    _data = new int[capacity];
    //IntVector v=new int[capacity];
    //_data = &v;

    unsigned i;
    for(i=0;i<capacity;i++){
        _data[i]=value;
    }
}

/*The destructor is used to clean up (delete) any remaining dynamically-allocated memory.
For this class, that will be the array pointed to by the int pointer named _data.*/
IntVector::~IntVector(){
    delete _data;
}

//This function returns the current size (not the capacity) of the IntVector object, 
//which is the values stored in the _size member variable.
unsigned IntVector::size() const{
    return _size;//why is it not _data->_size

}

//This function returns the current capacity (not the size) of the IntVector object, 
//which is the value stored in the _capacity member variable.
unsigned IntVector::capacity() const{
    return _capacity;

}

//Returns whether the IntVector is empty (_size is 0).
bool IntVector::empty() const{
    return _size==0;
}

//This function will return the value stored in the element at the passed in index position.
// Your function should throw an outofrange exception if an invalid index is passed in.
// An invalid index is an index greater than or equal to the size.
const int & IntVector::at(unsigned index) const{
   
    if(index>_size-1||_size==0){
        throw out_of_range("IntVector::at_range_check");      
    }
    else{ 
        return _data[index]; 
    }
}


//This function will return the value stored in the first element of the IntVector. 
//This function does not check the size of the IntVector or the array. 
//If the IntVector is empty then calling this function causes undefined behavior.
const int & IntVector::front() const{
    return _data[0];
}


//This function will return the value stored in the last element of the IntVector. 
//This function does not check the size of the IntVector or the array.
//If the IntVector is empty then calling this function causes undefined behavior.
const int & IntVector::back() const{
    return _data[_capacity-1];
}

// void insert(unsigned index, int value);
// void erase(unsigned index);
// int & back();
// int & front();
// void assign(unsigned n, int value);
// void push_back(int value);
// void pop_back();
// void clear();
// void resize(unsigned size, int value = 0);
// void reserve(unsigned n);

//This function will double the capacity of the vector.
// This function should reallocate memory for the dynamically allocated array and update the value of capacity.
// Make sure your expand() function properly handles the case when capacity is 0. 
//This will be a special case within the expand() function. 
//Since doubling 0 still gives you 0, you should set capacity to 1 in this special case.
//Make sure you don't create a memory leak here.
void IntVector::expand(){ 
    int* temp =_data;
    if(_capacity>0){
        _capacity=_capacity*2; 
        _data = new int[_capacity];
        unsigned i;
        for(i=0;i<_size;i++){
            _data[i]=temp[i];
        }
    }else{
        _capacity=1;
        _data = new int[_capacity];

    }
    delete[] temp;

}
//This function will expand the capacity of the vector by the amount passed in. 
//This function should reallocate memory for the dynamically allocated array and update the value of capacity.
//make sure you don't create a memory leak here.
void IntVector::expand(unsigned amount){
    int* temp =_data; //creates int pointer that is equal to _data
    _capacity=_capacity+amount; //increases capacity
    _data = new int[_capacity];//reallocate data to new, larger capacity value (also resets array)
    unsigned i;
    for(i=0;i<_size;i++){
        _data[i]=temp[i];//fill it with what is stored in temp
    }
    delete[] temp;
}

void IntVector::insert(unsigned index, int value){ //not sure what i am doing here
    if(index>_size){//used to be _capacity
        throw out_of_range("IntVector::insert_range_check");
    }
    if(_size+1 > _capacity){ 
        expand();
    }
    _size+=1;
    unsigned i;
    for(i=_size - 1; i>index;i--){
        _data[i]=at(i-1);
    }
    _data[index]=value;
}
void IntVector::erase(unsigned index){
    if(index>=_size){
        throw out_of_range("IntVector::erase_range_check");
    }
    unsigned i;
    for(i=index; i<_size;i++){
        if(!(i==_size-1)){
            _data[i]=at(i+1);
        }
    }
    _size=_size-1;
}
void IntVector::push_back(int value){
    //Size will be increased by 1. However, If size will become larger than capacity,
    //  this function needs to first increase the capacity. In other words, if capacity and size are both 20 
    //  when this function is called, capacity must first be increased to 40 and then size can be increased to 21.
    if(_size+1>_capacity){
        expand();
    }
    _size+=1;

    _data[_size-1]=value;

}
void IntVector::pop_back(){
    
    _size=_size-1;
}

void IntVector::resize(unsigned size, int value ){
    //If size is smaller than the current size(_size), this function just reduces the value of _size to size.
    //If size is greater than the current size(_size), then the appropriate number of elements are inserted at the end of the vector,
    //giving all of the new elements the value passed in through the 2nd parameter (value).]
    //If the new value of size will be larger than capacity, then the capacity must first be expanded by either doubling (expand())
    // or by increasing the capacity by a specific amount (expand(new size - current capacity)), 
    //whichever results in the largest capacity. Then, this function can increase the size appropriately.
    if(size<_size){
        _size=size;
        return;
    }  
    if(size>_capacity){
        if(_capacity*2 >  _size + size - _capacity){
            expand();
        }else{
            expand(size - _capacity);
        }
    }
    while(size!=_size){
        push_back(value);
    }
}

void IntVector::reserve(unsigned n){
    if(n>_capacity){
        expand(n-_capacity);
    }
}

void IntVector::assign(unsigned n, int value){
   // clear();
    //Assigns new content to the vector object,
    //dropping all the elements contained in the vector before the call
    // and replacing them by those specified by the parameters. 
    //The new value of size will be n and all values stored in the vector will have the value of the 2nd parameter.

    //If the new value of size will be larger than capacity,
     //then this function must first expand capacity by either double (expand()) 
     //or by increasing the capacity by a specific amount (expand(n - capacity)), whichever results in the largest capacity.

    if(n>_capacity){
        if(_capacity*2 > n ){ //n is equal to the new value of size
            expand();
        }else{
            expand(n - _capacity);
        }
    }
    _size=n;
    unsigned i;
    for(i=0; i<n;i++){
        _data[i]=value;
    }
}


int & IntVector::back(){
    return _data[_capacity-1];
}
int & IntVector::front(){
    return _data[0];

}

int & IntVector::at(unsigned index){
    if(index>_size-1||_size==0){
        throw out_of_range("IntVector::at_range_check");      
    }
    else{ 
        return _data[index]; 
    }
}

void IntVector::clear(){
    _size=0;
}


