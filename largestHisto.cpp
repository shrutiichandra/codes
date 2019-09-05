//g++ largestHisto.cpp -o largestHisto
//tle
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int findMin(vector<int>& arr){
	for(auto i: arr){
		cout<<i<<" ";
	}
	cout<<" | ";
	sort(arr.begin(), arr.end());
	for(auto i: arr){
		cout<<i<<" ";
	}
	cout<<" | ";
	return arr[0];
}
int largestRectangleArea(vector<int>& heights) {
	int ans=-999999999;
	int len=heights.size();

	int area=0;
	int left=0;
	int right=left+1;

	for(int left=0; left<len; left++){
		for(int right=left; right<len;right++){
		
			// cout<<"left: "<<left<<" right "<<right<<" h[l]: "<<heights[left]<<" h[r] "<<heights[right]<<"\n";
			
			// int h=heights[left];
			//height; minimum from left to right
			vector<int> temp(heights.begin()+left,heights.begin()+right+1);
			int h=findMin(temp);
			cout<<"h: "<<h;
			int b=(right-left)+1;
			cout<<" b: "<<b<<" ";
			cout<<"ar: ";
			int area=b*h;
			cout<<area<<"\n";
			if(ans<area){
				ans=area;
			}
			
		}
	}
	if(ans<0)
		ans=0;

	return ans;
}


int main(){

	vector<int> h{0,9};
	cout<<largestRectangleArea(h)<<"\n";

	return 0;
}