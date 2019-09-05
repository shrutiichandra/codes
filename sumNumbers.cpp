//g++ sumNumbers.cpp -o sumNumbers

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

void dfs(TreeNode* root, string s, vector<string>& v){
	if(root==NULL){
		cout<<"s push_back: "<<s<<"\n";
		
		s="";
		cout<<"return\n";
		return;
	}
	string temp=to_string(root->val);
	s+=temp;
	cout<<"s: "<<s<<"\n";
	if(root->left!=NULL){
		dfs(root->left,s,v);
	}
	if(root->right!=NULL){
		dfs(root->right,s,v);
	}

	// cout<<"no if\n";
	if(root->left==NULL && root->right==NULL){
		v.push_back(s);
		cout<<"leaf return\n";
		return;
	}

}

int sumNumbers(TreeNode* root) {
	int ans=0;
    string num="";
    vector <string> v;
    dfs(root, num, v);
    cout<<"vector: ";
    for(auto i:v){
    	ans+=stoi(i);
    }
    cout<<"\n";
    return ans;
}

int main(){ 
  
    TreeNode* root=NULL;
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    // root->left->left=newnode(4);
    // root->left->right=newnode(5);
    cout<<"---print---\n";
    print(root);
    cout<<"\n";
    cout<<"sum of all root to leaf paths: "<<sumNumbers(root)<<"\n";
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