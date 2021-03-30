// g++ maxProductSub.cpp -o maxProductSub, //modified kadane
//https://leetcode.com/problems/maximum-product-subarray/
#include <vector>
#include <iostream>

using namespace std;

int maxProduct(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    int max_till=1;
    int min_till=1;
    int overall_max=-999999;
    int temp;
    for(int i=left; i<=right; i++){

    	if(nums[i]>0){
    		//update max
    		max_till = max_till*nums[i];
    		min_till = min(1, min_till*nums[i]);
    		cout<<"num: "<<nums[i]<<" min_till: "<<min_till<<" max_till: "<<max_till<<"\n";

    	}

    	else if(nums[i]==0){
    		min_till=1;
    		max_till=0;

    		cout<<"elem 0 min_till: "<<min_till<<" max_till: "<<max_till<<"\n";
    	}

    	else if(nums[i]<0){
    		temp = max_till;
    		max_till = min_till * nums[i];
    		min_till = temp * nums[i];
    		cout<<"num: "<<nums[i]<<" min_till: "<<min_till<<" max_till: "<<max_till<<"\n";
    	}

    	overall_max=max(overall_max, max_till);

    	if(max_till<=0){
    		max_till=1;
    	}
    	cout<<"overall_max: "<<overall_max<<" max_till: "<<max_till<<"\n"
    }
    
    return overall_max;
}

int main(){
	vector<int> v{-1,-2,-3,0};
	cout<<maxProduct(v)<<"\n";
	return 0;
}