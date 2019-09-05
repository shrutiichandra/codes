//g++ canJumpMemo.cpp -o canJumpMemo
//TLE
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool canJumpHelper(vector<int>& n,int index,int des,vector<string>& index_type){
	cout<<"\n--- index: "<<index<<" index_type: "<<index_type[index]<<"----\n\n";
	if(index_type[index]!="unknown"){
		if(index_type[index]=="possible"){
			return true;
		}
		else if(index_type[index]=="not_possible"){
			return false;
		}
	}


	int jump_val=n[index];
	
	int jump=jump_val+index;
	
	int farthest_jump = min(jump,des);
	cout<<"farthest_jump: "<<farthest_jump<<"\n";
	for(int i=farthest_jump;i>=index+1;i--){
		cout<<"i: "<<i<<" index_type: "<<index_type[index]<<"\n";
		if(canJumpHelper(n,i,des,index_type)){
			index_type[index]="possible";
			return true;
		}
	}


	index_type[index]="not_possible";
	return false;

}
bool canJump(vector<int>& nums) {
	int last_index=nums.size()-1;
	vector<string> type;

	for(int i=0;i<nums.size();i++){

		type.push_back("unknown");
	}
	type[last_index]="possible";
	return canJumpHelper(nums,0,last_index,type);
}

int main(){

	vector <int> nums{2,3,0,1,4};
	cout<<canJump(nums)<<"\n";
	return 0;
}