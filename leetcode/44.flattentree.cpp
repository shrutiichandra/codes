//g++ flattentree.cpp -o flattentree
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

};

TreeNode* newnode(int n);
void print(TreeNode* root);
void flatten(TreeNode* root) {
   
    if(root==NULL || root->left==NULL && root->right==NULL){
        cout<<"returning\n";
        return;
    }
    cout<<"\nroot- "<<root->val<<" ";
    if(root->left!=NULL){
        cout<<"root->left: "<<root->left->val<<"\n";
        flatten(root->left);
        TreeNode* tempR=root->right;
        // cout<<"tempR: "<<tempR->val<<" ";
        root->right=root->left;
        // cout<<"new root right: "<<root->right->val<<" ";
        root->left=NULL;
        TreeNode* tempNewR=root->right;

        while(tempNewR->right!=NULL){
            tempNewR=tempNewR->right;
        }
        tempNewR->right=tempR;
        // cout<<"tempNewR->right: "<<tempNewR->right->val<<"\n";
    }
    cout<<"root: "<<root->val<<" | root->right: "<<root->right->val<<"\n";
    flatten(root->right);
   cout<<root->val<<" exit \n";
}
int main(){
	TreeNode* root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(5);
	root->left->left=newnode(3);
	root->left->right=newnode(4);
    root->right->right=newnode(6);
    root->left->left->left=newnode(7);
	root->left->left->right=newnode(8);
    root->left->right->left=newnode(9);
    
	print(root);
    cout<<"\n";
    flatten(root);
    cout<<"flattened: ";
    print(root);
    cout<<"\n";
	return 0;
}
void print(TreeNode* root){
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);

}

TreeNode* newnode(int n){
    TreeNode* temp=new TreeNode; //malloc,calloc
    temp->val=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
} 