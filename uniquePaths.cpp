//exponential
//g++ uniquePaths.cpp -o uniquePaths
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& mat,int r,int c,int rows,int cols,int& ans){
	
	if(r==rows-1 && c==cols-1){
		ans++;
		// cout<<"ANS; "<<ans<<"\n";
		return;

	}

	// vis[r][c]=1;

	if(r+1<rows && c<=cols ){
		dfs(mat,r+1,c,rows,cols,ans);
	}
	if(r<rows && c+1<=cols ){
		dfs(mat,r,c+1,rows,cols,ans);
	}
	// vis[r][c]=0;
}
int uniquePaths(int m, int n) {
	vector <vector <int> >board (m, vector <int> (n, 0)) ;
	int ans=0;

	dfs(board,0,0,m,n,ans);


	return ans;
}

int main(){
	cout<<uniquePaths(10,10)<<"\n";
	return 0;
}