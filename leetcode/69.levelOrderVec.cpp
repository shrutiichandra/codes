//g++ levelOrderVec.cpp -o levelOrderVec
// https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

};

TreeNode* newnode(int n);
void print(TreeNode* root);

int findHeight(TreeNode* root){
    int h;
    if(root==NULL){
        return 0;
    }
    else{
        int l_height=findHeight(root->left);
        int r_height=findHeight(root->right);
        
        h=max(l_height,r_height)+1;
        return h;
    }    
}

void ithLevel(TreeNode* root, int level,vector<int>& lev, vector<vector<int>>& res){
    cout<<"level: "<<level<<"\n";
    
    if(root==NULL)
        return;
    if(level==1){
        cout<<"root: "<<root->val<<"\n";
        
        lev.push_back(root->val);
    }
    else if(level>1){

        // cout<<"root: "<<root->val<<"\n";
        ithLevel(root->right, level-1,lev, res);
        ithLevel(root->left, level-1,lev, res);
    }
}

void levelOrderHelper(TreeNode* root,vector<int>& lev, vector<vector<int>>& res){
    int h=findHeight(root);
    
    for(int i=1;i<=h;i++){
        cout<<"i: "<<i<<"\n";
        ithLevel(root,i,lev,res);
        res.push_back(lev);
        lev.clear();

    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector <int> levels;
    vector <vector <int>> res;
    levelOrderHelper(root,levels,res);
    return res;
}

int main(){ 
    TreeNode* root=newnode(3);
    root->left=newnode(9);
    root->right=newnode(20);
    root->right->left=newnode(15);
    root->right->right=newnode(7);
    cout<<"---print---\n";
    print(root);
    cout<<"\n";
    cout<<"Level Order: \n";
    vector <vector <int> > v;
    v=levelOrder(root);

    for(auto i:v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
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