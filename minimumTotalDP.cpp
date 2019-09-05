// g++ minimumTotalDP.cpp -o minimumTotalDP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int minimumTotal(vector<vector<int>>& triangle) {
	int ans=0;
	int rows=triangle.size();
	int minimum_below;

	//start from second last row
	for(int curr_row=rows-2; curr_row>=0; curr_row--){
		for(int i=0; i<=curr_row; i++){//elem in each row
			minimum_below=min(triangle[curr_row+1][i], triangle[curr_row+1][i+1]);
			triangle[curr_row][i]+=minimum_below;
		}
	}
	ans=triangle[0][0];
	return ans;
}

int main(){
	vector<vector <int>> t{{-7},{-2,1},{-5,-5,9},{-4,-5,4,4},{-6,-6,2,-1,-5},{3,7,8,-3,7,-9},{-9,-1,-9,6,9,0,7},{-7,0,-6,-8,7,1,-4,9},{-3,2,-6,-9,-7,-6,-9,4,0},{-8,-6,-3,-9,-2,-6,7,-5,0,7},{-9,-1,-2,4,-2,4,4,-1,2,-5,5},{1,1,-6,1,-2,-4,4,-2,6,-6,0,6},{-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1}};
	cout<<"given triangle: \n";
	for(auto i:t){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	int ans;
	ans=minimumTotal(t);

	cout<<"minimumTotal in this triangle is: "<<ans<<"\n";
	return 0;
}