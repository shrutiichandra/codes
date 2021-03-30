// g++ minrotated.cpp -o minrotated
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
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
 int findMin(vector<int>& nums) {
	int ans=0;
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
	ans=nums[0];
	return ans;
}

int main(){
	vector<int> v{1,3};
	cout<<findMin(v)<<"\n";
	return 0;
}