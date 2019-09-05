//g++ subsets_bitMa.cpp -o  subsets_bitMa
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> subsets(vector<int>& nums) {
	vector <vector <int>> v;

	int len=nums.size();

	int num_sub=pow(2,len);

	for(int k=0; k<num_sub; k++){
		vector <int> temp;
		for(int i=0;i<len;i++){
			if(k&(1<<i)){
				temp.push_back(nums[i]);
			}

		}
		v.push_back(temp);

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