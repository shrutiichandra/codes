// g++ validSudoku.cpp -o validSudoku
//https://leetcode.com/problems/valid-sudoku/
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
void initializeMap(unordered_map<char,int>& m){
	for(char c='0';c<='9';c++){
		m[c]=0;
	}	
	m['.']=0;
}

bool isValidSudoku(vector<vector<char>>& board) {
	unordered_map<char,int> sudoku_digits;

	//check in each row
	for(int row=0;row<9;row++){
		initializeMap(sudoku_digits);
		
		for(int col=0;col<9;col++){
			sudoku_digits[board[row][col]]++;
		}

		for(auto i=sudoku_digits.begin();i!=sudoku_digits.end();i++){
			if(i->second>1 && i->first != '.'){
				cout<<"rep in row\n";
				return false;
			}
		}//end of one row
	}

	//check in each col
	for(int row=0;row<9;row++){
		initializeMap(sudoku_digits);
		
		for(int col=0;col<9;col++){
			sudoku_digits[board[col][row]]++;
		}

		for(auto i=sudoku_digits.begin();i!=sudoku_digits.end();i++){
			if(i->second>1 && i->first != '.'){
				cout<<"rep in col\n";
				return false;
			}
		}//end of one col
	}

	//check in each box
	for(int r=0;r<=6;r+=3){
		cout<<"----\n";
		
		for(int c=0;c<=6;c+=3){
			// int r=row;
			// int c=col
			initializeMap(sudoku_digits);
			cout<<r<<", "<<c<<"\n";
			sudoku_digits[board[r][c]]++;
			sudoku_digits[board[r][c+1]]++;
			sudoku_digits[board[r][c+2]]++;
			sudoku_digits[board[r+1][c]]++;
			sudoku_digits[board[r+1][c+1]]++;
			sudoku_digits[board[r+1][c+2]]++;
			sudoku_digits[board[r+2][c]]++;
			sudoku_digits[board[r+2][c+1]]++;
			sudoku_digits[board[r+2][c+2]]++;
			cout<<r+2<<", "<<c+2<<"\n";

			for(auto i=sudoku_digits.begin();i!=sudoku_digits.end();i++){
			if(i->second>1 && i->first != '.'){
				cout<<i->first<<" ,"<<i->second<<" ";
				cout<<"rep in box\n";
				return false;
			}
		}

		}
		

	}
	return true;
}

int main(){
	vector <vector <char> > v{{'.','4','.','.','.','.','.','.','.'},{'.','.','4','.','.','.','.','.','.'},{'.','.','.','1','.','.','7','.','.'},{'.','.','.','.','.','.','.','.','.'},{'.','.','.','3','.','.','.','6','.'},{'.','.','.','.','.','6','.','9','.'},{'.','.','.','.','1','.','.','.','.'},{'.','.','.','.','.','.','2','.','.'},{'.','.','.','8','.','.','.','.','.'}}
;


	cout<<"size: "<<v.size()<<"\n";
	for(auto i=0;i<9;i++){
		for(auto j=0;j<9;j++){

			if(j==2 || j==5){
				if(v[i][j]=='.')
					cout<<" || ";
				else
					cout<<v[i][j]<<"|| ";	
			}
			else{
				if(v[i][j]=='.')
					cout<<"  | ";
				else
				cout<<v[i][j]<<" | ";
			}
		}

		cout<<"\n";
	}

	cout<<isValidSudoku(v)<<"\n";
	return 0;
}