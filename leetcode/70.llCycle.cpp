//https://leetcode.com/problems/linked-list-cycle-ii/
#include <iostream>
#include <algorithm>
// maynot work coz of import
#include "common_utils.h"
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    

};

ListNode* newnode(int n);
 ListNode *detectCycle(ListNode *head) {
  if(head==NULL || head->next==NULL)  {
      return NULL;
  }
    ListNode* slow=head->next;
    ListNode* fast=head->next->next;
    cout<<"before loop: slow: "<<slow->val<<" fast: "<<fast->val<<"\n";
     // ListNode* slow=head;
    // ListNode* fast=head->next;
    // ListNode* prev=head;
    // cout<<"slow: "<<slow->val<<" fast: "<<fast->val<<"\n";
    while(slow!=fast){
        if(fast==NULL || fast->next==NULL){
            return NULL;
        }
// prev=slow;
        slow=slow->next;
        // cout<<"slow: "<<slow->val<<" fast: "<<fast->val<<"\n";
        fast=fast->next->next;
    cout<<"in loop: slow: "<<slow->val<<" fast: "<<fast->val<<"\n";
    }
    cout<<"exit while1\n";
    cout<<"slow: "<<slow->val<<" fast: "<<fast->val<<"\n";
    slow = head; 
    while (slow != fast) { 

        slow = slow->next; 
        cout<<"slow: "<<slow->val<<"\n";
        fast = fast->next; 
        cout<<"fast: "<<fast->val<<"\n";
    } 

    cout<<"exit while2\n";
    return slow;
}

int main(){
	ListNode* node=newnode(3);
	ListNode* entry=newnode(2);
	node->next=entry;
	node->next->next=newnode(0);
	node->next->next->next=newnode(-4);
	node->next->next->next->next=entry;

	ListNode* ans=detectCycle(node);
	return 0;

}
ListNode* newnode(int n){
    ListNode* temp=new ListNode; //malloc,calloc
    temp->val=n;
    temp->next=NULL;
    return temp;
} 