
//g++ minimSum.cpp -o minimSum
// https://leetcode.com/problems/minimum-path-sum/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int dfs(vector<vector<int>>& grid, int m,int n){

	vector <vector <int> > v(m+1, vector<int>(n+1,0));

	v[0][0]=grid[0][0];

	for(int i=1;i<=m;i++){
		v[i][0]=v[i-1][0]+grid[i][0];
	}

	for(int i=1;i<=n;i++){
		v[0][i]=v[0][i-1]+grid[0][i];
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			v[i][j]=min(v[i-1][j],v[i][j-1]) + grid[i][j];
		}
	}
	return v[m][n];

}

int minPathSum(vector<vector<int>>& grid) {
	
	int m=grid.size()-1;
	int n=grid[0].size()-1;
	
	return dfs(grid,m,n);
}

int main(){
	vector<vector<int>>v {{1,3,1},{1,5,1},{4,2,1}};

	cout<<minPathSum(v)<<"\n";
	return 0;
}