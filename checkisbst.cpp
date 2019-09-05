//g++ -o checkisbst checkisbst.cpp
#include <iostream>

using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;

};

Node* newnode(int n);
bool checkBST(Node* root);
bool window(Node* root,Node* min,Node* max);
void print(Node* root);
int main(){	
	Node* root=newnode(0);
	root->left=newnode(-1);
	// root->right=newnode(7);
	// root->left->left=newnode(1);
	// root->left->right=newnode(9);
	cout<<"---print---\n";
	print(root);
	cout<<"\n";
	checkBST(root) ? cout<<"Yes a bst\n" : cout<<"oops, not a bst\n";

	return 0;
}

void print(Node* root){
	if(root==NULL)
		return;
	cout<<root->val<<" ";
	print(root->left);
	print(root->right);
}

Node* newnode(int n){
	Node* temp=new Node; //malloc,calloc
	temp->val=n;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
} 

bool checkBST(Node* root){
	return window(root,NULL,NULL);
}
bool window(Node* root,Node* min,Node* max){

	if(root==NULL) return true; 
	
	if(min!=NULL && root->val <= min->val){
		return false;
	}

	if(max!=NULL && root->val >= max->val){
		return false;
	}

	bool left;
	if(root->left!=NULL){
		left=window(root->left,min,root);
	}
	else{
		left=true;
	}
	bool right;
	if(left){
		if(root->right!=NULL){
			right=window(root->right,root,max);
		}
		else{
			right=true;
		}
		return right;
	}
	else{
		return false;
	}
}