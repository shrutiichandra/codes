//g++ permu.cpp -o permu
// https://leetcode.com/problems/permutations/
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;
int factorial(int n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 
vector<int> nextPermutation(vector<int>& nums) {
	cout<<"--in nextPermutation--- ";
	for(auto i:nums){
		cout<<i<<" ";
	}
	cout<<"\n";
	vector<int> ans;
	int n_len=nums.size();
	int next_larger;
	int index;
	int flag=0;
	for(int i=n_len-1;i>=1&&!flag;i--){
		//scan from right
		cout<<i<<", "<<nums[i]<<", "<<nums[i-1]<<"\n";
		if(nums[i] > nums[i-1]){
			index=i;
			//find just larger number of nums[i-1] in i to n_len-1
			flag=1;
			int diff;
			int close=INT_MAX;
			for(int j=i;j<n_len;j++){
				diff=nums[j]-nums[i-1];
				cout<<j<<", diff: "<<diff<<"\n";
				if(diff<=close && diff>0 ){
					cout<<"updating close\n";
					close=diff;
					next_larger=j;
				}
			}

			// cout<<"swap: "<<i-1<<"th number: "<<nums[i-1]<<", "<<next_larger<<"th number: "<<nums[next_larger]<<"\n";
			swap(nums[index-1],nums[next_larger]);
		}
	}
	reverse(nums.begin()+index,nums.end());
	ans=nums;
	return ans;

}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> v;
	vector <int> arr(nums.begin(), nums.end());
	sort(nums.begin(), nums.end());
	int times=factorial(nums.size());
	v.push_back(nums);
	arr=nums;
	for(int i=0;i<times-1;i++){
		vector<int> temp;
		temp=nextPermutation(arr);
		v.push_back(temp);
		arr=temp;
	}
	return v;        
}
int main(){
	vector <int> n{1,2,3};
	vector<vector<int> >v;
	v=permute(n);
	for(auto i: v){
		for(auto j: i){
			cout<<j<<" "; 
		}
		cout<<"\n";
	}

	return 0;
}