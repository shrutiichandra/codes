//DP sol
//https://leetcode.com/problems/unique-paths-ii/
//g++ uniquePathsObDP.cpp -o uniquePathsObDP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int uniquePathsWithObstacles(vector<vector <int> >& obstacleGrid) {
	int rows=obstacleGrid.size();
	cout<<"rows: "<<rows<<"\n";
	
	int cols=obstacleGrid[0].size();
	cout<<"cols: "<<cols<<"\n";
	vector <vector <int> >count (rows, vector <int> (cols, 0)) ;
	vector<int>::iterator it;
	// cout<<"vector count\n";
	if(obstacleGrid[0][0]==1){
		return 0;
	}
	else {
		count[0][0]=1;
	}
	bool found1=false;
	for(int r=1;r<rows;r++){

		if(obstacleGrid[r][0]==0){
			if(obstacleGrid[r-1][0]!=1 && !found1){

				count[r][0]=1;
				cout<<"count["<<r<<"][0]: "<<count[r][0]<<"\n";

			}
			else{
				//if a previous 1 is found
				cout<<"in else col first\n";
				cout<<"prev row count: "<<count[r-1][0]<<"\n";
				count[r][0]=count[r-1][0];
				cout<<"count["<<r<<"][0]: "<<count[r][0]<<"\n";
				found1=true;
			}

		}

	}
	found1=false;
	for(int c=1;c<cols;c++){
		// cout<<"c: "<<c<<"\n";
		if(obstacleGrid[0][c]==0){
			if(obstacleGrid[0][c-1]!=1 && !found1){
				count[0][c]=1;
			}
			else{
				count[0][c]=count[0][c-1];
				found1=true;
			}
		}
	}
	cout<<"here\n";
	for(int i=1;i<rows;i++){
		for(int j=1;j<cols;j++){
			// cout<<"i: "<<i<<" j: "<<j<<"\n";
			if(obstacleGrid[i][j]==0){
				if(obstacleGrid[i-1][j]==1 && obstacleGrid[i][j-1]!=1){
					// cout<<"left is 1\n";
					count[i][j]=count[i][j-1];
				}
				else if(obstacleGrid[i-1][j]!=1 && obstacleGrid[i][j-1]==1){
					// cout<<"up is 1\n";
					count[i][j]=count[i-1][j];
				}
				else
					count[i][j]=count[i-1][j]+count[i][j-1];
			}
		}
	}
	for(auto i:count){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	return count[rows-1][cols-1];
}
int main(){
	vector <vector <int> >v={{0,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	cout<<uniquePathsWithObstacles(v)<<"\n";
	return 0;
}