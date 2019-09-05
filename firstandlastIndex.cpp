#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> indices;

	vector<int> :: iterator it,iter;
	int start = -1;
	int end = -1;
	it = find(nums.begin(),nums.end(),target);

	if(it!=nums.end()){
		start = it - nums.begin();
		
		for(iter = it+1; iter != nums.end(); ){
			if(target == *iter){
				iter++;
			}
			else{
				break;
			}
		}

		end = iter - nums.begin() - 1;

	}

	indices.push_back(start);
	indices.push_back(end);
	

	return indices;

}


int main(){

	vector <int> n{5,7,7,8,8,10};
	vector <int> ans;

	ans=searchRange(n,8);
	for(auto i:ans)
		cout<<i<<" ";
	cout<<"\n";
}