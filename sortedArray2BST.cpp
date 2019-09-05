
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

};

TreeNode* newnode(int n);
void print(TreeNode* root);
TreeNode* sortedArrayToBSTHelper(vector<int>& nums,int beg,int end,int dir){
	if(beg>end)
		return NULL;
	int mid=(beg+end)/2;

	TreeNode* root=NULL;
	root=newnode(nums[mid]);

	root->left=sortedArrayToBSTHelper(nums,beg,mid-1,1);
	root->right=sortedArrayToBSTHelper(nums,mid+1,end,2);
	return root;

}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	TreeNode* root=NULL;
	int end=nums.size()-1;
	int beg=0;
	root=sortedArrayToBSTHelper(nums,beg,end,0);
	return root;
	
}

int main(){ 
	vector <int> v{-10,-3,0,5,9};

    TreeNode* root=NULL;
    root=sortedArrayToBST(v);
    
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