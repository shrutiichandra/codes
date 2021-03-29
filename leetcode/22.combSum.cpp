//https://leetcode.com/problems/combination-sum/		
#include <vector> 
#include <iostream>
#include <algorithm>

using namespace std;
void combinationSumHelper(vector<vector<int>>& result,vector<int>& one_sol,vector<int>& candidates, int target, int index) {
	if(target<0){
		return;
	}

	if(target==0){
		result.push_back(one_sol);
		return;
	}

	while(target-candidates[index]>=0 && index<candidates.size()){

		one_sol.push_back(candidates[index]);
		int s = target-candidates[index];
		combinationSumHelper(result,one_sol,candidates,s,index);
		index++;
		one_sol.pop_back();

	}

}	
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	// sort(candidates.begin(),candidates.end());

	vector<int> temp_sol;
	vector<vector<int>> ans;

	combinationSumHelper(ans,temp_sol,candidates,target,0);
	return ans;
}
int main(){
	vector<int> v{2,4,6,8};
	vector<vector<int>> ans;
	ans=combinationSum(v,8);
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