//g++ twoSum2.cpp -o twoSum2
#include <vector>
#include <iostream>
#include "common_utils.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size();
        int beg=0, end=len-1;
        vector <int> v;
        int sum;
        while(beg < end){
        	sum = numbers[beg] + numbers[end];

        	if(sum==target){
        		v.push_back(beg+1);
        		v.push_back(end+1);
        		return v;
        	}

        	else if(sum<target){
        		beg++;
        	}

        	else{
        		end--;
        	}
        }


        return v;

    }
};

int main(){
    vector <int> v{2,7,11,15};
    cout<<"array: ";
    printVector(v);
    int target=9;
    cout<<"target: "<<target<<"\n";
    vector<int> ans;
    Solution s;
    ans=s.twoSum(v,target);
    cout<<"indices: ";
    printVector(ans);


    return 0;

}