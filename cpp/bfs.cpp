//g++ -o bfs bfs.cpp
#include <iostream>
#include <queue>

using namespace std;

struct Node* newNode(int d);
void doBFS(struct Node* root);
void print(struct Node* root);
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

int main(){
	/*
			1
		   / \
		  4   6
		 / \ /
		10 9 8
	*/

	Node *root=newNode(1);
	root->left=newNode(4);
	root->right=newNode(6);
	root->left->right=newNode(9);
	root->left->left=newNode(10);
	root->right->left=newNode(8);
	cout<<"---print--\n";
	print(root);
	cout<<"---BFS----\n";
	doBFS(root);
	return 0;
}

struct Node* newNode(int d){
	struct Node* temp=new Node;
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void doBFS(struct Node* root){
	if(root==NULL) return;

	queue<Node *> bfs_q;
	cout<<"starting from "<<root->data<<endl;
	bfs_q.push(root);

	while(!bfs_q.empty()){

		Node *node=bfs_q.front();
		cout<<"front of queue: "<<node->data<<endl;
		cout<<node->data<<"\n";
		bfs_q.pop();
		if(node->left!=NULL) bfs_q.push(node->left);
		if(node->right!=NULL) bfs_q.push(node->right);

	}

}
void print(struct Node* root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}