//waste
#include <iostream>
// /**
 // * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode* first=temp;
        ListNode* second=temp;
        
        for(int i=0; i<=n; i++){
            first=first->next; //moves n+1 steps
        }
        
        while(first!=NULL){
            first=first->next;
            second=second->next; //maintain gap
        }
        second->next=second->next->next; //unlink
        
        return temp->next;
    }
};

int main(){
    ListNode* n=new ListNode(1);
    n->next=

    return 0;
}