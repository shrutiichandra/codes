// g++ minimumTotal.cpp -o minimumTotal
//TLE 42/43
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(vector<vector<int>>& mat,int r,int c,int rows,int ans,int& min){
	cout<<"ans: "<<ans<<" min: "<<min<<" ";
	cout<<"currently in row: "<<r<<" ";
	if(r==rows-1){
		//reached last row
		ans+=mat[r][c];
		// cout<<"last row, ans: "<<ans<<" ";
		if(ans<min){
			min=ans;
		}
		cout<<"min: "<<min<<", return\n";
		//return the final min sum

		return;

	}

	if(r+1<rows ){
		cout<<"go down, ";
		ans+=mat[r][c];
		// cout<<"ans: "<<ans<<"\n";
		// if(ans<min){
		// 	min=ans;
		// }
		// cout<<"min: "<<min<<"\n";
		dfs(mat,r+1,c,rows,ans,min);
		// cout<<"return from down ans: "<<ans<<" ";
	}
	if(r+1<rows ){
		cout<<"go right, \n";
		// ans+=mat[r][c];
		// cout<<"ans: "<<ans<<"\n";
		// if(ans<min){
		// 	min=ans;
		// }

		// cout<<"min: "<<min<<"\n";

		dfs(mat,r+1,c+1,rows,ans,min);
	}
	// vis[r][c]=0;
}

int minimumTotal(vector<vector<int>>& triangle) {
	int ans=0;
	int min=999999;

	// vector<int> r;

	int rows=triangle.size();

	// int sum=triangle[0][0];
	dfs(triangle,0,0,rows,ans,min);
	ans=min;
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