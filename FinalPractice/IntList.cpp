#include "IntList.h"
#include <iostream>

/* Initializes an empty list.
*/
IntList::IntList() : head(nullptr) {}

/* Inserts a data value to the front of the list.
*/
void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } 
   else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

void IntList::swapHeadAndTail() {

   //working special cases:
   if(head==nullptr||head->next==nullptr){//0 or 1 element
      return;
   }else if(head->next->next==nullptr){//2 elements
      //swap the two nodes
   }

   IntNode *seclast=nullptr; //second to last node

   for(IntNode *curr=head; curr!=nullptr; curr=curr->next){

      if(curr->next->next==nullptr){
         seclast=curr;
         break;
      }
   }


   IntNode *tail = seclast->next; //tail is the next node of the second to last node

   tail->next=head->next;

   seclast->next=head; //segfault happens here

   head->next=nullptr; 

   head=tail;

   tail=seclast->next;


}
