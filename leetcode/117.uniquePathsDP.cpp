//DP sol
//https://leetcode.com/problems/unique-paths/
//g++ uniquePathsDP.cpp -o uniquePathsDP
#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
	vector <vector <int> >count (m, vector <int> (n, 0)) ;
	
	for(int r=0;r<m;r++){
		count[r][0]=1;
	}

	for(int c=0;c<n;c++){
		count[0][c]=1;
	}

	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			count[i][j]=count[i-1][j]+count[i][j-1];
		}
	}

	return count[m-1][n-1];
}

int main(){
	cout<<uniquePaths(23,12)<<"\n";
	return 0;
}