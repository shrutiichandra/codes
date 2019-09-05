//g++ rotateLL.cpp -o rotateLL
#include <iostream>

using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
};
ListNode* insertAtFront(struct ListNode* head,int k){
	cout<<"inserting "<<k<<"\n";
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
int countNodes(ListNode* head){
    ListNode* temp=head;
    int count=0; 
   
    return count;
}
ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL){
        return head;
    }

    int count=1;
    ListNode* temp=head;
    ListNode* newHead=newHead;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
	cout<<count<<" nodes, ";
    if(k>count){
        k=k%count;
    }
    cout<<"k: "<<k<<"\n";
    
    if(k==0){
        return head;
    }
 
    if(k==count)
    	return head;
  	
  	temp->next=head;

  	for(int i=0;i<count-k;i++){
  		temp=temp->next;
  	}

  	head=temp->next;
  	temp->next=NULL;
  	return head;
}
int main(){
	struct ListNode* head=new ListNode;
	head=NULL;
	for(int i=3;i>=1;i--){
		head=insertAtFront(head,i);
	}
	print(head);
	head=rotateRight(head,2);
	print(head);
}

