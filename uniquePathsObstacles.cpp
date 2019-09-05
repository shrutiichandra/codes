//expo
//g++ uniquePathsObstacles.cpp -o uniquePathsObstacles
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& mat,int r,int c,int rows,int cols,int& ans){
	
if(mat[r][c]==0){
	if(r==rows-1 && c==cols-1){
		ans++;
		// cout<<"ANS; "<<ans<<"\n";
		return;

	}

(r+1<rows && c<=cols && mat[r+1][c]!=1){
		dfs(mat,r+1,c,rows,cols,ans);
	}
	if(r<rows && c+1<=cols && mat[r][c+1]!=1){
		dfs(mat,r,c+1,rows,cols,ans);
	}
}
	// vis[r][c]=0;
}
int uniquePathsWithObstacles(vector<vector <int> >& obstacleGrid) {
	int rows=obstacleGrid.size();
	int cols=obstacleGrid[0].size();

	int ans=0;

	dfs(obstacleGrid,0,0,rows,cols,ans);


	return ans;
}

int main(){
	vector <vector <int> >board={{1}};
	cout<<uniquePathsWithObstacles(board)<<"\n";
	return 0;
}