//g++ nextPerm.cpp -o nextPerm
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;
void nextPermutation(vector<int>& nums) {
	int n_len=nums.size();
	int next_larger;
	int index;
	int flag=0;
	//iterate right to left
	for(int i=n_len-1;i>=1&&!flag;i--){
		cout<<"i: "<<i<<", num[i] "<<nums[i]<<", num[i-1] "<<nums[i-1]<<"\n";
		if(nums[i] > nums[i-1]){
			index=i;
			//find just larger number of nums[i-1] in i to n_len-1
			flag=1;
			int diff;
			int close=INT_MAX;
			for(int j=i;j<n_len;j++){
				diff=nums[j]-nums[i-1];
				cout<<"j: "<<j<<", diff: "<<diff<<"\n";
				if(diff<=close && diff>0 ){
					cout<<"updating close\n";
					close=diff;
					next_larger=j;
				}
			}

			cout<<"swap: "<<i-1<<"th number: "<<nums[i-1]<<", "<<next_larger<<"th number: "<<nums[next_larger]<<"\n";
			swap(nums[i-1],nums[next_larger]);
		}
	}
	reverse(nums.begin()+index,nums.end());


}
int main(){
	vector <int> n{2,3,1,3,3};
	nextPermutation(n);
	for(auto i: n)
		cout<<i<<" ";
	cout<<"\n";
	return 0;
}