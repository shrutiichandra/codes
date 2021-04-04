//g++ removeDup2.cpp -o removeDup2
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// slow, naive
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int index=0;
    int j=2;
    int count=1;
    int size=nums.size();

    if(size==0){
        return 0;
    }

    while(1){
        if(j >= size ){
            break;
        }
        if(nums.begin()+j == nums.end()){
            break;
        }
        cout<<"nums["<<index<<"] :"<<nums[index]<<" nums["<<j<<"]: "<<nums[j]<<"\n";
        if(nums[index]==nums[j]){
 
            nums.erase(nums.begin()+j);
            // cout<<"count: "<<nums[index]<<": "<<count<<"\n";
            // index++;
            // j++;
        }
        else{
            index++;
            j++;
            // count=1;
        }

    //     if(count>2){
    //         cout<<"erase j: "<<j<<" j-1:" <<j-1<<"\n";
    //         nums.erase(nums.begin()+j-1);
    //         // count=0;
    //     }
    }
    for(auto i:nums)
        cout<<i<<" ";
    cout<<"\n";
    return nums.size();
}

int main(){
    vector <int> n{1};

    cout<<removeDuplicates(n)<<"\n";
    return 0;
}