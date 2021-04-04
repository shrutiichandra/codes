//g++ removeDuplicates.cpp -o removeDuplicates
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int index=0;
    int j=1;
    while(1){
        if(nums.begin()+j == nums.end()){
            break;
        }
        cout<<"nums["<<index<<"] :"<<nums[index]<<" nums["<<j<<"]: "<<nums[j]<<"\n";
        if(nums[index]==nums[j]){
            nums.erase(nums.begin()+j);
        }
        else{
            index++;
            j++;
        }
    }
    cout<<"arr: \n";
    for(auto i:nums)
        cout<<i<<" ";
    cout<<"\n";
    return nums.size();
}

int main(){
    vector <int> n{1,1,2};

    cout<<"size after removeDuplicates: "<<removeDuplicates(n)<<"\n";
    return 0;
}