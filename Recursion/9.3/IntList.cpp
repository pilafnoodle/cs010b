#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}
public function
bool IntList::exists(int x) const{
   return this->exists(head,x);
}
//private helper function
bool IntList::exists(IntNode *curr, int x) const{
   if(curr==nullptr){
      return false;
   }
   if(curr->value==x){
      return true;
   }
   return this->exists(curr->next,x);
}

ostream & operator<<(ostream &out, const IntList &list){
   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
   This function does NOT output a newline or space at the end.*/

   if(list.head==nullptr){
      return out;
   }
   out<<list.head->value;
   return operator<<(out, list.head->next);

}
//recursive
ostream & operator<<(ostream &out, IntNode *curr){
   if(curr==nullptr){
      return out;
   }else{
      out<<' ';
   }
   out<<curr->value;
   return operator<<(out,curr->next);
}

void IntList::swapHeadAndTail(){

   //swap head and tail nodes not values
   IntNode *seclast = head; // find the pointer to the last value
   IntNode *curr=head;
   while(curr->next->next!=nullptr){
      if(curr->next->next==nullptr){
         seclast=curr; // we've found the node before the last node
      }
      curr=curr->next;
   }
   IntNode *secfirst = head->next;

   //link seclast->next->next(last node's next pointer) to secfirst
   seclast->next->next=secfirst;
   //cut off seclast
   seclast->next=nullptr;

   // link head to next of seclast

   seclast->next=head;

   seclast->next->next=nullptr;

   IntNode *temptail=tail;
   
   tail=seclast->next;
   head=temptail;

}

