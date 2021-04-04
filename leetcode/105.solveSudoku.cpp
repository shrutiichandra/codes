//g++ solveSudoku.cpp -o solveSudoku
// https://leetcode.com/problems/sudoku-solver/
#include<vector>
#include<iostream>
using namespace std;

vector<int> findBlankCell(vector<vector<char>>& b){
	vector<int> indices;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(b[i][j]=='.'){
				indices.push_back(i);
				indices.push_back(j);
			}
		}
	}
	return indices;
}

bool checkRepInRow(vector<vector<char>>& board, int r,char val){

	for(int i=0;i<9;i++){
		if(board[r][i]==val){
		cout<<"rep in row\n";
				return false;
			}
		}
	return true;

}

bool checkRepInCol(vector<vector<char>>& board, int c, char val){
	for(int i=0;i<9;i++){
		if(board[i][c]==val){
			cout<<"rep in col\n";
				return false;
			}
		}

	return true;
}

bool checkRepInBox(vector<vector<char>>& board, int r, int c, char val){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[r+i][c+j]==val){
				cout<<"rep in box\n";
				return false;
			}
		}
	}
	return true;
}
bool isSafe(vector<vector<char>>& board, int r, int c, char val){
	
	return checkRepInRow(board,r,val) && checkRepInCol(board,c,val) && checkRepInBox(board,r-r%3,c-c%3,val) && (board[r][c]=='.');

}
bool solveSudokuHelper(vector<vector<char>>& board){
		//see if there is a blank cell
	//if not, return
	cout<<"\n---solve sudoku start ---\n";
	vector<int> indices;
	indices=findBlankCell(board);
	if(indices.size()==0){
		cout<<"no blank cell, yay!\n";
		return true;
	}
	int row=indices[0];
	int col=indices[1];
	cout<<"row: "<<row<<" col: "<<col<<" is blank\n";
	
	//for that cell , put values 1 to 9
	for(char num='1';num<='9';num++){
		//check if the location is safe
		cout<<"checking for val: "<<num<<"\n";
		if(isSafe(board,row,col,num)){
			//if it is correct, return

			board[row][col]=num;
			//else backtrack
			if(solveSudokuHelper(board)){
				return true;
			}

			board[row][col]='.';

		}

	}
	
	return false;
}
void solveSudoku(vector<vector<char>>& board) {
	bool ans;
	ans=solveSudokuHelper(board);
	cout<<"ans: "<<ans<<"\n";
	if(ans==false){
		cout<<"no answer\n";
	}

}




int main(){
	vector<vector<char>> v{{'3','.','6','5','.','8','4','.','.'}, 
{'5','2','.','.','.','.','.','.','.'}, 
{'.','8','7','.','.','.','.','3','1'}, 
{'.','.','3','.','1','.','.','8','.'}, 
{'9','.','.','8','6','3','.','.','5'}, 
{'.','5','.','.','9','.','6','.','.'}, 
{'1','3','.','.','.','.','2','5','.'}, 
{'.','.','.','.','.','.','.','7','4'}, 
{'.','.','5','2','.','6','3','.','.'}};
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
	solveSudoku(v);
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

	return 0;
}