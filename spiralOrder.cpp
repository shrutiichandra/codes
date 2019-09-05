//g++ spiralOrder.cpp -o spiralOrder
#include <vector>
#include <iostream>
using namespace std;
void print(vector<int>& a){
	for(auto i:a){
		cout<<i<<" ";
	}
	cout<<"\n";
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {

	vector<int> arr;

	int rows=matrix.size();
	cout<<"rows: "<<rows<<", ";
	int cols=matrix[0].size();
	cout<<"cols: "<<cols<<"\n";
	string dir="left";
	int top=0;
	int left=0;
	int right=cols-1;
	int bottom=rows-1;
	
	while(top<=bottom && left<=right){
		
		if(dir=="left"){
			//first row
			for(int i=top; i<=right; i++){
				// cout<<"top: "<<top<<" i: "<<i<<" at matrix "<<matrix[top][i]<<"\n";
				arr.push_back(matrix[top][i]);
			}
			++top; 
			//move down
			dir="down";
		}


		else if(dir=="down"){
			//last col
			for(int i=top; i<=bottom; i++ ){
				arr.push_back(matrix[i][right]);
			}
			--right;
			//move right
			dir="right";
		}


		else if(dir=="right"){
			//last row
			for(int i=right; i>=left;i--){
				// cout<<"bottom: "<<bottom<<" i: "<<i<<" at matrix "<<matrix[bottom][i]<<"\n";
				arr.push_back(matrix[bottom][i]);
			}
			--bottom;
			//move up
			dir="up";
		}

		else if(dir=="up"){
			//first col
			for(int i=bottom; i>=top;i--){
				arr.push_back(matrix[i][left]);
			}
			++left;	
			//move left
			dir="left";
		}

	}


	return arr;
        
}

int main(){
	vector<vector<int>>m{{1,2,3,4},
				 {5,6,7,8},
				 {9,10,11,12}
				};
	vector <int> a;
	a=spiralOrder(m);
	print(a);
	return 0;
}