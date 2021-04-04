//g++ subsets.cpp -o  subsets
//https://leetcode.com/problems/subsets/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void combineHelper(vector <vector <int> >& res, vector<int>& nums, int k, vector <int>& temp, int start,int end){
	cout<<"start: "<<start<<"\n";
	if(temp.size()==k){
		cout<<"done\n";
		res.push_back(temp);
		return;

	}

	for(int i=start; i<=end; i++){
		// cout<<"i: "<<i<<"\n";
		temp.push_back(nums[i]);
		combineHelper(res,nums,k,temp,i+1,end);
		temp.pop_back();
	}
	
}
void combine(vector<vector<int>>& res, vector<int>& nums, int k) {
	vector <int> temp;	
	int start=0;
	int end=nums.size()-1;
	combineHelper(res,nums,k,temp,start,end);

}

vector<vector<int>> subsets(vector<int>& nums) {
	vector <vector <int>> v;

	int len=nums.size();

	int num_sub=pow(2,len);

	cout<<"num_sub: "<<num_sub<<"\n";
	v.push_back(nums);
	vector <int> temp;
	v.push_back(temp);

	for(int k=1; k<len; k++){
		combine(v,nums,k);
	}
	return v;        
}

int main(){
	vector <vector <int>> m;
	vector <int> nums{1,2,2};
	m=subsets(nums);


	for(auto i:m){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	return 0;
}