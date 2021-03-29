//g++ buildTreePreIn.cpp -o buildTreePreIn
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

};

TreeNode* newnode(int n);
void print(TreeNode* root);
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,int in_start,int in_end,int& pre_start) {
    cout<<"\ninorder: ("<<in_start<<" , "<<in_end<<" )\n";
    TreeNode* root=NULL;
    
    if(in_start<=in_end){
        
        int in_idx;
        for(int i=in_start; i<=in_end; i++){
            if(inorder[i]==preorder[pre_start]){
                in_idx=i;
                break;
            }
        }
        int preorder_root=preorder[pre_start];
        cout<<"current root: "<<preorder_root<<" ";
        
        root=newnode(preorder_root); 
        pre_start++;
        cout<<preorder_root<<" is present at index "<<in_idx<<" in inorder vec\n";
        
        root->left=buildTreeHelper(preorder,inorder,in_start,in_idx-1,pre_start);
        root->right=buildTreeHelper(preorder,inorder,in_idx+1,in_end,pre_start);
    }
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root;
    int in_start=0;
    int in_end=inorder.size()-1;
    int pre_start=0;
    root=buildTreeHelper(preorder,inorder,in_start,in_end,pre_start);
    return root;
}

int main(){ 
    vector <int> pre{3,9,20,15,7};
    vector <int> in{9,3,15,20,7};
    TreeNode* root;
    root=buildTree(pre,in);
    cout<<"---print---\n";
    print(root);
    cout<<"\n";
    
    return 0;
}

void print(TreeNode* root){
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

TreeNode* newnode(int n){
    TreeNode* temp=new TreeNode; //malloc,calloc
    temp->val=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
} 