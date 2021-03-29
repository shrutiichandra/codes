//g++ -std=c++11 -o bst bst.cpp
//insertion and search in bst
//max depth
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	struct node* l;
	struct node* r;
	int key;
};

struct node* createNode(int k){
	struct node* newnode=new node;
	newnode->l=NULL;
	newnode->r=NULL;
	newnode->key=k;
	return newnode;
}

struct node* insert(struct node* root,int k){
	if(root==NULL){
		root=createNode(k);
		return root;
	}

	if(k<root->key){
		root->l=insert(root->l,k);
	}
	else 
		root->r=insert(root->r,k);

	return root;

}

bool search(struct node* root,int val){
	if(root==NULL){
		return false;
	}

	if(root->key==val)
		return true;

	if(root->key>val)
		search(root->l,val);
	else search(root->r,val);
}

bool searchIterative(struct node* root,int val){
	struct node* curr=root;
	struct node* parent=NULL;

	while(curr!=NULL&&curr->key!=val){
		parent=curr;
		if(curr->key>val)
			curr=curr->l;
		else curr=curr->r;

	}

	if(curr==NULL)
		return false;
	return true;
}

void mirror(struct node* node){
	if(node!=NULL){
		mirror(node->l);
		mirror(node->r);
		struct node* temp;
		temp=node->l;
		node->l=node->r;
		node->r=temp;
	}
}
void print(struct node* root){
	if(root==NULL)
		return;
	cout<<root->key<<" ";
	print(root->l);
	print(root->r);
}

int maxDepth(struct node* node){
	if(node==NULL) return 0;
	else{
		int l=maxDepth(node->l);
		int r=maxDepth(node->r);
		if(l>r)
			return l+1;
		else
			return r+1;
	}
}
int main(){
	vector<int> v{1,8,9,2,6,5};
	vector<int> v_test{3,5,1,9,0};
	struct node* root=NULL;
	for(int i=0;i<v.size();i++){
		root=insert(root,v[i]);
	}
	cout<<"--print--\n";
	print(root);
	cout<<"\n- Search--\n";
	for(int i=0;i<v_test.size();i++){
		cout<<v_test[i]<<": "<<search(root,v_test[i])<<"\n";
	}

	cout<<"\n- searchIterative--\n";
	for(int i=0;i<v_test.size();i++){
		cout<<v_test[i]<<": "<<searchIterative(root,v_test[i])<<"\n";
	}

	cout<<"maxDepth: "<<maxDepth(root)<<"\n";

	mirror(root);
	cout<<"--print Mirror--\n";
	print(root);

}