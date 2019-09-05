//./nqueen  | less
//g++ nqueen.cpp -o nqueen
#include <vector>
#include <string>
#include <iostream>

using namespace std;
void print(vector<vector<string>>& b){
	int sol=0;
	for (auto i: b){
		cout<<"sol# "<<sol++<<"\n";
		for(auto j: i){
			cout<<j<<"\n";
		}
	}
}
void initialize(vector<string>& v,int n){
	for(int i=0;i<n;i++){
		string s;
		for(int j=0;j<n;j++){
			s.append(".");
		}
		v.push_back(s);
	}
}
bool isSafe(vector<string>& board, int r,int c){
	//no other col in the same row should have q
	//cout<<"\n----is safe----\n";
	//cout<<" same col in curr row \n";
	for(int i=0;i<r;i++){
		//cout<<"i: "<<i<<" r: "<<r<<"\n";
		string this_row=board[i];
		//cout<<"this_row in row: "<<this_row<<", ";
		if(this_row.substr(c,1)=="Q"){
			//cout<<"rep in same row\n";
			return false; 
		}
	}
	
	//cout<<" \\ upper diagonal \\ \n";

	//no upper diagonal on left side
	for(int i=r,j=c; i>=0 && j<board.size(); i--,j--){
		//cout<<"i: "<<i<<" j: "<<j<<"\n";

		string this_row=board[i];
		//cout<<"this_row in u.d: "<<this_row<<", ";
		if(this_row.substr(j,1)=="Q"){
			//cout<<"rep in upper diagonal\n";
			return false;
		}

	}
	
	//cout<<" / upper diagonal right / \n";
	//no lower diagonal on left side
	for(int i=r,j=c; i>=0 && j<board.size(); i--,j++){
		//cout<<"i: "<<i<<" j: "<<j<<"\n";

		string this_row=board[i];
		//cout<<"this_row in l.d: "<<this_row<<", ";
		if(this_row.substr(j,1)=="Q"){
			//cout<<"rep in lower diagonal\n";
			return false;
		}

	}
	
	//cout<<"----is safe end----\n";

	return true;
	
}
bool solveNQueensHelper(vector<vector<string>>& v, vector<string>& board,int r){
	bool res=false;
	int board_size=board.size();
	//cout<<"row: "<<r<<" solveNQUtil\n";

	if(r>=board_size){
		//reached end
		//cout<<"yaya reached end\n";
		//push_back this board
		v.push_back(board);
		//cout<<"returning true\n";

		return true;
	}
	
	//for all cols of this row.
	for(int col=0;col<board_size;col++){
		//cout<<"\nchecking safety ----- row: "<<r<<" col: "<<col<<"\n\n";

		//if the cell is safe, place a queen
		if(isSafe(board,r,col)){
		
			//string at this row
			string place_here=board[r];
		
			//place a queen
			place_here[col]='Q';
			board[r]=place_here;
		
			//then move to other row

			res= (solveNQueensHelper(v,board,r+1)) || res;

			//else backtrack
			place_here[col]='.';
			board[r]=place_here;


		}
	}

	return res;
}
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> v;
	vector<string> board;

	initialize(board,n);
	
	
	//start from first row
	if(solveNQueensHelper(v,board,0)){
		return v;
	}
	else{
		 //cout<<"no sol\n";
		return v;
	}
}
int totalNQueens(int n) {
	vector<vector<string>> v;
	v=solveNQueens(n);
	return v.size();

}
int main(){
	vector<vector<string>> v;
	v=solveNQueens(5);
	print(v);
	cout<<totalNQueens(5)<<" solutions\n";
}