#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList(){
    head=nullptr;
    tail=nullptr;
}
//memory leak?
IntList::~IntList(){
    while(!empty()){
        pop_front();
    }
    head=nullptr;
    tail=nullptr;
}
void IntList::push_front(int val){ 
    IntNode *newNode = new IntNode(val);
    if(empty()){
        head=newNode;
        tail=newNode;
    }else if(head->next==nullptr){
        IntNode *temp = head;
        head=newNode;
        newNode->next=temp;
        tail=temp;
    }
    else{
        IntNode *temp = head;
        head=newNode;
        newNode->next=temp;
    }
}
//memory leak?
//dangling pointer?
 //does the pop_front function delete the IntNode it removes from the list?
 //does it leave the tail pointer dangling when IntList becomes empty?

void IntList::pop_front(){
    if(head==nullptr){
        return;

    }else if(head->next==nullptr){  
        delete head;
        head=nullptr;
        tail=nullptr;
        return;
    }else{
        //cout<<"there is more than one item in the list"<<endl;
        IntNode *temp = head;
        head=head->next;
        delete temp;
    }
}

bool IntList::empty() const{
   return head==nullptr; 
}
const int & IntList::front() const{
    return head->value;
}
const int & IntList::back() const{
    return tail->value;
}
ostream & operator<<(ostream & out, const IntList &list){
    IntNode *temp = list.head;
    while(temp!=nullptr){
        out<<temp->value;

        if(temp->next!=nullptr){
            out<<" ";
        }
        temp = temp->next;
    }
    return out;
}

// Inserts a data value (within a new node) at the back end of the list.
void IntList::push_back(int value){
    IntNode *newNode = new IntNode(value);
    if(head==nullptr){
        head=newNode;
        tail=newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

//everything below this line is from program 5
IntList::IntList(const IntList &cpy){
    // cout<<"copy constructor running"<<endl;
    // cout<<"cleared this"<<endl;
    head=nullptr;
    tail=nullptr;
    IntNode *curr = cpy.head;
    while(curr!=nullptr){
        push_back(curr->value);
        curr=curr->next;
    }
} 

// the overloaded assignment operator. Make sure this performs deep copy.
IntList & IntList::operator=(const IntList &rhs){
    if(this==&rhs){
        return *this;
    }
    if(rhs.empty()){
        clear();  
        return *this;
    }
    clear();
    IntNode *curr = rhs.head;
    while(curr!=nullptr){
        push_back(curr->value);
        curr=curr->next;
    }
    return *this;
}

//: Removes (deallocates) all IntNodes in the IntList. 
//Don't forget to set both head and tail to appropriate values for an empty list. DO NOT leave them dangling!
void IntList::clear(){
   // cout<<"clearing list"<<endl;
    while(!empty()){
        pop_front();
    }
    head=nullptr;
    tail=nullptr;
}

//: Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
void IntList::selection_sort(){
    IntNode *step = head; 
    IntNode *pos;
    IntNode *minNode = nullptr;
    int temp=0;

    for(step=head; step!=nullptr; step=step->next){
        minNode=step;
        for(pos=step; pos!=nullptr; pos=pos->next){

            if(pos->value < minNode->value){
                minNode=pos;
            }
        }
        temp=step->value;
        step->value=minNode->value;
        minNode->value=temp;
    }
}


//: Inserts a data value (within a new node) in an ordered list. 
//Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.)
// This function loops through the list until if finds the correct position for the new data value and 
//then inserts the new IntNode in that location.
// This function may NOT ever sort the list.
void IntList::insert_ordered(int value){  
    // cout<<"inside insert ordered intlist, value: "<<value<<endl;
    IntNode *newNode = new IntNode(value);
    IntNode *curr=nullptr;
    if(empty()){
        head=newNode;
        tail=newNode;
        return;
    }
    else if(value<=head->value){
        push_front(value);
        return;
    }
    else if(value>=tail->value){
        push_back(value);
        return;
    }
    for(curr=head; curr->next!=nullptr; curr=curr->next){

        if((value>curr->value && value<curr->next->value) || value==curr->value){
                IntNode *temp = curr->next;
                newNode->next = temp;
                curr->next = newNode;
                return;
        }
    }
}

//: Removes all duplicate data values (actually removes the nodes that contain the values) within the list. 
//Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list.
//memory leak?
//dangling pointer?
void IntList::remove_duplicates(){

    if(head==nullptr && tail==nullptr){
        return;
    }
    IntNode *step=head;
    IntNode *prev = head;
    while(step!=nullptr){
        prev=step;
        IntNode *curr=step->next;
        while(curr!=nullptr){
            if(curr->value==step->value){
                IntNode *temp=curr -> next;
                delete curr;
                prev->next=temp;
                if (temp == nullptr) {
                    tail = prev;
                }
            }else{
                prev=prev->next;
            }
            curr=prev->next;
           
        }
        step=step->next;
    }
    // IntNode *step=nullptr;
    // IntNode *curr=head;
    // bool lastNodeDeleted=false;
    // for(step = head; step->next!=nullptr; step=step->next){
    //     //cout<<"outer step loop running"<<endl;
    //     curr=step;//sets curr to the new number to check for
    //     while(curr->next!=nullptr){
    //       //cout<<"inner curr loop running"<<endl;
    //         if(curr->next->value==step->value){
    //         //cout<<"found a duplicate"<<endl;
    //             if(curr->next->next!=nullptr){              
    //                 IntNode *temp=curr->next;//added this
    //                 curr->next=curr->next->next;
    //                 delete temp; //added this
    //             }else{
    //             //cout<<"deleting last node of list"<<endl;
    //                 delete curr->next;
    //                 tail=curr;
    //                 curr->next=nullptr;              
    //                 lastNodeDeleted =  true; 
    //                 break;
    //             }  
    //         }else{
    //             curr=curr->next;
    //         }
    //     }
    //     if(lastNodeDeleted){
    //         break;
    //     }
    // }
}
