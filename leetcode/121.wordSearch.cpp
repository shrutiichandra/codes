//g++ wordSearch.cpp -o wordSearch
// https://leetcode.com/problems/word-search/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool existHelper(vector <vector <char> >&b, string& w, int r, int c, int curr_r, int curr_c, int w_len, int start){
	bool res=false;
	char letter=w[start];
	if(b[curr_r][curr_c] != letter){
		return false;
	}

	if(start == w_len-1){
		return true;
	}
	b[curr_r][curr_c]='.';
	if(curr_r>0){
		//go up
		res=existHelper(b,w,r,c,curr_r-1,curr_c,w_len,start+1);
	}

	if(res==false && curr_r < r-1){
		//go down
		res=existHelper(b,w,r,c,curr_r+1,curr_c,w_len,start+1);
	}
	if(res==false && curr_c > 0){
		//go left
		res=existHelper(b,w,r,c,curr_r,curr_c-1,w_len,start+1);
	}
	if(res==false && curr_c < c-1){
		//go right
		res=existHelper(b,w,r,c,curr_r,curr_c+1,w_len,start+1);
	}
	b[curr_r][curr_c]=letter; //backtrack
	return res;
}

bool exist(vector<vector<char>>& board, string word) {
	int rows=board.size();
	int cols=board[0].size();
	int len=word.length();
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(word[0]==board[i][j]){
				if(existHelper(board,word,rows,cols,i,j,len,0)){
					return true;
				}
			}
		}
	}


	return false;        
}

int main(){
	vector <vector <char> > m{{'A','B','C','E'},
								{'S','F','C','S'},
								{'A','D','E','E'}};

	cout<<exist(m,"ABCB")<<"\n";



	return 0;
}