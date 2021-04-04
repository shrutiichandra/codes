/* C/C++ program to solve N Queen Problem using 
backtracking */
#include<bits/stdc++.h> 
#define N 4 
using namespace std;
/* A utility function to print solution */
void printSolution(int board[N][N]) 
{ 
	static int k = 1; 
	printf("%d-\n",k++); 
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) 
			printf(" %d ", board[i][j]); 
		printf("\n"); 
	} 
	printf("\n"); 
} 


bool isSafe(int board[N][N], int row, int col) 
{ 
	int i, j; 

	/* Check this row on left side */
	for (i = 0; i < row; i++) 
		if (board[i][col]) 
			return false; 

	/* Check upper diagonal on left side */
	for (i=row, j=col; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 

	/* Check upper diagonal on right side */
	for (i=row, j=col; j<N && i>=0; i--, j++) 
		if (board[i][j]) 
			return false; 

	return true; 
} 

/* A recursive utility function to solve N 
Queen problem */
bool solveNQUtil(int board[N][N], int r) 
{ 
	cout<<"row: "<<r<<" solveNQUtil\n";
	/* base case: If all queens are placed 
	then return true */
	if (r == N) 
	{ 
		printSolution(board); 
		cout<<"returning true\n";
		return true; 
	} 

	/* Consider this column and try placing 
	this queen in all rows one by one */
	bool res = false; 
	for (int i = 0; i < N; i++) 
	{ 
		/* Check if queen can be placed on 
		board[i][col] */
		if ( isSafe(board, r, i) ) 
		{ 
			/* Place this queen in board[i][col] */
			board[r][i] = 1; 

			// Make result true if any placement 
			// is possible 
			cout<<"calling solveNQUtil r: "<<r+1<<"\n";
			res = solveNQUtil(board, r + 1) || res; 
			cout<<"res: after call: "<<res<<"\n";

			/* If placing queen in board[i][col] 
			doesn't lead to a solution, then 
			remove queen from board[i][col] */
			board[r][i] = 0; // BACKTRACK 
		} 
	} 

	/* If queen can not be place in any row in 
		this column col then return false */
	cout<<"returning res: "<<res<<"\n";
	return res; 
} 

void solveNQ() 
{ 
	int board[N][N]; 
	cout<<"memset\n";
	memset(board, 0, sizeof(board)); 
	cout<<"calling solveNQUtil 0\n";
	if (solveNQUtil(board, 0) == false) 
	{ 
		printf("Solution does not eist"); 
		return ; 
	} 

	return ; 
} 

// driver program to test above function 
int main() 
{ 
	solveNQ(); 
	return 0; 
} 
