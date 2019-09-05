//g++ -o mirrorimage mirrorimage.cpp
#include <iostream>
#include <vector>
using namespace std;

//mirror image of a binary tree, reverse printing inorder traversal

struct Node{
	int val;
	Node* left;
	Node* right;

};

Node* newnode(int n);
void mirror(Node* root);
void inorder(Node* root);

vector<int> traver;
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
	inorder(root);
	for(int i=0;i<traver.size();i++)
		cout<<traver[i]<<" ";
	
	cout<<endl;
	for(int i=traver.size()-1;i>=0;i--)
		cout<<traver[i]<<" ";
}
void inorder(Node* root){
	if(root==NULL) return;
	inorder(root->left);
	traver.push_back(root->val);
	inorder(root->right);

}