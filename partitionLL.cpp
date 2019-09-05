//g++ partitionLL.cpp -o partitionLL
//doubt!
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

ListNode* partition(ListNode* head, int x) {
	ListNode *smaller_x=NULL, *smaller_tail=NULL;
	ListNode *greater_x=NULL, *greater_tail=NULL;
	ListNode *equal_x=NULL,   *equal_tail=NULL;

	while(head->next!=NULL){
		cout<<"head->val: "<<head->val<<" ";
		if(head->val==x){
			cout<<"equal case\n";
			if(equal_x==NULL){
				equal_x=head;
				equal_tail=equal_x;
			}
			else{
				equal_tail->next=head;
				equal_tail=equal_tail->next;
			}
		}
		else if(head->val<x){
			cout<<"less than case\n";
			if(smaller_x==NULL){
				smaller_x=head;
				smaller_tail=smaller_x;
			}
			else{
				smaller_tail->next=head;
				smaller_tail=head;
			}
		}
		else if(head->val>x){
			cout<<"more than case\n";
			if(greater_x==NULL){
				greater_x=head;
				greater_tail=greater_x;
			}
			else{
				greater_tail->next=head;
				greater_tail=head;
			}
		}
		head=head->next;
	}

	if(greater_tail!=NULL){
		cout<<"greater not null\n";
		greater_tail->next=NULL;
	}

	if(smaller_x==NULL){
		cout<<"smaller empty, ";
		if(equal_x==NULL){
			cout<<"equal empty\n";
			return greater_x;
		}
		else{
			cout<<"equal not empty\n";
			equal_tail->next=greater_x;
			return equal_x;
		}
	}

	if(equal_x==NULL){
		cout<<"equal is empty\n";
		smaller_tail->next=greater_x;
		return smaller_x;
	}

	cout<<"smaller,equal non empty\n";
	smaller_tail->next=equal_x;
	equal_tail->next=greater_x;
	return smaller_x;
}

int main(){
	ListNode* node=new ListNode;
	node=insertAtFront(node,2);
	node=insertAtFront(node,5);
	node=insertAtFront(node,2);
	node=insertAtFront(node,3);
	node=insertAtFront(node,4);
	node=insertAtFront(node,1);
	cout<<"print: ";
	print(node);
	int x=3;
	cout<<"partitioning at val "<<x<<"\n";
	ListNode* newHead=new ListNode;
	newHead=partition(node,x);
	print(newHead);
	return 0;
}