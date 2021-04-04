//g++ zigzagLO.cpp -o zigzagLO
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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

void ithLevel(TreeNode* root, int level,int dir,vector<int>& lev, vector<vector<int>>& res){
    cout<<"level: "<<level<<"\n";
    
    if(root==NULL)
        return;
    if(level==1){
        lev.push_back(root->val);
    }
    else if(level>1 && dir%2==0){

        
        ithLevel(root->right, level-1,dir,lev, res);
        ithLevel(root->left, level-1,dir,lev, res);
    }
    else if(level>1 && dir%2==1){

        
        ithLevel(root->left, level-1,dir,lev, res);
        ithLevel(root->right, level-1,dir,lev, res);
    }
}

void zzLevelOrderHelper(TreeNode* root,vector<int>& lev, vector<vector<int>>& res){
    int h=findHeight(root);
    
    for(int i=1;i<=h;i++){
        cout<<"i: "<<i<<"\n";
        ithLevel(root,i,i,lev,res);
        res.push_back(lev);
        lev.clear();

    }
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector <int> levels;
    vector <vector <int>> res;
    zzLevelOrderHelper(root,levels,res);
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
    cout<<"ZigZagLevel Order: \n";
    vector <vector <int> > v;
    v=zigzagLevelOrder(root);

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