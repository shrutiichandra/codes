// g++ findPeakLogN.cpp -o findPeakLogN
//O(logN) https://leetcode.com/problems/find-peak-element/
#include <vector>
#include <iostream>
#include "common_utils.h"
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len=nums.size();
       
        // printVector(nums);
        int prev,next;
        int l=0;
        int r=len-1;

        while(l<r){
            int mid=(l+r)/2;

            if(nums[mid]<=nums[mid+1]){
                //rising side
                l=mid+1;
            }
            else{
                //falling side
                r=mid;
            }
        }
       
        return l;
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