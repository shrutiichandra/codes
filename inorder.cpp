 //g++ -o ino inorder.cpp
#include <iostream>

using namespace std;

void doInorder(struct Node* node);

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int n){
	struct Node* temp=new Node;
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int main(){
	Node* root=newNode(8);
	root->left=newNode(7);
	root->right=newNode(9);
	root->left->left=newNode(10);
	root->left->right=newNode(1);
	root->right->left=newNode(4);
	root->right->right=newNode(5);
	doInorder(root);
	return 0;
}

void doInorder(struct Node* node){

	if(node==NULL) return;
	cout<<node->data<<" :presently\n";
	doInorder(node->left);
	cout<<"inorder: "<<node->data<<"\n";
	doInorder(node->right);
}