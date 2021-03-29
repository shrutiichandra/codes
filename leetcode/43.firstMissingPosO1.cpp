//g++ firstMissingPos.cpp -o firstMissingPos
// https://leetcode.com/problems/first-missing-positive/
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
int separate(vector<int>& n){
	int non_positive_index=0;
	for(int i=0;i<n.size();i++){
		if(n[i]<=0){
			swap(n[i],n[non_positive_index]);
			non_positive_index++;
		}
	}
	return non_positive_index;
}
void print(vector<int>& n){
	for(auto i: n){
		cout<<i<<" ";
	}
	cout<<".\n";
}
int firstMissingPositiveHelper(vector<int>& n){
	cout<<"in helper: n.size() "<<n.size()<<". ";
	print(n);
	int elem;
	for(int i=0;i<n.size();i++){
		elem=abs(n[i]);
		cout<<"elem: "<<elem<<" elem-1: "<<elem-1<<"\n";
		if((elem - 1)<n.size() && n[elem-1]>0){
			cout<<"n[elem-1]: "<<-n[elem-1]<<"\n";
			n[elem-1]=-n[elem-1];
		}
	}
	cout<<"after for: ";
	print(n);

	//return first index where val is positive
	for(int i=0;i<n.size();i++){
		if(n[i]>0)
			return i+1;
	}
	return n.size()+1;
}
int firstMissingPositive(vector<int>& nums) {
	//separate positive and non positive
	int partition=separate(nums);
	print(nums);
	vector<int> partitioned_num{nums.begin()+partition,nums.end()};
	int missing = firstMissingPositiveHelper(partitioned_num);
	return missing;
}

int main(){
	vector<int> n{1,-5,9,0,-8,5,-2};
	cout<<firstMissingPositive(n)<<"\n";
	return 0;

}