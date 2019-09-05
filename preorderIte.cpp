//g++ preorderIte.cpp -o preorderIte
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "common_utils.h"
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

};

TreeNode* newnode(int n);
void print(TreeNode* root);
vector<int> preorderIterative(TreeNode* root){
	vector <int> ans;
    stack <TreeNode*> s;
    if(!root){
        return ans;
    }
    s.push(root);
    cout<<"push "<<root->val<<"\n";
    while(!s.empty()){
        TreeNode* top=s.top();

        ans.push_back(top->val);
        cout<<"push_back  "<<top->val<<", ";
        s.pop();
        cout<<"pop \n";
        if(top->right!=NULL){
            s.push(top->right);
            cout<<"push "<<top->right->val<<"\n";
        }
        if(top->left!=NULL){
        
            s.push(top->left);
            cout<<"push "<<top->left->val<<"\n";

        }
    }
    
    return ans;
}


int main(){
	TreeNode* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);

	vector<int> v;
	v=preorderIterative(root);
	printVector(v);
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