//g++ searchRotatedIndex.cpp -o searchRotatedIndex

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int binarySearch(vector<int>& nums,int l,int h,int k){
	cout<<"l: "<<l<<" h: "<<h<<"\n";
	int index=-1;

	if(l<=h){
		int mid = (l+h)/2;
		cout<<"mid: "<<mid<<"\n";

		if(nums[mid]==k){
			index=mid;
			cout<<"returning index: "<<index<<"\n";
			return index;
		}

		else if(nums[mid]>=k){
			index=binarySearch(nums,l,mid-1,k);
			cout<<"returning l: "<<l<<", mid-1: "<<mid-1<<" index: "<<index<<"\n";
			return index;
		}
		else if(nums[mid]<k){

			index=binarySearch(nums,mid+1,h,k);
			cout<<"returning mid+1: "<<mid+1<<", h: "<<h<<" index: "<<index<<"\n";
			

			return index;
		}
	}
	else
	return index;


}
int search(vector<int>& nums, int target) {
	int ans=-1;
	int size=nums.size();
	int rotated=-1;//pivot

	int low=0;
	int high=size-1;

	for(int i=0;i<size-1;i++){
		if(nums[i]>nums[i+1]){
			rotated=i;
			break;
		}
	}

	if(rotated==-1){
		cout<<"low: "<<low<<" high: "<<high<<"\n";
		ans=binarySearch(nums,low,high,target);
		return ans;
	}

	if(nums[rotated]==target){
		return rotated;
	}

	else if(nums[0]<=target){
		cout<<"low: "<<low<<" rotated-1: "<<rotated-1<<"\n";
		ans=binarySearch(nums,low,rotated-1,target);
		cout<<"returning "<<"low: "<<low<<" rotated-1: "<<rotated-1<<" ans: "<<ans<<"\n";
		return ans;
	}
	else if(nums[0]>target){
		cout<<"rotated+1: "<<rotated+1<<" high: "<<high<<"\n";
		ans=binarySearch(nums,rotated+1,high,target);
		cout<<"returning "<<"rotated+1: "<<rotated+1<<" high: "<<high<<" ans: "<<ans<<"\n";

		return ans;
	}
	
	return ans;
}

int main(){
	vector<int> v{4,5,6,7,0,1,2};
	cout<<search(v,0)<<"\n";
	return 0;
}