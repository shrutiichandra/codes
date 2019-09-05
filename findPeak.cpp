// g++ findPeak.cpp -o findPeak
//O(n)
#include <vector>
#include <iostream>
#include <stack>
#include "common_utils.h"
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len=nums.size();
        int idx=0;
        // nums.resize(len+2);
        // printVector(nums);
        int prev,next;
        for(int i=0; i<len;i++){
        	prev=next=-9999999;
        	if(i!=0){
        		prev=nums[i-1];
        	}
        	else if(i!=len-1){
        	 	next=nums[i+1];
        	 }
        	
        	if(nums[i]>prev && nums[i]>next){
        		idx=i;
        	}
        }
        return idx;
    }
};

int main(){
	vector<int>v{1,2,1,3,5,6,4};
	printVector(v);
	Solution s;
	int ans;
	ans=s.findPeakElement(v);
	cout<<"peak element index: "<<ans<<"\n";
	return 0;

}