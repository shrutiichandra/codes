//g++ -std=c++11 threesum.cpp -o threesum

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSumClosest(vector<int>& nums, int target) {
	int sum;
	set<vector<int>> ans;

	sort(nums.begin(),nums.end());

	int left;
	int right;
	
	for(int i=0;i<nums.size()-3;i++){
		// cout<<"i: "<<i<<", ";
		for(int j=i+1;j<nums.size()-2;j++){
			// cout<<"i: "<<i<<", j: "<<j<<"\n";
			left=j+1;
			right=nums.size()-1;
			// cout<<"nums["<<i<<"]: "<<nums[i]<<", ";
			while(left<right){
				vector <int> temp;
				sum=nums[i]+nums[left]+nums[right]+nums[j];
								
				// cout<<"sum: "<<sum<<"\n";
				if(sum==target){
				// cout<<"nums["<<i<<"]: "<<nums[i]<<", nums["<<left<<"]: "<<nums[left]<<", nums["<<right<<"]: "<<nums[right]<<", nums["<<j<<"]: "<<nums[j]<<"\n";					

					temp.push_back(nums[i]);
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);
					temp.push_back(nums[j]);

					ans.insert(temp);
					left++;
					right--;
	
				}
				else if(sum<target)
					left++;
				else	
					right--;
			}
		}
	}


	return vector<vector<int>>{ans.begin(),ans.end()};
}
int main(){
	vector<int> v{-3,-2,-1,0,0,1,2,3};
	int t=0;
	threeSumClosest(v,t);

	return 0;
}
 
