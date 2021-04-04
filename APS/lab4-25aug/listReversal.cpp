/*
Given a linked list and a number K.

Your task is to reverse the same linked list in group of K (K<=Number of nodes ) Nodes.

Number of Nodes <=1000000

Input Format

copy this stub to your code and complete the reverseK function

#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
};

struct node* reverseK(struct node* head, int k){
    //complete this function
}

void printLL(struct node* head){
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

Constraints

Do not use extra space

Output Format

complete the function and return the head pointer.

Sample Input 0

8
1 2 4 10 12 11 11 13
3

Sample Output 0

4
2
1
11
12
10
13
11


*/
#include<bits/stdc++.h>
using namespace std;

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
    }
    
    if(next!=NULL)
        head->next=reverseK(next,k);
    return prev;
}

void printLL(struct node* head){
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