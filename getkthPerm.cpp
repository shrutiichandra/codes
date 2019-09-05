#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string>
#include <sstream>
using namespace std;
string convert(vector<int>& v){
	ostringstream st;
	if(!v.empty()){
		copy(v.begin(),v.end(), ostream_iterator<int>(st));

	}
	return st.str();
}
vector<int> nextPermutation(vector<int>& nums) {
	// cout<<"--in nextPermutation--- ";
	// for(auto i:nums){
	// 	cout<<i<<" ";
	// }
	// cout<<"\n";
	vector<int> ans;
	int n_len=nums.size();
	int next_larger;
	int index;
	int flag=0;
	for(int i=n_len-1;i>=1&&!flag;i--){
		//scan from right
		// cout<<i<<", "<<nums[i]<<", "<<nums[i-1]<<"\n";
		if(nums[i] > nums[i-1]){
			index=i;
			//find just larger number of nums[i-1] in i to n_len-1
			flag=1;
			int diff;
			int close=INT_MAX;
			for(int j=i;j<n_len;j++){
				diff=nums[j]-nums[i-1];
				// cout<<j<<", diff: "<<diff<<"\n";
				if(diff<=close && diff>0 ){
					// cout<<"updating close\n";
					close=diff;
					next_larger=j;
				}
			}

			// cout<<"swap: "<<i-1<<"th number: "<<nums[i-1]<<", "<<next_larger<<"th number: "<<nums[next_larger]<<"\n";
			swap(nums[index-1],nums[next_larger]);
			}
	}
	reverse(nums.begin()+index,nums.end());
	ans=nums;
	return ans;

}
vector<int> permute(vector<int>& v,int k){

	vector<int> temp(v.begin(), v.end());

	for(int i=2;i<=k;i++){
		vector<int> temp_;
		temp_=nextPermutation(temp);
		temp=temp_;
	}



	return temp;

}

string getPermutation(int n, int k) {
	vector<int> v;
	string s;
	for(int i=1;i<=n;i++){
		v.push_back(i);
	}        
	if(k==1){
		s=convert(v);
		return s;
	}
	v=permute(v,k);
	s=convert(v);
	return s;


}

int main(){

	cout<<getPermutation(3,3)<<"\n";
	return 0;
}