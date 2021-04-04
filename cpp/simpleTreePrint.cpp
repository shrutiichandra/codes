//g++ simpleTreePrint.cpp -o simpleTreePrint
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

int main(){
	TreeNode* root=NULL;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(5);
	root->left->left=newnode(3);
	root->left->right=newnode(4);
	root->right->right=newnode(6);
	print(root);
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