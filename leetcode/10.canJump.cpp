//g++ canJump.cpp -o canJump
//TLE https://leetcode.com/problems/jump-game/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool canJumpHelper(vector<int>& n,int index,int des){

	if(index==des){
		cout<<"reached des\n";
		return true;
	}


	int jump_val=n[index];
	
	int jump=jump_val+index;
	
	int farthest_jump = min(jump,des);

	for(int i=farthest_jump;i>=index+1;i--){
		if(canJumpHelper(n,i,des)){
			
			return true;
		}
	}



	return false;

}
bool canJump(vector<int>& nums) {
	int last_index=nums.size()-1;
	return canJumpHelper(nums,0,last_index);
}

int main(){

	vector <int> nums{2,3,0,1,4};
	cout<<canJump(nums)<<"\n";
	return 0;
}