// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void print(vector<int>& v){
	cout<<"---v:---\n";
	for(auto i:v){
		cout<<i<<" ";
	}
	cout<<"\n";
}
bool search(vector<int>& nums, int target) {
	bool ans=false;
	int size=nums.size();
	int rotated;
	bool flag=false;
	for(int i=0;i<size-1;i++){
		if(nums[i]>nums[i+1]){
			rotated=i;
			flag=true;
			break;
		}
		
	}
	if(flag){
	cout<<"rotated: "<<rotated<<"\n";
	vector<int> temp;
	for(int i=0;i<=rotated;i++){
		temp.push_back(nums[i]);
	}
	print(temp);
	nums.erase(nums.begin(),nums.begin()+rotated+1);
	print(nums);
	for(int i=0;i<temp.size();i++){
		nums.push_back(temp[i]);
		
	}
	print(nums);
}
	ans=binary_search(nums.begin(),nums.end(),target);
	return ans;
}

int main(){
	vector<int> v{1,3};
	cout<<search(v,1)<<"\n";
	return 0;
}