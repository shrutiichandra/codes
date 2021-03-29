//g++ hasPathSum.cpp -o hasPathSum
// https://leetcode.com/problems/path-sum/
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

};

TreeNode* newnode(int n);
void print(TreeNode* root);

bool hasPathSum(TreeNode* root, int sum) {
	bool res=false;
	if(root==NULL)
		return res;
	
	sum=sum-root->val;
	if(root->left==NULL && root->right==NULL && sum==0){
		return true;
	}


	res=hasPathSum(root->left,sum) || hasPathSum(root->right,sum);

	return res;        
}


int main(){ 
    TreeNode* root=newnode(5);
    root->left=newnode(4);
    root->right=newnode(8);
    root->left->left=newnode(11);
    root->left->left->left=newnode(7);
    root->left->left->right=newnode(2);
    root->right->left=newnode(13);
    root->right->right=newnode(4);
    root->right->right->right=newnode(1);

    cout<<"---print---\n";
    print(root);
    cout<<"\n";
    int sum=22;
    cout<<"has path sum: "<<sum<<" ";

    hasPathSum(root,sum)? cout<<"true\n" : cout<<"false\n";
    
    
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