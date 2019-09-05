//g++ subsetsDup.cpp -o  subsetsDup
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector <vector <int>> v;

	int len=nums.size();

	int num_sub=2<<len;

	for(int k=0; k<num_sub; k++){
		vector <int> temp;
		for(int i=0;i<len;i++){
			if(k&(1<<i)){
				temp.push_back(nums[i]);
			}

		}
		int f=0;
		sort(temp.begin(),temp.end());
		// search(v2.begin(), v2.end(), v1.begin(), v1.end());
		for(int i=0; i<v.size()&&!f; i++){
			// for(int j=0; j<v[i].size(); j++){
			
			if(v[i]==temp){
				f=1;
			}
		}
		if(f==0)
			v.push_back(temp);

	}
	return v;        
}

int main(){
	vector <vector <int>> m;
	vector <int> nums{4,4,4,1,4};
	m=subsetsWithDup(nums);


	for(auto i:m){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	return 0;
}