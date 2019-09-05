//g++ firstMissingPos.cpp -o firstMissingPos
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
	int n_size=nums.size();
	
	int target,diff_t;
	int missing;
	int l=0,r=0;
	int flag=1;
	// unordered_map<int,int> numbers;
	sort(nums.begin(), nums.end());

	//find kth smallest in pairs
	for(int i=0;i<n_size;i++){
		cout<<"i: "<<i<<", ";
		if(nums[i]<=0){
			continue;
		}
		else{
			if(nums[i]!=1 && flag){
				missing =1;
				return missing;
			}
			else if(nums[i]==1){
				cout<<"minimum is not 1\n";
				flag=0; //min is not 1
				cout<<nums[i+1]<<", "<<nums[i]<<"\n";

				if(i!=n_size-1 && (nums[i+1]-nums[i]>1)){
					//they are not continuous
					missing=nums[i]+1;
					return missing;
				}
				
				else{
					cout<<"else do nothing, move ahead\n";
					continue;
				}
			
			}
			else if(nums[i]!=1 && !flag){
				cout<<nums[i+1]<<", "<<nums[i]<<"\n";

				if(i!=n_size-1 && (nums[i+1]-nums[i]>1)){
					//they are not continuous
					missing=nums[i]+1;
					return missing;
				}
				
				else{
					cout<<"else do nothing, move ahead\n";
					continue;
				}
			}

		}
	}
	missing = nums[n_size-1]+1;

	return missing;

}

int main(){
	vector<int> n{3,4,-1,1};
	cout<<firstMissingPositive(n)<<"\n";
	return 0;

}