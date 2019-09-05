// g++ connectTree.cpp -o connectTree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;

};

TreeLinkNode* newnode(int n);
void print(TreeLinkNode* root);


void connect(TreeLinkNode *root) {
    if(root==NULL)
        return;

    if(root->left!=NULL)
        root->left->next=root->right;

    if(root->right!=NULL && root->next!=NULL)
        root->right->next=root->next->left;

    connect(root->left);
    connect(root->right);
    // return;
}


int main(){
    TreeLinkNode* root=NULL;
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    print(root);
    cout<<"\n";
    connect(root);
    
    print(root);
    cout<<"\n";
    

    return 0;
}
void print(TreeLinkNode* root){
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);

}

TreeLinkNode* newnode(int n){
    TreeLinkNode* temp=new TreeLinkNode; //malloc,calloc
    temp->val=n;
    temp->left=NULL;
    temp->right=NULL;
    temp->next=NULL;
    return temp;
} 