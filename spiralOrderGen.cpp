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
vector<vector<int>> generateMatrix(int rows){
	vector<vector<int>> v(rows);
	for(int i=0;i<rows;i++){
		v[i]=vector<int>(3);
	}
	cout<<"rows: "<<rows<<", ";
	int cols=rows;
	cout<<"cols: "<<cols<<"\n";
	string dir="left";
	int top=0;
	int left=0;
	int right=cols-1;
	int bottom=rows-1;
	int count = 0;
	while(top<=bottom && left<=right){
		
		if(dir=="left"){
			//first row
			for(int i=top; i<=right; i++){
				cout<<"top: "<<top<<" i: "<<i<<"\n";
				count++;
				v[top][i] = count;
			}
			++top; 
			//move down
			dir="down";
		}


		else if(dir=="down"){
			//last col
			for(int i=top; i<=bottom; i++ ){
				count++;
				v[i][right]=count;
			}
			--right;
			//move right
			dir="right";
		}


		else if(dir=="right"){
			//last row
			for(int i=right; i>=left;i--){
				cout<<"bottom: "<<bottom<<" i: "<<i<<" right\n";
				count++;
				v[bottom][i]=count;
			}
			--bottom;
			//move up
			dir="up";
		}

		else if(dir=="up"){
			//first col
			for(int i=bottom; i>=top;i--){
				count++;
				v[i][left]=count;
			}
			++left;	
			//move left
			dir="left";
		}

	}


	return v;
        
}

int main(){
	vector<vector<int>>m;
	// vector <int> a;
	m=generateMatrix(3);
	for(auto i: m){
		for(auto j: i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	// print(a);
	return 0;
}