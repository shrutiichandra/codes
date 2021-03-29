//g++ levelOrder.cpp -o levelOrder
// https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;

};

TreeNode* newnode(int n);
void levelOrderHelper(TreeNode* root,vector <int>& levels, vector <vector <int>>& res);
void print(TreeNode* root);
vector<vector<int>> levelOrder(TreeNode* root);

int main(){	
	TreeNode* root=newnode(3);
	root->left=newnode(9);
	root->right=newnode(20);
	root->right->left=newnode(15);
	root->right->right=newnode(7);
	cout<<"---print---\n";
	print(root);
	cout<<"\n";
	cout<<"Level Order: \n";
	vector <vector <int> > v;
	v=levelOrder(root);

	for(auto i:v){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
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

void levelOrderHelper(TreeNode* root,vector <int>& levels, vector <vector <int>>& res){
   queue <TreeNode*> q;
    
    TreeNode* current=root;
    
    while(current){
        levels.push_back(current->val);
        
        if(current->left)
            q.push(current->left);
        if(current->right)
            q.push(current->right);
        
        current=q.front();
        q.pop();
        res.push_back(levels);
    }
    
    
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector <int> levels;
    vector <vector <int>> res;
    levelOrderHelper(root,levels,res);
    return res;
}