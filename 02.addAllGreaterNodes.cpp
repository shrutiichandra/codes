//In a binary search tree, add the value of all the nodes greater than the present 
// node to the value of the present node
//g++ addAllGreaterNodes.cpp 
//./addAllGreaterNodes
#include<iostream> 
using namespace std; 

// A BST node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new Binary Tree Node 
struct Node *newNode(int item) 
{ 
	struct Node *temp = new Node; 
	temp->data = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

void transformNode(struct Node *root, int sum, int target) 
{ 
	if (root == NULL) return; 

	// Recur for right subtree 
	transformNode(root->right, sum, target); 

	// Update sum 
	if(root -> data == target){
		root -> data += sum;
	}

	// Recur for left subtree 
	transformNode(root->left, sum, target); 

} 

// A utility function to print indorder traversal of a 
// binary tree 
void printInorder(struct Node *root, int target, int& sum) 
{ 
	if (root == NULL) return; 

	printInorder(root->left, target, sum); 
	cout << root->data << " "; 
	if (root -> data > target){
		sum += root -> data;
	}
	printInorder(root->right, target, sum); 
} 

// Driver Program to test above functions 
int main() 

{ 
	/*
			11
		   /  \
		  2   29
		 / \  / \
		1  7  15 40
		         /
		        35
	*/
	int sum = 0;
	struct Node *root = newNode(11); 
	root->left = newNode(2); 
	root->right = newNode(29); 
	root->left->left = newNode(1); 
	root->left->right = newNode(7); 
	root->right->left = newNode(15); 
	root->right->right = newNode(40); 
	root->right->right->left = newNode(35); 
	int givenNodeKey = root->left->right->data;
	cout << "Inorder Traversal of given tree\n"; 
	printInorder(root, givenNodeKey, sum); 
	cout << "sum: " << sum << "\n";
	transformNode(root, sum, givenNodeKey); 

	cout << "\n\nInorder Traversal of transformed tree\n"; 
	printInorder(root,givenNodeKey, sum); 
	cout<<"\n";
	return 0; 
} 
