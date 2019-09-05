//g++ removeDupLL1.cpp -o removeDupLL1
#include <iostream>

using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
};
ListNode* insertAtFront(struct ListNode* head,int k){
	// cout<<"inserting "<<k<<"\n";
	struct ListNode* newNode = new ListNode;
	newNode->val=k;
	newNode->next=head;
	head=newNode;
	return head;
}
void print(ListNode* head){
	while(head!=NULL){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<"\n";
}

ListNode* deleteNode(ListNode* head, int key){
  ListNode* temp=head;
  ListNode* prev;

  if(temp!=NULL && temp->val==key){
    head=temp->next;

    return head;
  }

  while(temp!=NULL && temp->val!=key){

    prev=temp;
    temp=temp->next;

  }
  if(temp==NULL) return head;

  prev->next=temp->next;



  return head;
}
ListNode* deleteDuplicates(ListNode* head) {
  if(head==NULL){
      return head;
  }

  ListNode* dummy=new ListNode;
  dummy->val=0;
  dummy->next=head;
  ListNode* prev_node=dummy;
  ListNode* curr_node=head;
  // ListNode* next_node=prev_node->next;

  // curr_node=prev_node;
  while(curr_node!=NULL){
    ListNode* next_node=curr_node->next;
    if(next_node==NULL)
      break;
    
    int curr_val=curr_node->val;
    cout<<"curr_val: "<<curr_node->val;
    int next_val=next_node->val;
    cout<<" next_val: "<<next_node->val<<"\n";


    if(curr_val==next_val){
     ListNode* temp=head;
      // while(temp!=NULL){
        cout<<"delete: curr_val: "<<curr_val<<"\n";
        head=deleteNode(head,curr_val);
        // temp=temp->next;
      // }
    }
    curr_node=curr_node->next;

  }
  
	return head;
}
int main(){
	struct ListNode* head=new ListNode;
	head=NULL;
	
	head=insertAtFront(head,3);
  head=insertAtFront(head,3);
  head=insertAtFront(head,3);
  // head=insertAtFront(head,3);
  // head=insertAtFront(head,3);
  head=insertAtFront(head,1);
  head=insertAtFront(head,1);


	print(head);
	head=deleteDuplicates(head);
	print(head);
}

