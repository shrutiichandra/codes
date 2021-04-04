//g++ rotateimage.cpp -o rotateimage
// https://leetcode.com/problems/rotate-image/
//90deg clockwise
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<vector<int>> v){
	for(auto i: v){
		for(auto j: i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}
void rotate(vector<vector<int>>& matrix) {
	int size=matrix.size();
	int cycles=size/2;

	for(int i=0; i<cycles; i++){
		for(int j=i; j<(size-i-1); j++){
			cout<<"-----"<<j<<"th iteration------\n";
			cout<<"matrix["<<i<<"]["<<j<<"]: "<<matrix[i][j]<<"\n";
			int temp = matrix[i][j];
			
			cout<<"at "<<i<<","<<j<<" ";
			cout<<"matrix["<<size-j-1<<"]["<<i<<"]: "<<matrix[size-j-1][i]<<"\n";
			matrix[i][j]=matrix[size - j - 1][i];

			cout<<"at "<<size - j - 1<<","<<i<<" ";
			cout<<"matrix["<<size - i - 1<<"]["<<size - j - 1<<"]: "<<matrix[size-i-1][size - j - 1]<<"\n";
			matrix[size - j - 1][i] = matrix[size - i - 1][size - j - 1];

			cout<<"at "<<size - i - 1<<","<<size - j - 1<<" ";
			cout<<"matrix["<<j<<"]["<<size - i - 1<<"]: "<<matrix[j][size - i - 1]<<"\n";
			matrix[size - i - 1][size - j - 1] = matrix[j][size - i - 1];

			cout<<"at "<<j<<","<<size - i - 1<<" ";
			cout<<"temp: "<<temp<<"\n";
			matrix[j][size - i - 1]=temp;
		}	
	}
}

int main(){
	vector<vector<int>> v{{1,2,3},
				  {4,5,6},
				  {7,8,9}
				};
	// vector<vector<int>> v{{5,1,9,11},
	// 			  {2,4,8,10},
	// 			  {13,3,6,7},
	// 			  {15,14,12,16}
	// 			};
	print(v);
	cout<<"-------\n";
	rotate(v);
	print(v);
	return 0;
}