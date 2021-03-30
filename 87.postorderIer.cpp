//g++ postorderIer.cpp -o postorderIer
// https://leetcode.com/problems/binary-tree-postorder-traversal/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include "common_utils.h"
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

};

TreeNode* newnode(int n);
void print(TreeNode* root);
vector<int> postorderIterative(TreeNode* root){
    vector <int> ans;
    stack <TreeNode*> s;
    if(!root){
        return ans;
    }
    s.push(root);
    while(!s.empty()){
        TreeNode* top=s.top();
        ans.push_back(top->val);
        s.pop();
        
        if(top->left!=NULL){
        
            s.push(top->left);
        }
        if(top->right!=NULL){
            s.push(top->right);
        }
        
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
int main(){
	TreeNode* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);

	vector<int> v;
	v=postorderIterative(root);
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