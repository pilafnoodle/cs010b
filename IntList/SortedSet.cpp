#include "SortedSet.h"
#include "IntList.h"
#include <iostream>
using namespace std;

SortedSet::SortedSet():IntList(){
}
SortedSet::SortedSet(const SortedSet &newList):IntList(newList){
}
SortedSet::SortedSet(const IntList &newList):IntList(newList){
    selection_sort();
    remove_duplicates();
}
SortedSet::~SortedSet(){
    this->IntList::~IntList();
}

//This function returns true if the value passed in is a member of the set, otherwise false.
bool SortedSet::in(int value){
    // cout<<"value passed in is "<<value<<endl;

    IntNode *curr=head;
    while(curr!=nullptr){
        // cout<<"current value is "<<curr->value<<endl;
        if(curr->value==value){
            // cout<<"found match"<<endl;
            return true;
        }
        curr=curr->next;
    }
    return false;
}

// This function returns a SortedSet object that is the union of 2 SortedSet objects,

SortedSet SortedSet::operator|(const SortedSet &rhs){
    if(this->empty()){
        return rhs;
    }
    SortedSet result;

    for(IntNode *curr = rhs.head; curr!=nullptr; curr=curr->next){
        result.insert_ordered(curr->value);
    }

    for(IntNode *curr = head; curr!=nullptr; curr=curr->next){
        result.insert_ordered(curr->value);
    }
    return result;
}

//returns a set with elements that both operands have
SortedSet SortedSet::operator&(const SortedSet &rhs){
    SortedSet result;
    for(IntNode *curr = rhs.head; curr!=nullptr; curr=curr->next){
        if(in(curr->value)){
            result.push_back(curr->value);
        }        
    }
    return result;
}
//operator&=: This function is the intersection-assign operator function. 
//It returns an intersection of the left and right operands, 
//but also sets the left operand's value to be that intersection as well.
// In other words, sset1 &= sset2 is equivalent to sset1 = sset1 & sset2.
SortedSet SortedSet::operator&=(const SortedSet &rhs){
   SortedSet intersectionSet = *this & rhs;
    *this=intersectionSet;
    return *this;
}
SortedSet SortedSet::operator|=(const SortedSet &rhs){
    SortedSet unionSet = *this | rhs;
    *this=unionSet;

    return *this;
}

void SortedSet::add(int value){
    if(!in(value)){
        IntList::insert_ordered(value);
    }
}
void SortedSet::push_front(int value){
    add(value);
}
void SortedSet::push_back(int value){
    add(value);
}
void SortedSet::insert_ordered(int value){    
    add(value);
}
