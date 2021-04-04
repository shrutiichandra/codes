//g++ -o mirrorswap mirrorswap.cpp
#include <iostream>
#include <vector>
using namespace std;

//mirror image of a binary tree, swap

struct Node{
	int val;
	Node* left;
	Node* right;

};

Node* newnode(int n);
void mirror(Node* root);
void inorder(Node* root);

int main(){	
/*
	Node* root=newnode(4);
	root->left=newnode(2);
	root->right=newnode(6);
	root->left->left=newnode(1);
	root->left->right=newnode(3);
	root->right->left=newnode(5);
	root->right->right=newnode(7);
*/


	Node* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	

	mirror(root);
	inorder(root);
	
	return 0;
}

Node* newnode(int n){
	Node* temp=new Node; //malloc,calloc
	temp->val=n;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
} 

void mirror(Node* root){
	
	if(root==NULL) return;
	else{cout<<"Root is: "<<root->val<<endl;
	
		Node* temp;
		mirror(root->left);
		mirror(root->right);

	if(root->left!=NULL&&root->right!=NULL)	cout<<"Swap: "<<root->left->val<<" and "<<root->right->val<<endl;
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}

}
void inorder(Node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);

}