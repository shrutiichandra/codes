//g++ sort02.cpp -o sort02
//dutch national flag
//https://leetcode.com/problems/sort-colors/
#include <vector>
#include <iostream>

using namespace std;

//one pass
void print(vector<int>& v){
	for(auto i:v){
		cout<<i<<" ";
	}
	cout<<"\n";\
}
void sortColors(vector<int>& nums) {
	int len=nums.size();

	int high=len-1;
	int low=0;
	int mid=0;

	while(mid<=high){
		if(nums[mid]==0){//red

			if(nums[mid]!=nums[low]){
				swap(nums[mid],nums[low]);
			}
			mid++;
			low++;
			
		}
		else if(nums[mid]==1){//white
			mid++;
		}
		else{//blue
			if(nums[mid]!=nums[high]){
				swap(nums[mid],nums[high]);
			}
			high--;

		}
	}

}

int main(){
	vector <int> v{2,0,2,1,1,0};
	print(v);
	sortColors(v);
	print(v);
	return 0;
}