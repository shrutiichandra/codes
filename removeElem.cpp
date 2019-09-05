#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int index=0;
    if(nums.size()==0)
        return;

    while(1){
        if(nums.begin()+index == nums.end()){
            break;
        }
       
        if(nums[index]==val){
            nums.erase(nums.begin()+index);
        }
        else{
            index++;
            
        }
    }
    for(auto i:nums)
        cout<<i<<" ";
    cout<<"\n";
    return nums.size();
}

int main(){
    vector <int> n{0,1,2,2,3,0,4,2};

    cout<<removeElement(n,2)<<"\n";
    return 0;
}