//  https://leetcode.com/problems/jump-game/
#include <iostream>
#include <vector>

using namespace std;


bool canJump(vector<int>& nums) {
    int last_index=nums.size()-1; //the leftmostgood index
    cout<<"last_index: "<<last_index<<"\n";

    for(int i=last_index;i>=0;i--){
        cout<<"i: "<<i<<" nums[i]: "<<nums[i]<<"\n";
        if(i+nums[i]>=last_index){
            last_index=i;
            cout<<"\blastindex: "<<last_index<<"\n";
        }
        
    }
    if(last_index==0){ //0 should be leftmost good index
        return true;    
    }
    return false;
}    

int main(){
    vector <int> n{2,3,1,1,4};
    cout<<"vector: ";
    for(auto i:n){
        cout<<i<<" ";
    }

    canJump(n)? cout<<"true\n" : cout<<"false\n";
    return 0;
}