/*
For the purposes of this challenge, we define a binary tree to be a binary search tree with the following ordering requirements:

    The 

value of every node in a node's left subtree is less than the data value of that node.
The

    value of every node in a node's right subtree is greater than the data value of that node.

Given the root node of a binary tree, can you determine if it's also a binary search tree?

Complete the function in your editor below, which has

parameter: a pointer to the root of a binary tree. It must return a boolean denoting whether or not the binary tree is a binary search tree. You may have to write one or more helper functions to complete this challenge.

Input Format

You are not responsible for reading any input from stdin. Hidden code stubs will assemble a binary tree and pass its root node to your function as an argument.

Constraints

Output Format

You are not responsible for printing any output to stdout. Your function must return true if the tree is a binary search tree; otherwise, it must return false. Hidden code stubs will print this result as a Yes or No answer on a new line.

Sample Input

tree

Sample Output

No

*/
/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	bool checkBST(Node* root){
    return window(root,-99999,99999);
}
int window(Node* root,int min,int max){
    int left,right;

    if(root==NULL) return 0; 
    if(root->left==NULL&&root->right==NULL){
        if(root->data>min&&root->data<max) return 1;
        return 0;
    }

    if(root->data<min||root->data>max) return 0;

    int upper_bound=root->data;

    left=window(root->left,min,upper_bound);

    int lower_bound=root->data;
    right=window(root->right,lower_bound,max);

    return left&&right; 

}