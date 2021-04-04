#include<bits/stdc++.h>
using namespace std;
void printLL(struct node* head);
struct node{
    int val;
    node* next;
};

struct node* reverseK(struct node* head, int k){
    //complete this function
    struct node* curr=head;
    struct node* prev;
    struct node* next;
    int i=0;
    prev=NULL;
    next=NULL;
    
    while(curr!=NULL&&i<k){
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
       i++;
       printLL(prev);
    }

    printLL(prev);
    
    if(next!=NULL)
        head->next=reverseK(next,k);
    return prev;
}

void printLL(struct node* head){
    cout<<"list is:";
    while(head){
        cout<<head->val<<endl;
        head = head->next;
    }
    return;
}
int main() {
    struct node* head = new node();
    struct node* insert = head;
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++){
        int temp;
        cin >> temp;
        struct node* data = new node();
        data->val = temp;
        insert->next = data;
        insert = insert->next;
        
    }
    head = head->next;
    int k;
    cin >> k;
    struct node* head_after_reversal = reverseK(head, k);
    printLL(head_after_reversal);
    return 0;
}