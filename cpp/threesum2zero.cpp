//g++ -std=c++11 threesum.cpp -o threesum

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSumClosest(vector<int>& nums) {
	int sum;
	set<vector<int>> ans;

	sort(nums.begin(),nums.end());

	int left;
	int right;
	
	for(int i=0;i<nums.size()-3;i++){
		// cout<<"i: "<<i<<", ";
			// cout<<"i: "<<i<<", j: "<<j<<"\n";
			left=i+1;
			right=nums.size()-1;
			// cout<<"nums["<<i<<"]: "<<nums[i]<<", ";
			while(left<right){
				vector <int> temp;
				sum=nums[i]+nums[left]+nums[right];
								
				// cout<<"sum: "<<sum<<"\n";
				if(sum==0){
				// cout<<"nums["<<i<<"]: "<<nums[i]<<", nums["<<left<<"]: "<<nums[left]<<", nums["<<right<<"]: "<<nums[right]<<", nums["<<j<<"]: "<<nums[j]<<"\n";					

					temp.push_back(nums[i]);
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);

					ans.insert(temp);
					left++;
					right--;
	
				}
				else if(sum<0)
					left++;
				else	
					right--;
			
		}
	}


	return vector<vector<int>>{ans.begin(),ans.end()};
}
int main(){
	vector<int> v{-3,-2,-1,0,0,1,2,3};
	int t=0;
	threeSum(v);

	return 0;
}
 
