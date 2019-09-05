// g++ pathSum2.cpp -o pathSum2
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

void hasPathSum(TreeNode* root, int sum,vector <vector<int>>& res,vector <int> temp) {
    
    if(root==NULL){
        temp.pop_back();
        return;
    }
    cout<<"root->val: "<<root->val<<", sum: "<<sum<<"\n";
    
    temp.push_back(root->val);
    sum-=root->val;

    if(root->left==NULL && root->right==NULL && sum==0){
       
        res.push_back(temp);
       
        return;
    }

        hasPathSum(root->left,sum,res,temp);
        hasPathSum(root->right,sum,res,temp);   
    
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector <vector<int>> res;
    vector <int> temp;
    
    hasPathSum(root,sum,res,temp);
    return res;
}


int main(){ 
    TreeNode* root=newnode(-4);
    root->left=newnode(-5);
    root->right=newnode(4);
    root->left->left=newnode(5);
    // root->left->right=newnode(3);
    root->left->left->left=newnode(-2);

    // root->left->left->right=newnode(2);
    root->right->left=newnode(3);
    root->right->left->left=newnode(6);
    root->right->left->left->left=newnode(2);
    root->right->left->left->right=newnode(-2);

    // root->right->right=newnode(4);
    // root->right->right->left=newnode(5);
    // root->right->right->right=newnode(1);

    cout<<"---print---\n";
    print(root);
    cout<<"\n";
    int sum=-6;
    cout<<"has path sum "<<sum<<":\n";

    vector <vector <int>> v;
    v=pathSum(root, sum);
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