#include <vector> 
#include <set>
#include <iostream>
#include <algorithm>
//may have duplicates
using namespace std;
void removeDuplicates(vector<int>& nums) {
    int index=0;
    int j=1;
    while(1){
        if(nums.begin()+j == nums.end()){
            break;
        }
        if(nums[index]==nums[j]){
            nums.erase(nums.begin()+j);
        }
        else{
            index++;
            j++;
        }
    }
    
}
void combinationSumHelper2(set<vector<int>>& result,vector<int>& one_sol,vector<int>& candidates, int target, int index) {
	if(target<0){
		return;
	}

	if(target==0){
		result.insert(one_sol);
		return;
	}

	while(target-candidates[index]>=0 && index<candidates.size()){

		one_sol.push_back(candidates[index]);
		int s = target-candidates[index];
		index++;
		combinationSumHelper2(result,one_sol,candidates,s,index);
		
		one_sol.pop_back();

	}

}	
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	 sort(candidates.begin(),candidates.end());

	vector<int> temp_sol;
	set<vector<int>> ans;
	vector<vector<int>> ans2;
	combinationSumHelper2(ans,temp_sol,candidates,target,0);
	return vector<vector<int>>{ans.begin(),ans.end()};	
}
int main(){	
	vector<int> v{10,1,2,7,6,1,5};
	vector<vector<int>> ans;
	ans=combinationSum2(v,8);
	for(int i=0;i<ans.size();i++){
		cout<<"( ";
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<" ) ";
	}	
	cout<<"\n";
	return 0;
}