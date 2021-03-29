//g++ -o dfs dfs.cpp 
#include <iostream>
#include <stack>
using namespace std;
bool visited[5];
void doDFS(struct Node* root);
void print(struct Node* root);

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int n){
	struct Node* temp=new Node;
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int main(){
	struct Node* root=newNode(0);
	root->left=newNode(1);
	root->right=newNode(2);
	root->left->left=newNode(3);
	root->left->right=newNode(4);
	cout<<"--print--\n";
	print(root);
	cout<<"\n--dfs--\n";
	doDFS(root);
	cout<<"\n";
	for(int i=0;i<5;i++){
		visited[i]=false;
	}
}

void doDFS(struct Node* root){
	if(root==NULL) return;

	stack<Node *> dfs_s;
	cout<<"starting from "<<root->data<<endl;
	dfs_s.push(root);

	while(!dfs_s.empty()){

		Node *node=dfs_s.top();
		
	//	cout<<"front of queue: "<<node->data<<endl;
	
		dfs_s.pop();
	
		if(node->right!=NULL) dfs_s.push(node->right);
		if(node->left!=NULL) dfs_s.push(node->left);
		cout<<node->data<<" ";	
	}
}
void print(struct Node* root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}