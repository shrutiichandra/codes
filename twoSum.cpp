//g++ twoSum.cpp -o twoSum
#include <vector>
#include <iostream>
#include "common_utils.h"
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        unordered_map <int,int> table;
        int diff;
        for(int i=0;i<nums.size();i++){
            diff=target-nums[i];
            
            if(table.find(diff)!=table.end()){
                //found , return ans
               // cout<<nums[i]<<" "<<diff;
                 ans.push_back(table[diff]);
                ans.push_back(i);
               
                return ans;
            }
            table[nums[i]]=i; //{nums[i],i}
        }
        return ans;
    }
};

int main(){
    
    vector <int> v{1,2,3,0};
    cout<<"array: ";
    printVector(v);
    int target=5;
    cout<<"target: "<<target<<"\n";
    vector<int> ans;
    Solution s;
    ans=s.twoSum(v,target);
    cout<<"indices: ";
    printVector(ans);


    return 0;
}