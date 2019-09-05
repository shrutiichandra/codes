//g++ -o lca lca.cpp
#include <iostream>
using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;

};

Node* newnode(int n);
Node* findLCA(Node* root,int a,int b);
void print(struct Node* root);
int main(){	
	Node* root=newnode(4);
	root->left=newnode(2);
	root->right=newnode(6);
	root->left->left=newnode(1);
	root->left->right=newnode(3);
	root->right->left=newnode(5);
	root->right->right=newnode(7);
	cout<<"print--\n";
	print(root);
	cout<<"\n";
	cout<<"LCA(1,3): "<<findLCA(root,1,3)->val<<endl;
	cout<<"LCA(7,3): "<<findLCA(root,7,3)->val<<endl;
	return 0;
}

Node* newnode(int n){
	Node* temp=new Node; //malloc,calloc
	temp->val=n;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
} 

Node* findLCA(Node* root,int a,int b){
	Node* left_anc;
	Node* right_anc;
	if(root==NULL) return NULL;

//if any one of the a or b is present on root, root itself is the ca
	if(root->val==a||root->val==b)
		return root;

	left_anc=findLCA(root->left,a,b);
	right_anc=findLCA(root->right,a,b);

	if(left_anc!=NULL && right_anc!=NULL) return root;
	if(left_anc==NULL) return right_anc;
	if(right_anc==NULL) return left_anc;
}
void print(struct Node* root){
	if(root==NULL)
		return;
	cout<<root->val<<" ";
	print(root->left);
	print(root->right);
}