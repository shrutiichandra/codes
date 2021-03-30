//https://leetcode.com/problems/maximum-subarray/
#include <vector>
#include <iostream>

using namespace std;
int maximum(int a,int b,int c){
	int d=max(a,b);
	return max(d,c);
}
int maxCrossing(vector<int>& nums, int l, int m, int r){
	cout<<"----maxCrossing--- \n";
	int sum=0;
	int left=-9999999,right=-9999999;
	int l_sum=0;
	//**tricky loop
	for(int i=m;i>=l;i){
		cout<<"i: "<<i<<" nums[i]: "<<nums[i]<<", ";
		l_sum+=nums[i];
		cout<<"l_sum: "<<l_sum<<"\n";
		if(l_sum>left){
			left=l_sum;
		}
	}

	int r_sum=0;
	for(int j=m+1;j<=r;j++){
		// cout<<"j: "<<j<<" nums[j]: "<<nums[j]<<", ";
		r_sum+=nums[j];
		// cout<<"r_sum: "<<r_sum<<"\n";
		if(r_sum>right){
			right=r_sum;
		}
	}
	cout<<"left "<<left<<" right "<<right;
	sum=left+right;
	cout<<" sum "<<sum<<"\n";
	return sum;
}
int maxSubArrayHelper(vector<int>& nums, int l, int r){
	cout<<"------maxSubArrayHelper: ";
	cout<<"l: "<<l<<" r: "<<r<<" ";
	if(l==r){
		cout<<"returning: "<<nums[l]<<"\n";
		return nums[l];
	}
	int mid=(l+r)/2;
	cout<<"mid: "<<mid<<"\n";
	// cout<<max(4,5)<<"\n";
	return maximum(maxSubArrayHelper(nums,l,mid),maxSubArrayHelper(nums,mid+1,r),maxCrossing(nums,l,mid,r));
}
int maxSubArray(vector<int>& nums) {
	int left=0;
	int right=nums.size()-1;
	
	return maxSubArrayHelper(nums, left, right);
}

int main(){
	vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
	cout<<maxSubArray(v)<<"\n";
	return 0;
}