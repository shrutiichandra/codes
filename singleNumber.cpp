#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int x,sum;
        for(int i=0; i<2; i++){
            sum=0;
            x=(1<<i);
            cout<<"i: "<<i<<" x: "<<x<<" ans: "<<ans<<"\n";

            for(int j=0; j<n; j++){
                cout<<"j: "<<j<<" nums[j]: "<<nums[j]<<" nums[j]&x: "<<(nums[j]&x)<<"\n";
                if(nums[j]&x)
                    sum++;
            }
            if(sum%3){
                cout<<"ans: ";
                ans=ans | x;
                cout<<ans<<"\n";
            }
        }
        return ans;
    }
};

int main(){
    vector <int> n{2,2,3,2};
    // vector <int> n{0,1,0,1,0,1,99};
    cout<<"vector: ";
    for(auto i:n) cout<<i<<" ";
    cout<<"\n";
    Solution obj;
    cout<<"singleNumber is: "<<obj.singleNumber(n)<<"\n";

    return 0;
}