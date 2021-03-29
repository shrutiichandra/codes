//g++ canJump2.cpp -o canJump2
//TLE https://leetcode.com/problems/jump-game/
#include <vector>
// #include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;

int jump(vector<int>& nums) {
 	int n=nums.size();
 	vector<int> jumps(n,0);

 	if(n==0){
 		return INT_MAX;
 	}
 	
 	//min jumps reqd to reach i from 0
 	for(int idx=1; idx<n;idx++){
 		cout<<"\n\nidx: "<<idx<<", ";
 		jumps[idx]=INT_MAX;
 		cout<<"set jumps["<<idx<<"]: "<<jumps[idx]<<"\n";
 		for(int j=0;j<idx;j++){
 			cout<<"\nj: "<<j<<", ";
 			int in_nums=nums[j];
 			cout<<"nums["<<j<<"]: "<<in_nums<<", ";
    		int jump=in_nums+j;
    		cout<<"des: "<<jump<<"\n";
    		cout<<"b4 if] idx: "<<idx<<" jump: "<<jump<<" jumps["<<j<<"]: "<<jumps[j]<<"\n";
    		if(idx<=jump && jumps[j]!=INT_MAX){
    			cout<<"in if] ";
    			cout<<"jumps["<<idx<<"]: ";
    			jumps[idx]=min(jumps[idx],jumps[j]+1);
    			cout<<jumps[idx]<<"\n";
    			break;
    		}
 		}
 	}
 	return jumps[n-1];
}

int main(){

	vector <int> nums{2,3,1,1,4};
	cout<<jump(nums)<<"\n";
	return 0;
}